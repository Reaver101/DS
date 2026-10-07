#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node *createTree(){
	int value;
	struct node *newnode=(struct node *)malloc(sizeof(struct node));
	printf("\nEnter data(-1 for no node):");
	scanf("%d",&value);
	if (value==-1){
    	return NULL;
	}
	newnode->data=value;
	printf("Enter left child of %d", value);
	newnode->left=createTree();
	printf("Enter right child of %d", value);
	newnode->right=createTree();
	return newnode;
}
void inorder(struct node *root){
	if(root!=NULL){
    	inorder(root->left);
    	printf("%d",root->data);
    	inorder(root->right);

	}
}
void preorder(struct node *root){
	if(root!=NULL){
    	printf("%d", root->data);
    	preorder(root->left);
    	preorder(root->right);

	}
}
void postorder(struct node *root){
	if(root!=NULL){
    	postorder(root->left);
    	postorder(root->right);
    	printf("%d",root->data);
	}
}
int main(){
	struct node *root=NULL;
	printf("\nCreate Binary Tree");
	root = createTree();

	printf("\nInorder Traversal:");
	inorder(root);

	printf("\nPreorder Traversal: ");
	preorder(root);
	printf("\nPostorder Traversal: ");
	postorder(root);

	return 0;
}
