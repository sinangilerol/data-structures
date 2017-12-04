#include<stdio.h>
#include<stdlib.h>
 
struct node{
    int data;
    struct node *left, *right;
};
 

struct node *newNode(int data){
    struct node* node =(struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = node->right = NULL;
    return(node);
}
 
void inorder(struct node *root){
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void fixPrevPtr(struct node *root){
    static struct node *pre = NULL;
 
    if (root != NULL)
    {
        fixPrevPtr(root->left);
        root->left = pre;
        pre = root;
        fixPrevPtr(root->right);
    }
}
 

struct node *fixNextPtr(struct node *root){
    struct node *prev = NULL;
 
    while (root && root->right != NULL)
        root = root->right;
 
    while (root && root->left != NULL){
        prev = root;
        root = root->left;
        root->right = prev;
    } 
    return (root);
}
 
struct node *BTToDLL(struct node *root){
    fixPrevPtr(root); 
    return fixNextPtr(root);
}
 
void printList(struct node *root){
    while (root != NULL){
        printf("%d ", root->data);
        root = root->right;
    }
}

int main(){
    struct node *root = newNode(1);
    root->left        = newNode(2);
    root->right       = newNode(3);
    root->left->left  = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    inorder(root);
    struct node *head = BTToDLL(root);
    printf("\n");
    printList(head);
    return 0;
}
