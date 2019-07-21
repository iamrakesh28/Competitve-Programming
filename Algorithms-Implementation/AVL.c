#include <stdio.h>
#include <stdlib.h>

struct AVL{
	int key,height;
	struct AVL *left,*right;
};

typedef struct AVL AVL;

int max(int a, int b)
{
	return a>b?a:b;
}

int height(AVL *node)
{
	if(node == NULL)
	return 0;
	return node->height;
}

AVL* newNode(int key)
{
	AVL *node = (AVL*)malloc(sizeof(AVL));
	node->key = key;
	node->height = 1;
	node->left = NULL;
	node->right = NULL;
	return node;
}

/*
		z                                        y
	       / \                                      / \
	      y   T4                                   x   z
	     / \           Right Rotate               / \ / \
	    x  T3          ------------->            T1 T2T3 T4
	   / \
	  T1 T2

*/
/*
		z                                        y
	       / \                                      / \
	      y   T4                                   x   z
	     / \           Left Rotate                / \ / \
	    T3  x          ------------->            y   T
	       / \ 
	      T2  T3

*/
AVL *rightRotate(AVL *z)
{
	AVL *y = z->left;
	AVL *T3 = y->right;
	z->left = T3;
	y->right = z;
	y->height = 1 + max(height(y->left),height(y->right));
	z->height = 1 + max(height(z->left),height(z->right));
	return y;
}

AVL *leftRotate(AVL *y)
{
	AVL *x = y->right;
	AVL *T2 = x->left;
	x->left = y;
	y->right = T2;
	y->height = 1 + max(height(y->left),height(y->right));
	x->height = 1 + max(height(x->left),height(x->right));
	return x;
}

int getBalanced(AVL *head)
{
	if(head == NULL)
	return 0;
	return height(head->left)-height(head->right);
}

AVL *insert(int key,AVL *node)
{
	if(node == NULL)
	return newNode(key);
	if(key > node->key)
	node->right = insert(key,node->right);
	else
	node->left = insert(key,node->left);
	node->height = 1 + max(height(node->left),height(node->right));
	int bal = getBalanced(node);
	if(bal > 1 && key < node->left->key)
	return rightRotate(node);
	if(bal > 1 && key > node->left->key)
	{
		node->left = leftRotate(node->left);
		return rightRotate(node);
	}
	if(bal < -1 && key > node->right->key)
	return leftRotate(node);
	if(bal < -1 && key < node->right->key)
	{
		node->right = rightRotate(node->right);
		return leftRotate(node); 
	}
	return node;	
}

void inorder(AVL *head)
{
	if(head == NULL)
	return;
	inorder(head->left);
	printf("%d %d\n",head->key,head->height);
	inorder(head->right);
}

int main()
{
	int i=0;
	AVL *head=NULL;
	while(i<5)
	{
		head = insert(i+5,head);
		i++;
	}
	/*head = insert(5,head);
	head = insert(3,head);
	head = insert(6,head);
	head = insert(2,head);
	head = insert(9,head);*/
	//inorder(head);
	printf("%d\n",height(head));
	return 0;
}
