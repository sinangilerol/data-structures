#include<stdio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* newNode(int data){
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->data=data;
	n->left=NULL;
	n->right=NULL;
	return n;
}
int height(struct Node* n){
	if(n==NULL)
		return 0;
	else{
		int lheight=height(n->left);
		int rheight=height(n->right);
		if(lheight>rheight)
			return lheight+1;
		return rheight+1;	
		
	}	
}

void printGivenLevel(struct Node* root,int lewel){
	if(root==NULL)
		return ;
	if(lewel==1)
		printf("%d ",root->data);
	else{
		printGivenLevel(root->left,lewel-1);
		printGivenLevel(root->right,lewel-1);
	}		
}

void prinLevelOrder(struct Node* root){
	int h=height(root);
	int i;
	for(i=1;i<=h;i++)
		printGivenLevel(root,i);
		
}
int main(){
	struct Node* root=newNode(1);
	root->left=newNode(10);
	root->right=newNode(100);
	root->left->left=newNode(15);
	root->left->right=newNode(18);
	root->right->left=newNode(150);
	root->right->right=newNode(180);
	prinLevelOrder(root);

	return 0;
}
