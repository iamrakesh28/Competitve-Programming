#include <stdio.h>

#define N 10

struct Heap{
	int size=0;
	int capacity;
	int *arr;
};

int left(int i)
{
	return 2*i+1;
}
int right(int i)
{
	return 2*i+2;
}
int parent(int i)
{
	return (i-1)/2;
}
int min(int a,int b)
{
	return a<b?a:b;
}

void swap(int *a1,int *b1)
{
	int temp;
	if(*a1 < *b1)
	{
		temp = *b1;
		*b1  = *a1;
		*a1 = temp;
	}
}

void insert(int key,struct Heap min_heap)
{
	min_heap.size += 1;
	if(min_heap.size > min_heap.capacity)
	{
		printf("Oveflow\n");
		return;
	}
	int i = min_heap.size-1;
	min_heap.arr[i] = key;
	while(i!=0 && min_heap.arr[parent(i)] > min_heap.arr[i])
	{
		swap(&min_heap.arr[parent(i)],&min_heap.arr[i]);
		i = parent(i);
	}
	
}

void Minheapify(int index,struct Heap min_heap)
{

}

int extract(struct Heap min_heap)
{
	if(min_heap.size == 0)
	return INT_MAX;
	if(min_heap.size == 1)
	{
		min_heap.size--;
		return min_heap.arr[0];
	}
	min_heap.arr[0] = min_heap.arr[min_heap.size-1];
	min_heap.size--;
	Minheapify(0,min_heap);
}

void heapify(struct Heap min_heap)
{
	int n = min_heap.size;
	for(int i=n/2;i>=0;i--)
	{
		if(left(i) < n && min_heap.arr[left(i)]< min_heap.arr[i])
		swap(&min_heap.arr[left(i)],&min_heap.arr[i]);	
		if(right(i) < n && min_heap.arr[right(i)]< min_heap.arr[i])
		swap(&min_heap.arr[right(i)],&min_heap.arr[i]);		
	}
 }
//decreasing value
void decrease_key(int index,struct Heap min_heap,int new_val)
{
	int i = index;
	min_heap.arr[index] = new_val;
	while(i !=0 && min_heap.arr[i] > min_heap.arr[parent(i)])
	{
		swap(&min_heap.arr[i],&min_heap.arr[parent(i)]);
		i = parent(i);
	}	
}
void delete(int i,struct Heap min_heap)
{
	decrease_key(i,min_heap,INT_MIN);
	extract(min_heap);
}

int main()
{
	int *arr = (int*)malloc(sizeof(int)*N);
	int i=0;
	while(i<N)
	{
		arr[i] = i;
		++i;
	}
	return 0;
} 
