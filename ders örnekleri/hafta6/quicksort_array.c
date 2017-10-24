#include<stdio.h>
#include<stdlib.h>
int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=(low-1);
	int j;
	for(j=low;j<=high-1;j++){
		if(arr[j]<=pivot){
			i++;
			swap(&arr[i],&arr[j]);
			
		}
	}
	swap(&arr[i+1],&arr[high]);
			return i+1;
}
void quickSort(int arr[],int low,int high){
	if(low<high){
		int pi=partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}
void swap(int* a,int* b){
	int t=*a;
	*a=*b;
	*b=t;
}
void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
int main(){
	int arr[] = {12, 11, 13, 5, 6,7};
	int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    printArray(arr, arr_size);
 
   quickSort(arr, 0, arr_size - 1);
 
    printf("\nSorted array is \n");
    printArray(arr, arr_size);
	return 0;
}
