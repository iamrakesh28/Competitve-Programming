#include <stdio.h>
#include <stdlib.h>

typedef struct MinheapNode{
	int v;
	int dist;
}MinheapNode;

typedef struct Minheap{
	int heap_size;
	int *pos;
	MinheapNode **arr;
}Minheap;

void swap(MinheapNode **a,MinheapNode **b)
{
	MinheapNode *c = *a;
	*a = *b;
	*b = c;
}
MinheapNode* newnode(int dist)
{
	MinheapNode *node = (MinheapNode*)malloc(sizeof(MinheapNode));
	//node->v = v;
	node->dist = dist;
	return node;
}
void Minheapify(Minheap *minheap,int idx)
{
	int left = 2*idx + 1;
	int right = 2*idx + 2;
	int smallest = idx;
	if(left < minheap->heap_size && minheap->arr[smallest]->dist > minheap->arr[left]->dist)
	smallest = left;
	if(right < minheap->heap_size && minheap->arr[smallest]->dist > minheap->arr[right]->dist)
	smallest = right;	
	if(smallest != idx)
	{
		minheap->pos[minheap->arr[idx]->v] = smallest;
		minheap->pos[minheap->arr[smallest]->v] = idx;
		swap(&minheap->arr[smallest],&minheap->arr[idx]);
		Minheapify(minheap,smallest);
	}
}
Minheap* createHeap(int v)
{
	int x;
	Minheap *minheap = (Minheap *)malloc(sizeof(Minheap));
	minheap->arr  = (MinheapNode **)malloc(sizeof(MinheapNode*)*v);
	minheap->pos = (int *)malloc(sizeof(int)*v);
	minheap->heap_size = v;
	for(int i=0;i<v;++i)
	{
		scanf("%d",&x);
		minheap->arr[i] = newnode(x);
		minheap->arr[i]->v = i;
		minheap->pos[i] = i;
	}
	for(int i=v/2;i>=0;i--)
	Minheapify(minheap,i);
	return minheap;
}

void changeval(Minheap *minheap,int idx,int val)
{
	int pos = minheap->pos[idx];
	int parent;
	parent = (pos-1)/2;
	if(minheap->arr[pos]->dist > val)
	{
		minheap->arr[pos]->dist = val;
		if(parent > 0 && val < minheap->arr[parent]->dist)
		{
			minheap->pos[minheap->arr[pos]->v] = parent;
			minheap->pos[minheap->arr[parent]->v] = pos;
			swap(&minheap->arr[pos],&minheap->arr[parent]);
			pos = parent;
			parent = (parent-1)/2;
		}
		return;
	}
	else
	{
		minheap->arr[pos]->dist = val;
		Minheapify(minheap,pos);
	}
	
}
int extract(Minheap *minheap)
{
	int min = minheap->arr[0]->dist;
	minheap->pos[minheap->arr[minheap->heap_size-1]->v] = 0;
	minheap->pos[minheap->arr[0]->v] = minheap->heap_size-1;
	swap(&minheap->arr[0],&minheap->arr[minheap->heap_size-1]);	
	minheap->heap_size = minheap->heap_size - 1;
	Minheapify(minheap,0);
	return min;
}

int main()
{
	int v;
	scanf("%d",&v);
	Minheap *minheap = createHeap(v);
	//changeval(minheap,0,10);
	//changeval(minheap,3,20);
	for(int i=0;i<v;++i)
	{
		int small = extract(minheap);
		printf("%d ",small);
	}
	printf("\n");
	return 0;
}
