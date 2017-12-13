#include<stdio.h>
#include<stdlib.h>

  
struct node{
    int key;
    struct node *left, *right;
};
  
struct node *newNode(int item){
    struct node *temp =(struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}


struct node* insert(struct node* node, int key){
	
    if (node == NULL) return newNode(key);
 
 	if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}

int isBSD_1(struct node* n){
	if(n==NULL)
		return 1;
	if(n->left!=NULL && n->left->key > n->key)
		return 0;
	if(n->right!=NULL && n->right->key < n->key)
		return 0;		
	if(!isBSD_1(n->left) || !isBSD_1(n->right))
		return 0;
	return 1;		
}

struct node* leafDelete(struct node* root){
	if(root->left==NULL && root->right==NULL){
		free(root);
		return NULL;
	}
	root->left=leafDelete(root->left);
	root->right=leafDelete(root->right);
	return root;
}


int main(){
	
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inorder(root);
 	
 	if(isBSD_1(root))
 		printf("\n bsd\n");
	else
		printf("\n not bsd\n");

	root=leafDelete(root);
	inorder(root);
	

}
