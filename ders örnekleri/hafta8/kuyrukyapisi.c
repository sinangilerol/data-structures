#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
 
	/* kuyruk, stackin tam tersi bir yapidir.stack lifo seklinde calisirken,kuyruk fifo yapisi ile calisir.
	Stackta eklenen veri dizinin en ustune eklenir(dizinin en buyuk elemanli indisi olur),ve veri cekilirken dizinin en buyuk elemanli 
	indisinden cekilir.Kuyruk yapisinda ise bunun tersinde bir islem yapilir: Veri ekleme dizinin sonundan yapilir,veri cekme ise dizinin basindan yapilir.
	Ornek: 
	1.adim: 5 sayisini ekleme : dizinin en buyuk indisi : 0 
	2.adim: 8 sayisini ekleme : dizinin en buyuk indisi : 1
	3.adim: 9 sayisini ekleme : dizinin en buyuk indisi : 2
	4.adim  veri cekme        : cekilen eleman :5   dizinin en kucuk indisi :1
	5.adim  veri cekme        : cekilen eleman :8   dizinin en kucuk indisi :2
	.... ana mantiki bu sekildedir.
	*/
struct Queue
{
    int front, rear, size; 
    unsigned capacity;
    int* array;
};
 
struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0; 
    queue->rear = capacity - 1; // enqueue fonksiyonu cagirildiginda 0 olur (queue->rear = (queue->rear + 1)%queue->capacity;)  
    queue->array = (int*) malloc(queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{  return (queue->size == queue->capacity);  }
 
int isEmpty(struct Queue* queue)
{  return (queue->size == 0); }
 
void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)%queue->capacity;
    queue->array[queue->rear] = item;  
    queue->size = queue->size + 1;
    printf("%d kuyruga eklendi ...\n", item);
}
 
int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)%queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}
 
int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}
 
int main()
{
    struct Queue* queue = createQueue(10);
 
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
 
    printf("%d kuyruktan cekildi ...\n", dequeue(queue));
 
    printf("En ondeki eleman: %d\n", front(queue)); //yani bir sonraki cekilecek eleman
    printf("Arkadaki eleman : %d\n", rear(queue));  //yani en son eklenen eleman
 
    return 0;
}
/* 
____________________________________________________________________________________
ORNEK: Boyutu 3 olan bir kuyruga ekleme ve silme islemleri yapalim:					|
kuyruk tanimlandiginda :size=0 ,front=0 ,rear=2;									|
1.adim:ekleme(1 verisi) -> rear=(2+1)%3 =0;  size=1;  front=0;  dizideki indisi=0	|
2.adim:ekleme(2 verisi) -> rear=1;           size=2;  front=0;  dizideki indisi=1	|
3.adim:ekleme(3 verisi) -> rear=2;           size=3;  front=0;  dizideki indisi=2	|
_________________________________________________________________________________	|
4.adim:cekme -> dizinin cekilen indisi=0.indis(1 verisi)  front=1;  size=2;			|
5.adim:cekme -> dizinin cekilen indisi=1.indis(2 verisi)  front=2;  size=1;			|
_________________________________________________________________________________	|
6.adim:ekleme(4 verisi) -> rear=(2+1)%3 =0;  size=2;  front=2;  dizideki indisi=0	|
_________________________________________________________________________________	|
7.adim:cekme -> dizinin cekilen indisi=2.indis(3 verisi)  front=(2+1)%3=0;  size=1;	|
8.adim:cekme -> dizinin cekilen indisi=0.indis(4 verisi)  front=1;  size=0;			|
____________________________________________________________________________________|

        
*/
