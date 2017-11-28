#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char data;
	struct Node* left;
	struct Node* right;
};


struct Node* newNode(char data){
	struct Node* n=(struct Node*)malloc(sizeof(struct Node));
	n->data=data;
	n->left=n->right=NULL;
}



struct Node* createMors(){
	struct Node* root=newNode(' ');
	//_______________________________________-
	root->left=newNode('E');
	root->right=newNode('T');
	//____________________________________________
	root->left->left=newNode('I');
	root->left->right=newNode('A');
	root->right->left=newNode('N');
	root->right->right=newNode('M');
	//_______________________________________________
	root->left->left->left=newNode('S');
	root->left->left->right=newNode('U');
	root->left->right->left=newNode('R');
	root->left->right->right=newNode('W');
	root->right->left->left=newNode('D');
	root->right->left->right=newNode('K');
	root->right->right->left=newNode('G');
	root->right->right->right=newNode('O');
	//_____________________________________________________
	root->left->left->left->left=newNode('H');
	root->left->left->left->right=newNode('V');
	root->left->left->right->left=newNode('F');
	root->left->left->right->right=newNode('@'); //bos 
	root->left->right->left->left=newNode('L');
	root->left->right->right->left=newNode('P');
	root->left->right->right->right=newNode('J');
	root->right->left->left->left=newNode('B');
	root->right->left->left->right=newNode('X');
	root->right->left->right->left=newNode('C');
	root->right->left->right->right=newNode('Y');
	root->right->right->left->left=newNode('Z');
	root->right->right->left->right=newNode('Q');
	root->right->right->right->left=newNode('@');//bos
	root->right->right->right->right=newNode('@');//bos
	//_________________________________________________________
	root->left->left->left->left->left=newNode('5');
	root->left->left->left->left->right=newNode('4');
	root->left->left->left->right->right=newNode('3');
	root->left->left->right->right->right=newNode('2');
	root->left->right->right->right->right=newNode('1');
	root->right->left->left->left->left=newNode('6');
	root->right->right->left->left->left=newNode('7');
	root->right->right->right->left->left=newNode('8');
	root->right->right->right->right->left=newNode('9');
	root->right->right->right->right->right=newNode('0');	
	return root;
	
}


char morsToChar(char* mors){
	struct Node* root=createMors();
	struct Node* temp=root;
	int i,j=0;
	for(i=0;i<=strlen(mors);i++){
		if(mors[i]=='.')
		temp=temp->left;
		if(mors[i]=='-' || mors[i]=='_')
		temp=temp->right;
		if(mors[i]=='/')
		mors[j++]=' ';
		if(!mors[i] || mors[i]==' '){
			if(temp->data==' ') 
				continue;
		mors[j++]=temp->data;
		temp=root;	
		}
		
	}
	
	mors[j++]='?';
	mors[j]='\0';
	return *mors;
}
int main(){
	
	
	
	char mors[]="-... .. -. -... .. .-. / -... .- ... .-.. .. / -.- .- .-. - .- .-.. .. / -. .- ... .. .-.. / - .- ... .. .-. / -.- .- -. .- .-. -.-- .-";
	*mors=morsToChar(mors);
	printf("%s",mors);
	return 0;
}
