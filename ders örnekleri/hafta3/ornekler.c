#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node* next;
};
////DUGUMUN BASINA EKLER ///////////
void push(struct Node** head_ref,int new_data){// Call by reference yontemi ile cagirdigimiz icin 2 adet '*' var. 
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=(*head_ref);//yeni dugumun nextini,ilk dugumumuze bagladik 
	(*head_ref)=new_node; //elimizde tuttugumuz ilk dugum olan head dugumunude yeni dugumumuz ile guncelledik.(boylece head dugumu hala ilk
	// dugumu gosteriyor.)
	
	/*
	call by reference yontemini kullanmamızın nedeni: push fonksiyonu icinde yaptıgımız degisikliklerin,main fonksiyonu icindede
	gecerli kalmasini saglamaktır.
	
	*/
	
	/*
	push fonksiyonunda yaptigimiz seyler:
	1-)yeni dugum icin bellekten yer ayir
	2-)yeni dugumun nextine ilk dugumu ver 
	3-)yeni dugumu head yap
	!!!!  eger 1 adimindan sonra 2 degilde 3 adimi yapilirsa ne olur ?
	cevap:head listedeki 2. dugumun,2.dugum 3.dugumun..... adresini tuttugu icin yeni dugumu head yaparsak ,onceki head dugumunun gosterdigi 2. dugumu
	dolayisiylada tum listeyi kaybederiz. 
	*/
	
	
}
////DUGUMUN BASINA EKLER ///////////

//---------------------------------------------------//

////////////ARAYA EKLEME YAPAR //////////////
void insertAfter(struct Node* prew_node,int new_data){//prew_node dugumunden sonraki dugume yeni dugumu ekler 
if(prew_node==NULL){ //prew_nodenin NULL olmasi demek,sonda olmasi demektir.Bu yuzden sona ekleme fonksiyonuna yonlendirir ve fonksiyonu bitir.
	append(&prew_node,new_data);
	return;
}
struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
new_node->data=new_data;
new_node->next=prew_node->next;//yeni dugumun nextine prew_nodenin nextini ata.(su anda ikiside aynı dugumu gosteriyor)
prew_node->next=new_node;//prew_nodenin nextine yeni dugumu bagla 
/*
yukaridaki push fonksiyonunda oldugu gibi bu fonk.dada listedeki dugumleri kaybetmemek icin ilk once yeni dugumumuzun nextine prew_node dugumumuzun nextini verdik
ve boylece listedeki dugumleri saglama aldik.Daha sonra ise prew_node dugumumuzun nextini yeni dugume bagladik
*/
}
////////////ARAYA EKLEME YAPAR //////////////

//---------------------------------------------------//

////////DUGUMUN SONUNA EKLEME YAPAR ///////////////
void append (struct Node** head_ref,int new_data){//
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=NULL;//listenin sonuna ekleme yaptigimizdan,yeni dugumun nextini NULL yaptık
	struct Node* last=*head_ref;
	if(*head_ref==NULL){// yani tek elemanli ise
		*head_ref=new_node;//yeni dugumu head'den sonraki yere ekle
	}
	
	while(last->next!=NULL){//dugumun sonuna kadar git
		last=last->next;
	}
	last->next=new_node;//en son ki dugumun nexti yeni elemanı gosterir.
	return;
}
////////DUGUMUN SONUNA EKLEME YAPAR ///////////////

//---------------------------------------------------//

////PARAMETRE OLARAK VERILEN SAYIYI ICEREN DUGUMU SILER//////
void deleteNode(struct Node* head_ref,int key){
	struct Node* temp=head_ref,*prew;//temp headle aynı yeri,prew ise su an bir yeri gostermiyor
	if(temp!=NULL&&temp->data==key){ //temp yani head null degilse ve aradigimiz elemani bulduysak 
		head_ref=temp->next;//head'i headden sonraki dugum yap
		free(temp);//eski head'i sil
		return;
	}
	while(temp!=NULL&&temp->data!=key){//temp null oluncaya veya aradigimiz datayi buluncaya kadar:
		prew=temp; 
		temp=temp->next; 
		/*
		parametre olarak verilen sayiyi iceren dugum,listenin basinda,sonunda veya ortasinda olabilir.eger basinda ise yukaridaki if blogu gerceklesir.eger ortasinda ise 
		silinecek olan dugumun oncesindekinede ihtiyacimiz vardir.cunku dugumu silmeden once,silinecek dugumun oncesindeki dugumu silinecek dugumden sonraki dugume 
		baglamaliyiz ki dugumleri kaybetmeyelim.yukaridaki while dongusundede silinecek dugum bulunmaya calisiliyor ayni zamandada silinecek dugumden onceki dugumude elimizde
		tutmaya calisiyoruz(temp silinecek dugum,prew ise silinecek dugumden onceki dugumu ifade ediyor)
		*/
	}
	if(temp==NULL){//yani aradigimiz datayi bulamadiysak ve listeninde sonuna geldiysek
		return;// geri don
	}
	//yukaridaki if gerceklesmedi ise aradigimiz datayi bulduk demektir.
	prew->next=temp->next; //silinecek dugumden onceki dugumle silinecek dugumden sonraki dugumu birbirine bagladik
	free(temp);// dugumu sildik
	
}
////PARAMETRE OLARAK VERILEN SAYIYI ICEREN DUGUMU SILER//////

