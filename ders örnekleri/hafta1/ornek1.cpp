#include<stdio.h>
#include<conio.h>

void leftRotateOne(int array[],int n){
	int i=0;
	int temp=array[0]; // dizimiz sola döneceði için,0.indisteki veriyi kaybetmeyelim diye temp'de sakladýk
	for(i;i<n-1;i++){
		array[i]=array[i+1]; //elemanlar sola doðru kaydýrýlýr.
	}
	array[i]=temp; //son indisteki elemana,0.indisteki veriyi sakladýðýmýz temp deðiþkenini atadýk
}

void leftRotate(int array[],int d,int n){
	for(int i=0;i<d;i++){ //
		leftRotateOne(array,n); //her sola dönüþ için leftRotateArray fonksiyonuna gidilir,1 indis sola döndürülür
	}
}

int main() {
int array[]={1,2,3,4,5,6,7}; 
leftRotate(array,3,7); //3: sola dönüþ adedi,7:dizideki eleman sayýsý
for(int i=0;i<7;i++){
	printf("%d,",array[i]);

}
getch();
return 0;
}
