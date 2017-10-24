#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack
{
	int top; // icinde kac tane veri oldugunu tutat
	int capacity; //kapasiteti tutat
	int* array; // gelen verileri tutar(ilk taimlandiginda boyutu belli olmadigindan pointer tipinde tanimladik
	//boyutu belli oldugunda,boyutu kadar yer ayiracagiz 
};

struct Stack* createStack(int capacity){// stack ilk olusturuldugunda boyutuna gore yer ayiran fonksiyon.
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));
	stack->capacity = capacity;// eklenebilecek max. veri sayisi
	stack->top = -1;// ici ilk  basta bos oldugundan -1 dir(altsatirlarda gorulecegi gibi diziye eleman eklenirken dizinin indisi buradan cekilir.o yuzden 
	// ilk veri eklendiginde degeri sifir olur[dizinin indisleride 0 dan baslar])
	stack->array = (int*) malloc(stack->capacity * sizeof(int));// eklenecek verilerin tutuldugu dizinin max. boyutu=int tipinin boyutu x eklenebilecek max. veri sayisi
	return stack;
}

int isFull(struct Stack* stack){ 
	return stack->top == stack->capacity - 1; // top capacity-1 e esitse geriye 1,degilse 0 dondurulur 
}

int isEmpty(struct Stack* stack){ 
	return stack->top == -1;  // top -1 e esitse 1,degilse 0 dondurulur
	}

void push(struct Stack* stack, int item){ // ekleme islemi yapilir
	if (isFull(stack)){//eger doluysa isFull fonk.u geriye 1 degeri dondurur.if(1) durumunda ise if blogunun ici calisir (ekleme yapmadan geri doner) 
		return; }
	stack->array[++stack->top] = item; //++stack->top: ilkonce stack->top un degerini artir sonra atama islemini yap demektir(ornegin ilk elemanin eklenecegi 
	// dusunulerse ilk once top un degeri -1 den 0 yapilir sonra ise array[0] a item degeri atanir
	
}

int pop(struct Stack* stack){ // veri cekme islemi yapilir
	if (isEmpty(stack)){//eger bossa isEmpty fonk.u geriye 1 degeri dondurur. if(1) durumunda ise if blogunun ici calisir (geriye -1 degerini dondurur)
		return -1; }
	return stack->array[stack->top--]; //stack->top--:ilk once atama islemi yapilir,sonra top un degeri 1 azaltilir(boylece bir dahaki seferde,su an gonderdigimiz
	// veriden bir onceki veriyi dondururuz
}

int main()
{
	struct Stack* stack = createStack(10);
	push(stack, 10);//top=0
	push(stack, 20);//top=1
	push(stack, 30);//top=2
	printf("%d\n", pop(stack));//top=1 (veriyi cektikten sonra)
	printf("%d\n",pop(stack));//top=0 (veriyi cektikten sonra) 
	printf("%d\n",pop(stack));//top=-1 (veriyi cektikten sonra)
	printf("%d\n",pop(stack));	//burada pop fonk.unun if blogu calisir.Cunku su an top -1 e esittir
	return 0;
}

