/*
LISTEYI, CEVRIMSEL LISTEYE CEVIRIR
*/

#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
//liste icin basa dugum ekleme fonksiyonu :
void push(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	if(*head_ref==NULL){
		new_node->next=NULL;
		*head_ref=new_node;
		return ;
	}
	new_node->next=*head_ref;
	*head_ref=new_node;
}
//parametre olarak gonderilen listeyi,bagli liste yapip geriye dondurur
struct Node* circular(struct Node* head){
	struct Node* start=head;
	while(start->next!=NULL){ // listenin sonuna kadar git
		start=start->next;
	}
	//sona geldiginde ise,sondaki dugumun nextini ilk dugum yap (ki boylece bagli liste elde etmis olalim)
	start->next=head;
	return head;// geriye parametre olarak gonderilen dugumu gonder
}
//dairesel bagli liste icin gosterme fonksiyonu:
void goster(struct Node* head){
	struct Node* temp=head;
	do{
		printf("%d - ",temp->data);
		temp=temp->next;
	}while(temp!=head);
	printf("\n");
}
int main(){
	struct Node* head=NULL;
	push(&head,3);
	push(&head,2);
	push(&head,1);	
	head=circular(head);
	goster(head);
	return 0;
}
