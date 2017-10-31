#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Stack
{
	int top;
	unsigned capacity;
	int* array;
};

struct Stack* createStack( unsigned capacity )
{
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) // bellekte yer yoksa  
		return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	if (!stack->array)
		return NULL;
	return stack;
}
int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}
// stackin en ustunde olan elemani dondurur.ama pop islemi gibi elemanin yerini bosaltmaz..
char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
}
void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

//gonderilen char karakteri operand ise 1 dondurur.
int isOperand(char ch)
{
	return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

//operatorlerin islem onceligine gore sayilar dondurur.(islem onceligi arttikca dondurulen sayinin buyuklugu artar)
int Prec(char ch)
{
	switch (ch)
	{
	case '+':
	case '-':
		return 1;

	case '*':
	case '/':
		return 2;

	case '^':
		return 3;
	}
	return -1;
}

/*
infix bir ifade 4 seyi icerir:operand(a,b,c,...1,2,3...),operator(+,-,*,/,^),'(' ve ')' .infix ifade postfixe cevrilirken ana mantik sudur:
	infix ifade iceren dizinin tum elemanlari kontrol edilir(bir for dongusu).infix ifadede 4 sey olabilir demistik.O zaman her elemani bu 4 seye gore kontrol 
	edecegiz demektir.
	1-)eger eleman operand ise: bulundugu dizide kalmaya devam eder ama yeri degisir.
	2-)eger operator ise:eger kendisinden once stacka alinan operatorun islemonceligi daha buyukse,onun ustune eklenir.eger kucuk ve esitse,kendisinden onceki 
	operator diziye aktarilir,kendiside stacka eklenir.
	3-) '(' ise stacka eklenir 
	4-) ')' ise stackdaki elemanlar sirasi ile diziye bosaltilir taki '(' gorulene kadar. stackin en ustundeki eleman '(' oldugunda,'(' stacktan atilir ama diziye eklenmez
	her eleman icin bu 4 kosuldan birisi isletilir ve soncunda postfix bir ifade olusur.
	
*/

int infixToPostfix(char* exp)
{
	int i, k;

	struct Stack* stack = createStack(strlen(exp)); // strlen fonksiyonu parametre olarak verilen char dizisinin boyutunu dondurur
	
	for (i = 0, k = -1; exp[i]; i++) { // exp dizisinin eleman sayisi kadar donguyu tekrarla:
		if (isOperand(exp[i])){//eger i. indisdeki eleman operand ise dizide kalir(alttaki ornekte bu kisim daha net anlasilacaktir)
			exp[++k] = exp[i];
		}
		
		else if (exp[i] == '('){// ( var ise stacka eklenir 
				push(stack, exp[i]);
		}
		else if (exp[i] == ')'){
			while (!isEmpty(stack) && peek(stack) != '('){//ilk adimda ( gorulene kadar olan operatorler sirasi ile diziye eklenir
				exp[++k] = pop(stack);
			}
				
			if (!isEmpty(stack) && peek(stack) != '('){// normalde stack bos olmasi ve stackin en ustunde ( olmasi gerekir.eger bunlar gerceklesmedi ise hata vardir.
				return -1; // islem sonlandirilir
			}
			else // stackin en ustunde kalan ( stacktan atilir
				pop(stack);
		}
		
		else /* son olarak eger eleman bir operator ise 2 durum var:
		 i-)eger eleman, stackin en ustundeki operatorden daha oncelikli bir operator ise stacka eklenir
		 ii-)eger eleman, stackin en ustundeki elemanla ayni oncelige veya daha az oncelige sahipse,stackdaki operatorlerden kendisinden daha buyuk oncelige sahip
		 olan operatorlere (eger boyle bir operator yoksa stackin sonuna kadar) kadar olan kisim sirasi ile diziye eklenir. 
		 */
		{
			while (!isEmpty(stack) && Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}
	while (!isEmpty(stack)) //dizideki tum elemanlar kontrol edildikten sonra,stackta kalan operatorler diziye eklenir.
		exp[++k] = pop(stack );

	exp[++k] = '\0'; //karakter dizimizin sonlandigini belirttik. (bkz. null terminated)
	printf( "%s\n", exp ); //dizimizi gosterdik
}
/*
    ORNEK: a*(b+c)/d-e infix ifadesini postfixe cevirelim
    1.ADIM: a : dizinin 0. indisine alinir. dizi:a*(b+c)/d-e  stack:
	2.ADIM: * : stacka eklenir.             dizi:a*(b+c)/d-e  stack:*
	3.ADIM: ( : stacka eklenir.             dizi:a*(b+c)/d-e  stack:*,(
	4.ADIM: b : dizinin 1.indisine alinir.  dizi:ab(b+c)/d-e  stack:*,(
	5.ADIM: + : '(' den onceligi buyuk oldugundan stacka eklenir: 	dizi:ab(b+c)/d-e  stack:*,(,+
	6.ADIM: c :dizinin 2. indisine alinir.  dizi:abcb+c)/d-e  stack:*,(,+
	7.ADIM: ) : ( e gelene kadarki operatorler diziye alinir,( silinir 	dizi:abc++c)/d-e  stack:*
	8.ADIM: / : * ile onceligi ayni oldugundan * diziye alinir, / stacka atilir:  dizi:abc+*c)/d-e  stack:/
	9.ADIM: d : diziye alinir  dizi:abc+*d)/d-e  stack:/
   10.ADIM: - : / dan onceligi kucuk oldugundan / diziye,- stacka alinir  dizi:abc+*d//d-e   stack:-
   11.ADIM: e : diziye alinir  dizi:abc+*d/ed-e
   12.ADIM: dizi elemanlari bittiginden stackdaki operatorler diziye alinir: dizi:abc+*d/e--e
   13.ADIM: son eklenen operatorden sonra \0 ile dizinin bittigi belirtilir. dizi:abc+*d/e-
   boylece postfix islemi bitirilir
*/

int main()
{
	char exp[] = "a*(b+c)/d-e";
	infixToPostfix(exp);
	return 0;
}


