#include <stdio.h>
#include <stdlib.h>

struct BST{
	int item;
	struct BST *left;
	struct BST *right;
};

typedef struct BST BST;

BST* newNode(int val)
{
	BST* node = (BST*)malloc(sizeof(BST));
	node->item = val;
	node->left = NULL;
	node->right = NULL;
	return node;
}

BST* insert(int val,BST *head)
{
	if(head == NULL)
	return newNode(val);
	if(val > head->item)
	head->right = insert(val,head->right);
	else
	head->left = insert(val,head->left);
	return head;
}

int search(int key,BST *head)
{
	if(head == NULL)
	return 0;
	if(key == head->item)
	return 1;
	if(key > head->item)
	return search(key,head->right);
	return search(key,head->left);
}

BST* minValueNode(BST *head)
{
	BST* node = head;
	while(node->left != NULL)
	{
		node = node->left;
	}
	return node;
}

BST* deleteNode(int key,BST *head)
{
	if(head == NULL)          //No need
	return head;
	BST *node;
	if(key > head->item)
	head->right = deleteNode(key,head->right);
	else if(key < head->item)
	head->left = deleteNode(key,head->left);
	else
	{
		if(head->left == NULL)
		{
			node = head->right;
			free(head);
			return node;
		}
		if(head->right == NULL)
		{
			node = head->left;
			free(head);
			return node;
		}
		node = minValueNode(head->right);
		head->item = node->item;
		head->right = deleteNode(head->item,node);
		return node;
		
	}
}

void print(BST *head)
{
	if(head == NULL)
	return;
	print(head->left);
	printf("%d\n",head->item);
	print(head->right);
}


int main()
{
	BST *head = NULL;
	int i=0;
	/*while(i<5)
	{
		head=insert(i+5,head);
		++i;
	}
	i=0;
	/*while(i<7)
	{
		printf("%d\n",search(i,head));
		++i;
	}*/
	head = insert(5,head);
	head = insert(3,head);
	head = insert(6,head);
	head = insert(2,head);
	head = insert(9,head);
	print(head);
	deleteNode(2,head);
	print(head);
	return 0;
}
