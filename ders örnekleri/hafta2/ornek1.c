#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // mallocu kullanmak icin
struct Node{
	int data;
	struct Node* next; // struct Node tipinden bir pointer tanimladik (ileride tutacagimiz pointerin tipinden)
};
int main(){
	struct Node* head =NULL;
	struct Node* second =NULL;
	struct Node* third =NULL;
		//3 adet struct node tipinden pointer tanimladik
	
	head=(struct Node*) malloc(sizeof(struct Node));
	//    ---1---------        ---------2--------
    second=(struct Node*) malloc(sizeof(struct Node));
	third=(struct Node*) malloc(sizeof(struct Node));
	
	// olusturdugumuz pointerler icin bellekten yer ayirdik
	//1-)malloc fonksiyonun geri donus tipi void oldugundan degisken donusumu yaptik
	//2-)Bellekten ayirdigimiz yerin miktari struct Node kadar
	
	head->	data =1;
	//head bir pointer oldugundan icindeki verilere '.' ile degil, '->' ile ulasiriz
	head->	next=second;
	//dikkat edilirse =&second yerine =second yazdik cunku second zaten pointerdir.
	second->data =2;
	second->next =third;
	third->data =3;
	third->next =NULL;
    getch();
	return 0;
}
