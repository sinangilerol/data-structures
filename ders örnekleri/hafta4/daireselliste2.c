/*
----------------------LAST REFERANSI ILE EKLEME ISLEMLERI----------------------------																
*/
#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* next;
};

void goster(struct Node* liste){
	struct Node* temp=liste;
		do{
			printf("%d - ",temp->data);
			temp=temp->next;
		}while(temp!=liste);
		printf("\n");
	
}
// ------  KOLAY ANLASILMASI ICIN LASTIN NEXTI HEAD DEDIK FAKAT GERCEKTE BOYLE BIR DURUM YOK (SADECE LAST DUGUMUNU TUTUYORUZ)----- 
struct node *addToEmpty(struct Node* last,int new_data){
	if(last!=NULL){ //last bos degilse geriye tekrar lasti gonder	
		return last;
	}
	last=(struct Node*)malloc(sizeof(struct Node));
	last->data=new_data;
	last->next=last; // tek eleman old.dan nexti kendisini tutat
	return last;
}

struct Node *addBegin(struct Node* last,int new_data){
	if(last==NULL){ // last bossa :
		return addToEmpty(last,new_data);
	}
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=new_data;
	temp->next=last->next; // temp lastin nextini yani headi gosterir 
	last->next=temp; // last yeni nextini temp yapar yani tempi head yapar
	return last;
}
struct Node * addEnd(struct Node* last,int new_data){
	if(last==NULL){
	return addToEmpty(last,new_data);	
	}
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=new_data;
	temp->next=last->next; //temp lastin nexti yani headi gosterir
	last->next=temp; // last yeni nextini temp yapar.eger bu hali ile birakirsa temp head olur
	last=temp;// yeni lasti temp yapar
	return last;
	
}
struct Node* addAfter(struct Node* prew,int new_data){
	struct Node* temp=(struct Node*)malloc(sizeof(struct Node));
	temp->data=new_data;
	
	temp->next=prew->next;
	prew->next=temp;
	return temp;
}

int main(){
	struct Node* last=NULL;
	last=addToEmpty(last,5); // bos listeye eleman ekleme
	goster(last->next);
	last=addBegin(last,3); // baslangica ekleme
	goster(last->next);
	last=addBegin(last,1);
	goster(last->next);
	last=addEnd(last,6);// sona ekleme
	goster(last->next);
	last=addAfter(last,2); // last ile lastin nextinin arasina ekledik
	goster(last->next);
	
	
	return 0;
}




