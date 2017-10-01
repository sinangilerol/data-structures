/*
dizi icerisinde bulunan 2 elemanin birbirlerine olan min. uzakligini bulur
Ornek: dizi={4,7,1,3,2,4,6,5,1,9,8}
4 ile 1 arasındaki mesafeler:
i-)dizi[0]=4 && dizi[2]=1 olup => 2-0=2 dir
ii-)dizi[2]=1 && dizi[5]=4 olup =>5-2=3 dur
iii-)dizi[5]=4 && dizi[8]=1 olup =>8-5=3 dur
iV-)dizi[0]=4 && dizi[8]=1 olup=>8-0=8 dir

bu 4 secenekten min. uzakliga sahip olan i. secenektir yani min. mesafe =>2 dir
*/
#include <stdio.h>
#include <limits.h> // Kutuphanedesindeki INT_MAX sabitini kullanmak icin dahil ettik.
#include <stdlib.h>// abs()[ mutlak deger] fonksiyonunu barindirir.

int minDist(int arr[],int n,int x,int y){ 
int i,j;
int min_dist=INT_MAX; //min_dist degiskeninde 2147483647 sayisi (en buyuk int sayisi ) atanir
for(i=0;i<n;i++){
	for(j=i+1;j<n;j++){
		if( ( ( x==arr[i]&& y==arr[j] ) ||  (x==arr[j] && y==arr[j]) ) && min_dist>abs(i-j) ){
			min_dist=abs(i-j);
		}
		
	}
} /*
dizi icerisinde parametre olarak verilen sayilar aranir.Eger bu sayilar bulunursa,bulunduklari indisler mutlak deger icerisinde birbirinden cikarilir.Eger bu fark 
min_dist degiskeninden kucukse (eger bu islem ilk defa yapiliyorsa, buldugumuz fark 2147483647 sayisi ile kiyaslanir [ buyuk ihtimalle de  bu sayidan kucuktur  :) ] )
yeni min_dist degeri buldugumuz fark olur.
*/

return min_dist;
}

int main(){
		int arr[]={4,7,1,3,2,4,6,5,1,9,8};
	printf("%d ile %d arasindaki min. mesafe = %d",4,1,minDist(arr,sizeof(arr)/sizeof(arr[0]),4,1));
	getch();
	return 0;
}
