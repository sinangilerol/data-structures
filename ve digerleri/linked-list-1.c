#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node* next;
};
int main (void){
struct node* head=NULL;
struct node* second=NULL;
struct node* third =NULL;

head=(struct node*)malloc(sizeof(struct node));
second=(struct node*)malloc(sizeof(struct node));
third=(struct node*)malloc (sizeof(struct node));

head->data=1;
head->next=second;
second->data=2;
second->next=third;
third->data=3;
third->next=NULL;
struct node* cursor; 
cursor=head; // cursore baslangici verdik
while(cursor!=NULL){//cursor null oluncaya kadar:
	printf("%d \n",cursor->data);
	cursor=cursor->next; //cursore siradaki dugumun adresini ata 
}//en son cursore third atandiginda while den cikar.
getch();
return 0;

} 