//---------------------------------------------------//

////VERILEN POZISYONDAKI DUGUMU SILER//////////
void deleteRotate(struct Node** head_ref,int position){
	if(*head_ref==NULL){
		return ;
	}
	struct Node* temp=*head_ref;//temp head ile aynı yeri gosteriyor
	
	if(position==0){//position sıfırsa head dügümünü silmek istiyoruz demektir
		*head_ref=temp->next;//headi,headden sonraki dugum yaptik
		free(temp);//eski headi sildik
		return ;
	}
	int i;
	for(i=0;temp!=NULL&&i<position-1;i++){//listenin sonuna gelinceye kadar veya aranan pozisyonun bir eksigine kadar ilerle
		temp=temp->next;
	}
	if(temp==NULL||temp->next==NULL){//sona geldi ise geri don
		return;
	}
	/*
	eger sona gelmediysek silinmek istenen dugumden bir onceki dugume geldik demektir.
	burada dikkat edilecek yer:bir dugumu sildigimizde,silinen dugumunden oceki dugum ile silinen dugumden sonraki dugumu birbirine baglamaktir.
	su anda temp: silinecek dugumden onceki dugumu gosteriyor.istenen dugumu silebilmek icin geriye kalan tek eksigimiz silinecek dugumden sonraki dugum.
	onu da asagidaki next_node de tutuyoruz
	*/
	struct Node* next_node=temp->next->next;
	free(temp->next); //silinecek dugum silinir
	temp->next=next_node;//silinen dugumden onceki dugum ile sonraki dugum birbirine baglanir.
}
////VERILEN POZISYONDAKI DUGUMU SILER//////////

//---------------------------------------------------//

//////LISTEDEKI DUGUM SAYISI BULUNUR//////////////////
int getCount(struct Node* liste){//parametre olarak headi verdik
	int count=0; // dugum sayimizi count degiskeninde tutuyoruz
	while(liste!=NULL){//listenin sonuna gelinceye kadar
		count++;//dugum sayisini arttir
		liste=liste->next;//sonraki dugume gec
	}
	return count;//dugumun sonuna gelince,dugum sayisini gonder
}
//////LISTEDEKI DUGUM SAYISI BULUNUR//////////////////

//---------------------------------------------------//

//////LISTEDEKI DUGUMLER GOSTERILIR /////////////////
void goster(struct Node* liste){// parametre olarak headi verdik 
	while(liste!=NULL){//listenin sonuna gelinceye kadar
		printf("%d-",liste->data);// o an bulundugun dugumu goster
		liste=liste->next; //sonraki dugume gec
	}
	printf("\n");//gosterme islemleri bittiginde bir alta gec
}
//////LISTEDEKI DUGUMLER GOSTERILIR /////////////////

int main(){
	struct Node* head=NULL;
	head=(struct Node*)malloc(sizeof(struct Node));
	head->data=1;
	head->next=NULL;
	goster(head);//listedeki dugumler gosterilir
	push(&head,2);//listenin basina ekleme yapilir
	goster(head);
	int i;
	for(i=3;i<9;i++){ // listenin basina dugumler eklenir
		push(&head,i);
		goster(head);
	}
	insertAfter(head->next->next,30);//araya ekleme yapilir
	goster(head);

	append(&head,66);// listenin sonuna ekleme yapilir
	goster(head);
	deleteNode(head,6);//listedeki 6 sayisi silinir.
	goster(head);
	printf(" boyutu : %d\n",getCount(head));// listedeki dugum sayisi bulunur
	deleteRotate(&head,3);// listenin 3. sirasindaki dugum silinir
	goster(head);
	
		
}
