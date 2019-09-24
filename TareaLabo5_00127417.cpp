#include <stdio.h>
#include <stdlib.h>
struct node{int key;
struct node *left, *right;};

struct node *newNode(int item){
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}




struct node* insert(struct node* node, int key){

	if (node == NULL) return newNode(key);
	if (key < node->key)
	node->left = insert(node->left, key);
	else if (key > node->key)
	node->right = insert(node->right, key);
	return node;
}



void inorder(struct node *root){

	if (root != NULL){
	inorder(root->left);
	printf("%d \n", root->key);
	inorder(root->right);
}
}


void preorder(struct node *root){

	if (root != NULL){
	printf("%d \n", root->key);
	preorder(root->left);
	preorder(root->right);

	}
}



void postorder(struct node *root){

	if (root != NULL){
		postorder(root->left);
		postorder(root->right);
		printf("%d \n", root->key);
}
}


struct node* borrar(struct node* nodo, int dato){

	if(nodo->key == dato ){
		if(nodo->right == NULL && nodo->left == NULL){
		struct node* temp = nodo;
		free(temp);
		return NULL;
	}
	if(nodo->right == NULL && nodo->left!=NULL){
		struct node* temp = nodo->left;
		free(nodo);
		return temp;
	}
	if(nodo->right != NULL && nodo->left==NULL){
		struct node* temp = nodo->right;
		free(nodo);
		return temp;
	}
	if(nodo->right != NULL && nodo->left!=NULL){
		struct node* templ = nodo->left;
		struct node* tempr = nodo->right;
		
		if(templ->key>tempr->key){
			templ->right = nodo->right;
			free(nodo);
			return templ;
		}else{
			tempr->left = nodo->left;
			free(nodo);
			return tempr;
		}	
	}
	}

	if(dato < nodo->key)
		nodo->left = borrar(nodo->left,dato);

	else if(dato>nodo->key)
		nodo->right = borrar(nodo->right,dato);

	return nodo;
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

	printf("InOrder\n");
	inorder(root);
	printf("\nPreOrder\n");
	preorder(root);
	printf("\nPostOrder\n");
	postorder(root);
	printf("\n Eliminando dato (80)\n");	
	
	borrar(root,80);
	printf("\nInOrder\n");
	inorder(root);
	printf("\nPreOrder\n");
	preorder(root);
	return 0;


}

