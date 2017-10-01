/*
sirali bir sekildeki dizide, eksik olan en kucuk sayi bulunur
Ornek: dizi={0,1,2,3,4,7,8}
=> dizisinde eksik olan en kucuk sayi 5 dir
*/
#include <stdio.h>
#include <conio.h>
int findFirstMissing(int arr[],int start,int end){
	if (start>end){
		return end+1;}
	if(start!=arr[start]){
		return start;}
	int mid=(start+end)/2;
	/*
	diziyi 2 ye bolelim.sonra dizinin ortasındaki elemanin dizinin orta indisinde olup olmadigini kontrol edelim.
	*/
	if(arr[mid]==mid){
		return findFirstMissing(arr,mid+1,end);
	//eger ortadaki sayi,ortadaki indiste ise dizinin sol tarafindaki sayilarda herhangi bir eksik yok demektir. oyleyse eksigi dizinin sag tarafinda arayalim 	
	}
	//eger ortadaki sayi,ortadaki indiste degilse dizinin sol tarafinda eksik bir sayi var demektir.oyleyse eksigi dizinin sol tarafinda arayalim
	return findFirstMissing(arr,start,mid);
}
int main(){
	int arr[]={0,1,2,3,4,7,8};
	int n=sizeof(arr)/sizeof(arr[0]);
	printf("en kucuk eksik sayi =%d",findFirstMissing(arr,0,n-1));
	getch();
	return 0;
}
/*
programi adim adim takip edelim :
1-)program basladiginda : fonksiyonun içindeki ilk 2 if i saglamaz ve 3.if e gelir.arr[3]==3 old.dan
 fonksiyonu tekrar cagirir ve parametreleri (arr,3+1,6) yapar
2-)fonksiyona 2. geldiginde de ilk 2 if i saglamaz ve 3. if e gelir.arr[5](7) != 5 old.dan,3. if blogunun dısındaki 
return'u calistirir.parametreler ise (arr,4,5) olur.
3-)fonksiyona 3. geldiginde de ilk 2 if i saglamaz (mid degeri (4+5)/2=4.5 den 4 e yuvarlanir) ve 3. if e gelir.arr[4](4)==4 old.dan
fonksiyonu tekrar cagirir ve parametreleri (arr,4+1,5) yapar
4-)fonksiyona 4. geldiginde ilk if i saglamaz ve 2. if e gelir.5!=arr[5](7) sartini sagladigindan geriye start degerini yani 5 degerini 
dondurur.Gercektende dizimizdeki en kucuk kayip eleman 5 dir.
*/
