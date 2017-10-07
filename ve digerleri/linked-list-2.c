#include <stdio.h>
#include <stdlib.h>
struct Node {
	int data;
	struct Node* next;
};
void push(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=*head_ref;
	*head_ref=new_node;
}
void insertAfter(struct Node* prew,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=prew->next;
	prew->next=new_node;
}
void append(struct Node** head_ref,int new_data){
	struct Node* new_node=(struct Node*)malloc(sizeof(struct Node));
	new_node->data=new_data;
	new_node->next=NULL;
	struct Node* temp=*head_ref;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new_node;
}
void deleteNode(struct Node** head_ref,int s_data){
	struct Node* temp=*head_ref,*prew;
	if(temp->data==s_data){
		*head_ref=temp->next;
		free(temp);
		return ;
	}
	while(temp!=NULL && temp->data!=s_data){
		prew=temp;
		temp=temp->next;
	}
	if(temp==NULL){
		printf (" ####   data bulunamadi   ####\n");
		return;
	}
	prew->next=temp->next;
	free(temp);
}
void deleteRotate(struct Node** head_ref,int position){
	struct Node* temp=*head_ref;
	if(position==1){
		*head_ref=temp->next;
		free(temp);
		return;
	}
	int i;
	for(i=1;temp!=NULL&&i<position-1;i++){
		temp=temp->next;
	}
	if(temp==NULL){
		printf (" ####   pozisyon bulunamadi   ####\n");
		return ;
	}
	struct Node* next=temp->next;
	temp->next=next->next;
	free(next);
}
void getPosition(struct Node** head_ref,int position,int data){
	struct Node* temp=*head_ref;
	if(position==1){
		insertAfter(*head_ref,data);
		return ;
	}
	int i;
	for(i=1;temp!=NULL && i!=position;i++){
		temp=temp->next;
	}
	if(temp==NULL){
		printf (" ####   pozisyon bulunamadi   ####\n");
		return;
	}
	insertAfter(temp,data);
	
}

void goster(struct Node* liste){
	if(liste==NULL){
		printf ("#####   dugum yok    #####\n");
	}
	while(liste!=NULL){
		printf("%d - ",liste->data);
		liste=liste->next;
		
	}
	printf("\n");
}

int main(){
	struct Node* head=(struct Node*)malloc (sizeof(struct Node));
	head->next=NULL;
	int g_data,menu=2;
	printf("ilk dugumun datasini girin...\n");
	scanf("%d",&g_data);
	head->data=g_data;
	while(menu!=4){
		printf("dugum silmek icin 1 e,yeni dugum eklemek icin 2 ye, dugumlerdeki datalari gormek icin 3 e, cikmak icin 4 e basin...\n");
		scanf("%d",&menu);
		if(menu==1){
		int alt_menu;
		printf("silme islemini dataya gore yapmak icin 1 e,pozisyona gore yapmak icin 2 ye,ana manuye donmek icin 3 basin..\n");
		scanf("%d",&alt_menu);
			if(alt_menu==1){
				printf("silmek istediginiz datayi giriniz..\n");
				int silinecek_data;
				scanf("%d",&silinecek_data);
				deleteNode(&head,silinecek_data);
			}		
			else if(alt_menu==2){
				printf("silmek istediginiz pozisyonu giriniz..\n");
				int silinecek_pozisyon;
				scanf("%d",&silinecek_pozisyon);
				deleteRotate(&head,silinecek_pozisyon);
				
			}
			else if(alt_menu=3){
				continue ;
			}
		}
		else if(menu==2){
		int alt_menu;
		printf("eklemek istediginiz dugumu basa eklemek icin 1 e,belli bir pozisyona eklemek icin 2 ye, \n sona eklemek icin 3 e,ana menuye donmek icin 4 e basin\n");
		scanf("%d",&alt_menu);
			if(alt_menu==1){
			printf("eklemek istediginiz datayi giriniz..\n");
			int data;
			scanf("%d",&data);
			push(&head,data);
			}
			else if(alt_menu==2){
				printf("yanina ekleme yapmak istediginiz pozisyonu girin..\n");
				int position,data;
				scanf("%d",&position);
				printf("eklemek istediginiz datayi girin..\n");
				scanf("%d",&data);
				getPosition(&head,position,data);
			}
			else if(alt_menu==3){
			printf("eklemek istediginiz datayi giriniz\n");
				int data;
				scanf("%d",&data);
				append(&head,data);
				
			}
			else if(alt_menu==4){
			continue;
			}	
		}
		else if(menu==3){
			goster(head);
		}
	}
	return 0 ;
}
