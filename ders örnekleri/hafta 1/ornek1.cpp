#include<stdio.h>
#include<conio.h>

void leftRotateOne(int array[],int n){
	int i=0;
	int temp=array[0]; // dizimiz sola d�nece�i i�in,0.indisteki veriyi kaybetmeyelim diye temp'de saklad�k
	for(i;i<n-1;i++){
		array[i]=array[i+1]; //elemanlar sola do�ru kayd�r�l�r.
	}
	array[i]=temp; //son indisteki elemana,0.indisteki veriyi saklad���m�z temp de�i�kenini atad�k
}

void leftRotate(int array[],int d,int n){
	for(int i=0;i<d;i++){ //
		leftRotateOne(array,n); //her sola d�n�� i�in leftRotateArray fonksiyonuna gidilir,1 indis sola d�nd�r�l�r
	}
}

int main() {
int array[]={1,2,3,4,5,6,7}; 
leftRotate(array,3,7); //3: sola d�n�� adedi,7:dizideki eleman say�s�
for(int i=0;i<7;i++){
	printf("%d,",array[i]);

}
getch();
return 0;
}
