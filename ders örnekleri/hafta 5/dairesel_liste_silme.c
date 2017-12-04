/*
DAIRESEL BAGLI LISTEDE PARAMETRE OLARAK VERILEN DATAYI ICEREN DUGUMU SILER
*/
#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* next;
};
//basa eleman ekleme fonksiyonu
void push(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	if(*head_ref==NULL){//ekledigim dugum ilk dugum ise:
		new_node->next=new_node;//nexti kendisini gostersin
		*head_ref=new_node;
		return;
	}
	//eger ilk eleman degilse, nexti head olan dugume yani son dugume kadar gitmeli ve son dugumun nextini yeni dugum yapmaliyiz 
	struct Node* temp=*head_ref;
	while(temp->next!=*head_ref){
		temp=temp->next;
	}
	temp->next=new_node;//son dugumun nextini yeni dugum olarak degistir 
	new_node->next=*head_ref;//yeni dugumun nexti headi gostersin
	*head_ref=new_node;// ve headi yeni dugum olarak degistir
}
//dugumleri gosterme fonksiyonu
void goster(struct Node* liste){
	struct Node* temp=liste;
	do{
		printf("%d - ",temp->data);
		temp=temp->next;
	}while(temp!=liste);
	printf("\n");
}
// parametre olarak verilen datayi iceren dugumu silen fonksiyon:
void deleteNode(struct Node** head_ref,int key){
	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	 // silme isleminde ilk dugumun etkilenme olasiligi oldugundan, call by reference yontemini kullaniriz.
	  //cunku headin adresi degisebilir ve bunuda ya geriye yeni dugum dondurerek yada geriye dugumun adresini dondurerek(call by reference)
	   //yapabiliriz. [KISACA SOYLEMEK GEREKIRSE EVET geeksforgeeks deki ornekde yanlis :) ]
	    //yanlis ornek icin bakiniz:http://www.geeksforgeeks.org/deletion-circular-linked-list/  :) 
	if(*head_ref==NULL){// liste bossa geriye don
		return;
	}
	struct Node* current=*head_ref,*prew;
	//dugumleri tek tek gezip datayi ara:
	while(current->data!=key){ // datayi bulmadigin surece devam et 
		if(current->next==*head_ref){ // eger datayi bulamadiysan ve tekrar basa geldiysen,aradigin data listede yok demektir.
			printf("bulamadim\n");
		return ; // geriye don
		}
		// dugumun sonuna gelmediysen ve datayida bulmadiysan :
		prew=current; // prewde bir onceki pozisyonu tutuyoruz(eger ileriki adimlarda current aranan dataya esit olursa,silme islemi icin 
		//currenti gosteren bir dugume ihtiyacimiz var.Bu islevide prew yerine getirir.
		current=current->next;	//ileriiiii !!
	}
	//eger aradigin datayi bulduysan:
	//(3 adet durum vardir.Bunlar aradigin datanin basta,sonda veya aralarda bir yerlerde oldugudur.Her durum icin bir if -else if-else blogu actik )
	if(current==*head_ref){//aradigin data basta ise
		prew=*head_ref;//prew normalde silinecek dugumden onceki dugumu tutyordu fakat,silinecek dugum basta ise while dongusu 
		//hic isletilmez ve bu bloga gelir.
		while(prew->next!=*head_ref){//silinecek dugumu son dugum gosterdiginden son dugume gidilir
			prew=prew->next; // ileriiiiii
		}
		*head_ref=current->next;//head dugumunu,2. dugum yaptik
		prew->next=*head_ref;//son dugum yeni head oldu
		free(current);//eski ilk dugumu sil
	}
	else if(current->next==*head_ref){//aradigin sonda ise
		
		prew->next=*head_ref;//silinecek dugumu gosteren dugumun nextini ilk dugum yap
		free(current);//sondaki dugumu sil
	}
	else{//eger aralarda ise
		prew->next=current->next;//silinecek dugumden onceki dugum,silinecek dugumden sonraki dugumu gostersin
		free(current);//2 sinin arasindaki dugum yani silinecek dugumude sil..
	}
}

int main(){
	struct Node* head=NULL;
	push(&head,9);
	push(&head,8);
	push(&head,7);
	push(&head,6);
	push(&head,5);
	push(&head,4);
	push(&head,3);
	push(&head,2);
	push(&head,1);
	goster(head);
	deleteNode(&head,4);
	goster(head);
	return 0;
}
