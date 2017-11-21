#include<stdio.h>
#include<stdlib.h>
 
struct sNode
{
    int data;
    struct sNode *next;
};
 
struct queue
{
    struct sNode *stack1;
    struct sNode *stack2;
};

void push(struct sNode** top_ref, int new_data)
{
    struct sNode* new_node =(struct sNode*) malloc(sizeof(struct sNode));
	new_node->data = new_data;
	new_node->next = (*top_ref);
	(*top_ref) = new_node;
}
 
int pop(struct sNode** top_ref)
{
    int res;
    struct sNode *top;
     
    
        top = *top_ref;
        res = top->data;
        *top_ref = top->next;
        free(top);
        return res;
         
    
} 
void enQueue(struct queue *q, int x)
{
    push(&q->stack1, x);
}
 
int deQueue(struct queue *q)
{
    int x;
    if(q->stack1 == NULL && q->stack2 == NULL)
    {
        printf("kuyruk bos\n");
        return -1;
    }
 
if(q->stack2 == NULL)
{
    while(q->stack1 != NULL)
    {
        x = pop(&q->stack1);
        push(&q->stack2, x);
         
    }
}
 
x = pop(&q->stack2);
return x;
}
 
 
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    q->stack2 = NULL;
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
     
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
 
getchar();
}

/*
_____________________________________________________________________________________________________________________________________________
Ornek:cift bagli liste ile kuyruga ekleme ve veri cekme islemleri yapalim:																	|
1.adim:1 verisini ekleyelim: stack1= 1, stack2=NULL																							|
2.adim:2 verisini ekleyelim: stack1= 2-1,stack2=NULL																						|
3.adim:3 verisini ekleyelim: stack1= 3-2-1,stack2=NULL																						|	
____________________________________________________________________________________________________________________________________________|
4.adim:cekme islemi yapalim: stack1=NULL,stack2=1-2-3(1 en üstte) ->>> stack2 den pop islemi yapilir: cekilen veri:1,yeni stack2=2-3		|
5.adim:cekme islemi yapalim: stack1=NULL,stack2=2-3 ->>> stack2 den pop islemi yapilir: cekilen veri:2,yeni stack2=3						|
____________________________________________________________________________________________________________________________________________|
6.adim:4 verisini ekleyelim: stack1=4,stack2=3																								|
____________________________________________________________________________________________________________________________________________|
7.adim:cekme islemi yapalim: stack1=NULL,stack2=3-4 ->>> stack2 den pop islemi yapilir: cekilen veri:3,yeni stack2=4						|
8.adim:cekme islemi yapalim: stack1=NULL,stack2=4 ->>> stack2 den pop islemi yapilir: cekilen veri:4,yeni stack2=NULL						|
_____________________________________________________________________________________________________________________________________________



*/






