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
	n->left=n->right=NULL;
	
}
	
int main(){
	struct Node* root=newNode(1);
	root->left=newNode(3);
	root->right=newNode(4);
	root->left->left=newNode(5);
	/*
	
			1
		  /  \
		3	  4
	   /
	  5	
		
	*/
	
	return 0;
}
