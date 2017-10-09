#include <stdio.h>
#include <stdlib.h>
/*
parametre olarak verilen 2 listedki elemanlarý kucukten buyuge siralar
or:   a=2-5-7
	  b=1-3-9
siralanmis hali :1-2-3-5-7-9	  
*/
struct Node{
	int data;
	struct Node* next;
};

void push(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
	
}

struct Node* sortedMerge(struct Node* a,struct Node* b){
	struct Node d; // !! pointer tipinde degil !!
	struct Node* tail =&d;// pointer tipinde olan taile pointer tipinde olmayan d yi atamak icin d nin adresini taile verdik
	d.next=NULL;// pointer olmadigi icin '.' ile erisilir
	/*
	tailde yaptigimiz tum degisiklikler d de gerceklesir.
	programin genel algoritmasi su sekilde:
	a ve b yi kiyasla, kucuk olani (&(tail->next),&x) parametresi ile MoveNode fonk.una gonder
	MoveNode fonk.unda x listesinin kucuk olan elemanini kopar ve tail listesine ata
	...
	bu islemler bittiginde a ve b listelerinden birisi NULL olacaktir.Yani elemanlari bitecektir.
	Bu durumda bizde tail listesine bitmeyen a veya b listesini ekleyerek fonksiyonu bitiririz. 
	*/
	while(1){
		if(a==NULL){ // a nin sonuna gelmissek  
			tail->next=b;// bitmeyen b listesini tailin nextine ekle 
			break;
		}else if(b==NULL){ 
			tail->next=a;
			break;
		}
		
		if(a->data <=b->data){ // kucuk olan elemani tail ile birlikte MoveNodeye gonderdik
			MoveNode(&(tail->next),&a);
		}else{
			MoveNode(&(tail->next),&b);
		}
		tail=tail->next; // taili herseferinde bir ileri gotur
	}
	return d.next ; //tum islemler bittiginde yani siralama islemi bittiginde tailin isaret etmis oldugu d yi geri gonder
}
void MoveNode(struct Node** destRef,struct Node** sourceRef){
	struct Node* new_node=*sourceRef; //new_nodeye elemai silinecek listeyi atadik
	*sourceRef=new_node->next; //elemani silinecek listede silme islemi yapildi (ilk dugumu yani en kucuk elemani kaybettik)
	new_node->next=*destRef; // en kucuk olarak ekledigimiz elemani eski enkucuk elemana bagladik
	*destRef=new_node; //en kucuk eleman olarak atadik
	
}
void goster(struct Node* liste){
	while(liste!=NULL){
		printf("%d - ",liste->data);
		liste=liste->next;
	}
	printf("\n");
}
int main(){
struct Node* res =NULL;
struct Node* a =NULL;
struct Node* b =NULL;
	push(&a,15);push(&a,10);push(&a,5);
	// a listesi 5-10-15 oldu
	goster(a);
	push(&b,20);push(&b,3);push(&b,2);
	// b listesi 2-3-20 oldu
	goster(b);
	res=sortedMerge(a,b);
	// siralamak icin sortedMerge fonksiyonuna a ve b listelerimizi gonderdik
	goster(res);
	return 0;
}
