/*
CIFT BAGLI LISTE ile ilgili KARISIK ORNEKLER:
*/
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next;
	struct Node *prev; //cift bagli listede onceki dugumude tutacagimizdan prev isimli bir Node pointeri tanýmladik
};
//basa dugum ekleme
void push(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	new_node->prev=NULL;// basa eklendigi icin onceki dugumu gosteren prev null olacaktir
	if(*head_ref!=NULL){//eger ilk eleman degilse
	(*head_ref)->prev=new_node;//degisecek olan headin previ yeni dugumu (yeni headi)gosterir
	}
	*head_ref=new_node;//yeni dugumu head yap.
}
//araya dugum ekleme
void insertAfter(struct Node* prev,int new_data){
	//paramatre olarak verilen dugumden sonra ekle:
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->prev=prev;//yeni dugumun previ ,parametre olarak verilen dugum
	new_node->next=prev->next;//yeni dugumun nexti,parametre olarak verilen dugumun nexti olsun
	prev->next->prev=new_node;//prametre olarak verilen dugumun nextinin previ yeni dugum olsun
	prev->next=new_node;//parametre olarak verilen dugumun nexti yeni dugum olsun
}
//sona ekleme
void append(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=NULL;//sona eklendigi icin nexti null olacaktir
	struct Node* last=*head_ref;
	if(*head_ref==NULL){//eger hic dugum yoksa:
		new_node->prev=NULL;//yeni dugumun previni null yap(cunku baska eleman yok).
		*head_ref=new_node;//yeni dugumu head yap
		return;//geriye don
	}
	while(last->next!=NULL){//sona ekleme yapildigi ve referans olarak ilk dugum verildiginden son dugume git:
		last=last->next;
	}
	last->next=new_node;//son dugumun nexti yeni dugum,
	new_node->prev=last;//yeni dugumun previ eski son dugum olsun.
	
}
//parametre olarak head ve silinecek dugum verilir.
void deleteNode(struct Node** head_ref,struct Node* del){
	if(*head_ref==NULL || del==NULL){//eger head veya silinecek dugum NULLsa geri don
		return ;
	} 
	
	
	
	if(*head_ref==del){//eger silinecek dugum ilk dugum ise:
		*head_ref=del->next; //yeni headi,headin nexti yani 2. dugum yap.
		//!! silme islemleri en son yapilmaktadir.
	}
	if(del->next!=NULL){//eger silinecek dugum sonda degilse
		del->next->prev=del->prev;//silinecek dugumden sonraki dugumun previ,silinecek dugumden onceki dugumu gostersin
	}
	if(del->prev!=NULL){//eger silinecek dugumun previ null degilse 
		del->prev->next=del->next;//silinecek dugumden onceki dugum,silinecek dugumden sonraki dugumu gostersin
	}
	//next ve prevler degistikten sonra silinecek dugumu sil..
	free(del);
	//!!!!!:dikkat edilirse bazi kosullarda 2,bazilarinda 1 adet if bloguna girilir.ornegin ilk dugum silinmek istenirse:1. ve 2. if bloguna girer
	//zaten ilk dugum silinirse 2 islem yapmamiz gerekir.bunlar:ilk dugumu 2. dugum yapmak ve 2.dugumun previni null yapmaktir
	//ornegin son dugum silinmek istenirse:sadece 3. if bloguna girer.zaten son dugum silindiginde tek islem yapilir:son dugumden oncki dugumun nextini null yapmak
	//eger aradan silmek istenirse 2. ve 3. if bloguna girer.aradan silem islemindede 2 islem vardir:onceki dugumun nexti sonraki,sonraki dugum previ oncekini gosterir
	
}
//dugumlerin sirasini degistirme:(son dugum ilk,sondan bir oncki 2.,.......ilk dugum son dugum olur)
void reverse(struct Node** head_ref){
	struct Node* temp=NULL;
	struct Node* current=*head_ref;
	while(current!=NULL){ // reverse iþlemleri:currenttekileri tersten preve tasidik
		temp=current->prev;
		current->prev=current->next;
		current->next=temp;
		current=current->prev;
	}
	
	if(temp!=NULL){ //yeni headi tempin previ yap
		*head_ref=temp->prev;
	}
}
//elemanlari gosterme fonksiyonu
void goster(struct Node* liste){
	while(liste!=NULL){
		printf("%d - ",liste->data);
		liste=liste->next;
	}
	printf("\n");
}

int main(){
	struct Node* head=NULL;
	push(&head,4); push(&head,3); push(&head,2); push(&head,1);
	goster(head);
	insertAfter(head->next,77);
	goster(head);
	append(&head,99);
	goster(head);
	deleteNode(&head,head);
	goster(head);
	reverse(&head);
	goster(head);
	return 0;
}
