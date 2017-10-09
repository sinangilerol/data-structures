/*
----------------------HEAD REFERANSI ILE BASA ELEMAN EKLEME----------------------------																
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref,int new_data){
	struct Node* ptr1=(struct Node*)malloc(sizeof(struct Node));
	struct Node* temp=*head_ref;
	ptr1->data=new_data;
	ptr1->next=*head_ref;//yeni eleman ile headi bagladik.yalniz dairesel bagli liste old.dan headi gosteren dugumu,yeni elemani
	// gosterecek sekilde degistirmemiz gerekir:
	if(*head_ref!=NULL){ // listemiz bos degil ise
		while(temp->next!=*head_ref){// nexti headi gosteren elemani bulana kadar git
			temp=temp->next;
		}
		temp->next=ptr1;//nexti head olan dugumu ptr1 i gosterecek sekilde degistirdik
		*head_ref=ptr1;//yeni headi ptr1 yaptik
	
	}else{ // liste bos ise
		ptr1->next=ptr1; //ptr1 yine kendini gosterir
		*head_ref=ptr1;
	}

}
void goster(struct Node* liste){
	struct Node* temp=liste;
	if(liste!=NULL){
		do{	
			printf("%d - ",temp->data);
			temp=temp->next;
		}while(temp!=liste);
		printf("\n");
	}
}

int main(){
	struct Node* head =NULL;
	push(&head,1);
	goster(head);
	push(&head,2);
	goster(head);
	push(&head,3);
	goster(head);
	return 0;
}
