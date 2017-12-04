#include <stdio.h>
#include <string.h>
#include <ctype.h>
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

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;
	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	if (!stack->array) return NULL;

	return stack;
}

int isEmpty(struct Stack* stack)
{
	return stack->top == -1 ;
}

char peek(struct Stack* stack)
{
	return stack->array[stack->top];
}

char pop(struct Stack* stack)
{
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}

void push(struct Stack* stack, char op)
{
	stack->array[++stack->top] = op;
}

//postfix ifadenin sonucunu bulur
int evaluatePostfix(char* exp)
{
	//ana mantik su sekildedir:postfix ifade bastan sona okunur,sayi ise stacka,degilse stacktaki son 2 sayi arasinda okunan operatore gore islem yapilir.
	//<NOT> yalniz dikkat edilmesi gereken nokta islem yapilirken (stackin en ustundeki eleman q,q nun bir altindaki eleman w olsun) w 'operator' q seklinde olmalidir.
	//sebebini ornekle aciklayalim. q-w infix ifadesinin postfix karsiligi qw- dir. eger postfix ifadenin sonucunu bulurken w-q dersek hata yapmis oluruz. </NOT>
	//islem yapildiktan sonra,islemin sonucu tekrar stacka atilir.
	//postfix ifadenin sonuna gelenindiginde stackta sadece islemin sonucu kalir.geriyede sonuc dondurulur ve hesaplama islemi biter.   
	struct Stack* stack = createStack(strlen(exp));
	int i;


	for (i = 0; exp[i]; i++)
	{
		if (isdigit(exp[i])) //ctype kutuphanesinde bulunur.
			push(stack, exp[i] - '0'); // ascii karakterlerinde 0->48,1->49,..... 9->57 ye karsilik gelir.char tipindeki bir rakam  48 ile 57 arasinda rakamlar 
			// alabieceginden,karakteri inte cevirmek icin etkisiz eleman olan 0 in karsiligi olan 48 den cikaririz.Ornek: 3->51 ,'3'-'0' = 51-48=3
			//not:bu cevirme islemi sadece tek rakamli sayilar icin gecerlidir
		else
		{
			int val1 = pop(stack);
			int val2 = pop(stack);
			switch (exp[i])
			{
			case '+': push(stack, val2 + val1); break;
			case '-': push(stack, val2 - val1); break;
			case '*': push(stack, val2 * val1); break;
			case '/': push(stack, val2/val1); break;
			}
		}
	}
	return pop(stack);
}

int main()
{
	char exp[] = "231*+9-";
	printf ("Postfix ifade : %s \ndegeri= %d", exp, evaluatePostfix(exp));
	return 0;
}

