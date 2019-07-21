#include <stdio.h>
#include <stdlib.h>

struct BST{
	int item,rank;
	struct BST *left,*right;
};

typedef struct BST BST;

BST* newNode(int val)
{
	BST* node = (BST*)malloc(sizeof(BST));
	node->item = val;
	node->rank = 1;
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
	head->rank += 1;
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

int updateRank(BST *head)
{
	if(head==NULL)
	return 0;
	return (head->rank = updateRank(head->left) + updateRank(head->right) + 1);
}

void print(BST *head)
{
	if(head == NULL)
	return;
	print(head->left);
	printf("%d %d\n",head->item,head->rank);
	print(head->right);
}

int ksmall(BST *head,int k)
{
	int n;
	if(head->left != NULL)
	n = head->left->rank;
	else
	n = -1;
	if(n+1 == k)
	return head->left->item;
	else if(n+1 < k)
	{
		return ksmall(head->right,k);
	}
	else
	return ksmall(head->left,k);
}

int main()
{
	BST *head = NULL;
	int i=0;
	while(i<5)
	{
		head=insert(i,head);
		++i;
	}
	i=0;/*
	head = insert(5,head);
	head = insert(3,head);
	head = insert(6,head);
	head = insert(2,head);
	head = insert(9,head);*/
	/*while(i<5)
	{
		printf("%d\n",search(i,head));
		++i;
	}*/
	//print(head);
	//deleteNode(2,head);
	int a = updateRank(head);
	print(head);
	int k = ksmall(head,2);
	printf("%d\n",k);
	return 0;
}
