#include <stdio.h>
#include <stdlib.h>

struct Node{
	int item;
	struct Node *next;
}; 
typedef struct Node Node;

void print(Node *node)
{
	while(node!=NULL)
	{
		printf("%d\t",node->item);
		node = node->next;
	}
	printf("\n");
}

Node* allocate(int item)
{
	Node *new = (Node *)malloc(sizeof(Node));
	new->item = item;
	new->next=NULL;
	return new;
}

/*Node* insertLast(Node *start,Node *node)
{
	Node *cur = start;	
	while(cur!=NULL)
	{
		cur = cur->next;
	}
	cur = node;
	return node->next; //last pointer
}*/

Node* insert(Node *start,Node *node,int location)
{
	Node *cur;
	if(location == 0)	
	{
		node->next = start;
		return node;
	}
	cur = start;	
	int count =0;
	while(cur!=NULL && count < location-1)
	{
		cur = cur->next;
		count++;
	}
	node->next = cur->next;
	cur->next = node;
	return start; 
}

Node* delete(Node *start,int location)
{
	Node *cur,*node;
	if(location == 0)	
	{
		cur = start;
		start = start->next;
		free(cur);
		return start;
	}
	cur = start;	
	int count =0;
	while(cur!=NULL && count < location-1)
	{
		cur = cur->next;
		count++;
	}
	node = cur->next;
	cur->next = node->next;
	free(node);
	return start; 
}

int main()
{
	char ans = 'y';
	Node *start,*stop,*cur;
	int i=0;
	while(i<10)
	{
		cur = allocate(i+10);		
		start = insert(start,cur,i);	
		++i;
	}
	i=0;
	while(i<5)
	{
		int pos;
		scanf("%d",&pos);
		++i;
		start = delete(start,pos);
	}
	print(start);
	return 0;
}
