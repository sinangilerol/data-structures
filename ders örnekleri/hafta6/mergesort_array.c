#include<stdio.h>
#include<stdlib.h>
void merge(int arr[],int l,int m,int r){
	int i,j,k;
	int n1=m-l+1;
	int n2=r-m;
	int L[n1],R[n2];
	for(i=0;i<n1;i++){// soldaki parca L dizisinde
		L[i]=arr[l+i];
	}
	for(j=0;j<n2;j++){//sagdaki parca R dizisinde
		R[j]=arr[m+1+j];
	}
	i=0; j=0; k=l;
	while(i<n1 && j<n2){// 2 parcadan herhangi birisi bitmedigi surece:
		if(L[i]<=R[j]){// soldaki parcanin kiyaslanan elemani sagdakinin kiyaslanan elemanindan kucukse:
			arr[k]=L[i];//arr[k] ya kucuk olani ata
			i++; //atanan elemandan bir sonraki elemana gec
		}else{ // sagdaki buyukse tam tersi
			arr[k]=R[j];
			j++;
		}
		k++;
	}
	
	while(i<n1){ // eger sagdaki parca bitmisse
	arr[k]=L[i]; //arr[k] yi soldaki parcanin elemanlari ile devam ettir
	i++; k++;		
	}
	while(j<n2){//tam tersi...
		arr[k]=R[j];
		j++; k++;
	}
	
}
void mergeSort(int arr[],int l,int r){ //bolme algoritmamiz..
/*
dizimiz tum elemanlarina kadar parcalanincaya kadar fonksiyon kendini cagirir.tum elemanlar parcalaninca merge fonksiyonu ile birlestirilmeye baslanir
ornek:
4-7-8-3 siralamak istedigimiz dizi olsun:
1.adim: 4-7 ve 8-3 olarak 2 ye ayrilir ve tekrar mergeSort fonksiyonu cagrilir(her bir parca icin)
2.adim: 4,7,8 ve 3 olarak dizimiz 4 e ayrilir ve tekrar mergeSort fonksiyonu cagrilir(her bir parca icin)
3.adim: 4 parcada mergeSort algiritmasinin kosuluna takilir(if (l<r) ) ve artik parcalar birlesmeye baslar(if kosulu saglanmadigi icin yeni bir fonk. cagrilmaz 
ve geldigi recursive fonksiyona geri doner.
4.adim: 4 ve 7 birlesir ve 4-7 olur.
5.adim: 8 ve 3 birlesir ve 3-8 olur
6.adim 4-7 ve 3-8 birlesir ve 3-4-7-8 olur.siralama islemi biter.
*/
	if(l<r){
		int m=l+(r-l)/2;
		mergeSort(arr,l,m);
		mergeSort(arr,m+1,r);
		merge(arr,l,m,r);
	}
}
void goster(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main(){
	int arr[] = {12, 11, 13, 5, 6, 7};
	int arr_size = sizeof(arr)/sizeof(arr[0]); //dizimizin boyutunu bulduk
 
    printf("siralanmamis dizi: \n");
    goster(arr, arr_size);
 
    mergeSort(arr, 0, arr_size - 1); //fonksiyona ilk eleman ve son elemanin indislerini gonderdik
 
    printf("\nsiralanmis dizi:  \n");
    goster(arr, arr_size);
	return 0;
}
