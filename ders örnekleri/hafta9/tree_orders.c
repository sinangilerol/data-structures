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
	return n;
}
void pastOrder(struct Node* node){ // (left,right,root)->(root==past)
	if(node==NULL)
		return;
	pastOrder(node->left);
	pastOrder(node->right);
	printf("%d ",node->data);	
}

void inOrder(struct Node* node){ //(left,root,right)->(root==in[left,right])
	if(node==NULL)
		return;
	inOrder(node->left);
	printf("%d ",node->data);
	inOrder(node->right);	
}

void preOrder(struct Node* node){//(root,left,right)->(root==prew)
	if(node==NULL)
		return ;
	printf("%d ",node->data);
	preOrder(node->left);
	preOrder(node->right);	
}

int main(){
	
	struct Node* root=newNode(30);
	root->left=newNode(50);
	root->right=newNode(70);
	root->left->left=newNode(55);
	root->left->right=newNode(60);
	root->right->left=newNode(75);
	root->right->right=newNode(80);

	printf(" pastorder: ");
	pastOrder(root);
	printf("\n inorder: ");
	inOrder(root);
	printf("\n preorder: ");
	preOrder(root);
	return 0;
}


