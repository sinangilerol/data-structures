#include <stdio.h>
#include <conio.h>
/*   

D�Z�DEK� ELEMANLARI 1 KERE SA�A D�ND�R�R


*/
void rotate(int dizi[],int n){ // 1 kere sa�a d�nd�ren fonksiyon
	int temp=dizi[n-1]; // en sa�daki eleman� saklad�k
	for(int i=n-1;i>0;i--){
		dizi[i]=dizi[i-1]; //elemanlar� sa�a d�nd�rd�k
	}
	dizi[0]=temp; // saklad���m�z eleman� dizinin en sonuna atad�k
}
int main(){
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);// n=dizinin toplam boyutu/dizideki tek bir eleman�n boyutu = dizideki eleman say�s�
	rotate(arr,n); 
	for(int i=0;i<n;i++)
	printf("%d,",arr[i]);
	getch();
	return 0;
}
