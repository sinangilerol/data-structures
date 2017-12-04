#include <stdio.h>
#include <conio.h>
/*   

DÝZÝDEKÝ ELEMANLARI 1 KERE SAÐA DÖNDÜRÜR


*/
void rotate(int dizi[],int n){ // 1 kere saða döndüren fonksiyon
	int temp=dizi[n-1]; // en saðdaki elemaný sakladýk
	for(int i=n-1;i>0;i--){
		dizi[i]=dizi[i-1]; //elemanlarý saða döndürdük
	}
	dizi[0]=temp; // sakladýðýmýz elemaný dizinin en sonuna atadýk
}
int main(){
	int arr[]={1,2,3,4,5};
	int n=sizeof(arr)/sizeof(arr[0]);// n=dizinin toplam boyutu/dizideki tek bir elemanýn boyutu = dizideki eleman sayýsý
	rotate(arr,n); 
	for(int i=0;i<n;i++)
	printf("%d,",arr[i]);
	getch();
	return 0;
}
