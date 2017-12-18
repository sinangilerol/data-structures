#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=(*head_ref);
	(*head_ref)=new_node;	
}

int f(struct Node* n){ //b.li liste sirali kucukten buyuge siralanmis ise 1, degilse 0 dondurur.
	return (n==NULL || n->next==NULL || ( (n->data <= n->next->data) && f(n->next) ));
}

int main(){
	struct Node* head=NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	head=NULL;
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	printf("%d ",f(head));
	return 0;
}
