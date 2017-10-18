#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
	struct Node* prev;
};
//basa ekleme fonksiyonu
void push(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->prev=NULL;
	if(*head_ref==NULL){
		new_node->next=NULL;
		*head_ref=new_node;
		return;
	}
	new_node->next=*head_ref;
	(*head_ref)->prev=new_node;
	*head_ref=new_node;
}
//sona ekleme fonksiyonu
void append(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=NULL;
	if(*head_ref==NULL){
		new_node->prev=NULL;
		*head_ref=new_node;
		return;
	}
	
	struct Node* temp=*head_ref;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
	new_node->prev=temp;
}
void goster(struct Node* liste){
	while(liste!=NULL){
		printf("%d - ",liste->data);
		liste=liste->next;
	}
	printf("\n");
}
void reverse(struct Node** head_ref){
	struct Node* headtemp=NULL;
	struct Node* temp=*head_ref;
	//tempin yani head_refin sonuna kadar git
	while(temp->next!=NULL){
		
		temp=temp->next;
	}
	/*
	alt kisimdaki mantik sudur: yukarida tanimladigimiz headtemp isimli listeye ,sira ile tempdeki datalari ekliyoruz(ilk durumda temp son dugumu gosterir)
	ve temp=temp->prev diyerek bir onceki dugume geciyoruz (ilk dugume gelene kadar).boylece reverse islemini gerceklestirmis oluyoruz.Burada dikkat edilmesi 
	gereken yerlerden biriside ekleme islemini dugumun sonuna yapiyor olusumusdur.
	*/
	do{
		append(&headtemp,temp->data);//sona ekledik
		temp=temp->prev;
	}while(temp!=NULL);
	*head_ref=headtemp;//head_refi headtemp ile degistirdik
}
int main(){
	struct Node* head=NULL;
	push(&head,4); push(&head,3); push(&head,2); push(&head,1);	
	goster(head);
	reverse(&head);
	goster(head);
	return 0;
	
}
