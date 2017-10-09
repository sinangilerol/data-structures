#include <stdio.h>
#include <stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
void push(struct Node** head_ref,int new_data){ // dugumun basina ekleme fonksiyonu
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
	
}
void reverse(struct Node** head_ref){ // 2 adet '*' old.dan bu fonk.da yaptigimiz degisiklikler main 
//fonks.dada gecerli olur(cunku ** head_ref,main fonk.undaki head'in adresini tutar[bkz call by reference])
	/*
	parametre olarak verilen listenin elemanlarini terse cevirir. 
	Or: listemiz 1-2-3-4 ise, bu fonksiyona parametre olarak verildiðinde:
	4-3-2-1 halini alir
	*/
	struct Node* prew=NULL;
	struct Node* current=*head_ref;
	struct Node* next;
	
	while(current!=NULL){// A
		next=current->next;// B
		current->next=prew;// C
		prew=current;// D
		current = next;// E
		
		/*
		while döngüsünü adim adim takip edelim:
		______________________________________________________________________________________________________________________________
		1.ADIM:
		A-)currenti dongunun ustunde *head_ref yaptigimizdan kontrolden gecti
		B-)next isimli gecici degiskenimizde currentin nextini tuttuk yani next: 2->3->4->NULL þeklinde diyebiliriz
		C-)current headi tuttugundan (yani 1 i tuttugundan) ve prew dede su anda NULL old.dan current su hale gelebilir diyebiliriz:
		1->NULL [dikkat edilirse 1 den sonra NULL geldiginden sonraki dugumleri kaybettik. eger B diye bir islemimiz olmasaydi dugumumuzu
		 kaybedecektik {zaten E islemimizde currente tekrar dugumleri bagliyoruz} ]
		D-)prew'e currenti atadik yani prew :1->NULL oldu diyebiliriz.
		E-)C isleminde kaybettigimiz dugumleri tekrar currente bagladik ve current:2->3->4->NULL halini aldi (yalniz bagladigimiz dugum
		programin basindaki dugum degildir.Su anda nextte 2->3->4->NULL var fakat prog. basinda dugumumuz 1 den basliyordu.Ama prew'e 
		baktigimizda ise baslangicta sadece NULL iceriyorken simdi 1->NULL iceriyor.Zaten dongunun yaptigi islemde bu.Currentten head 
		dugumunu koparip,prewde head yapmak.currentin tum elemanlarini koparip bir tek NULL kaldigindada current A sartina takilacak 
		ve donguden cikacaktir. ) 
		______________________________________________________________________________________________________________________________
		2.ADIM:
		A-)current 2->3->4->NULL old.dan kontrolden gecer 
		B-)next:3->4->NULL tutulur
		C-)current headi tutar.headde 2 old.dan ve prew 1->NULL old.dan current su hali alir:2->1->NULL
		D-)prew:2->1->NULL olur
		E-)current:3->4->NULL olur
		______________________________________________________________________________________________________________________________
		3.ADIM:
		A-)currentin headi 3 old.dan kontrolden gecer
		B-)next:4->NULL
		C-)current:3->2->1->NULL
		D-)prew:3->2->1->NULL
		E-)current:4->NULL
		______________________________________________________________________________________________________________________________
		4.ADIM:
		A-)currentin headi 4 old.dan takilmaz
		B-)next:NULL
		C-)current:4->3->2->1->NULL
		D-)prew:4->3->2->1->NULL
		E-)current:NULL
		______________________________________________________________________________________________________________________________
		5.ADIM:
		A-)currentin headi NULL kontrolden gecemez ve donguden cikar.
		______________________________________________________________________________________________________________________________
		DONGUNUN DISI:
		yeni head_ref prew oldu ve dugumlerimizi terse cevirmis olduk
		*/
	}
	*head_ref=prew;
}
void goster(struct Node* liste){
	while(liste!=NULL){
		printf("%d - ",liste->data);
		liste=liste->next;
	}
	printf("\n");
}
int main(){
	struct Node* head=(struct Node*)malloc(sizeof(struct Node));
	head=NULL;
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	goster(head);
	reverse(&head);
	goster(head);
	return 0;
}
