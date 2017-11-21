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
    int x,res;
    if(q->stack1==NULL)
    	return;
    else if(q->stack1->next==NULL)
		return pop(&q->stack1);
	else{
		x=pop(&q->stack1);
		res=deQueue(q);
		push(&q->stack1,x);
		return res;
	}		
}
 
 
int main()
{
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));
    q->stack1 = NULL;
    
    enQueue(q, 1);
    enQueue(q, 2);
    enQueue(q, 3);
     
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
    printf("%d ", deQueue(q));
 
getchar();
}
