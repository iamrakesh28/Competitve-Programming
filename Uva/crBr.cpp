#include <bits/stdc++.h>

using namespace std;

int getMid(int s, int e) {  return s + (e -s)/2;  } 

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) 
{ 
    	if (qs <= ss && qe >= se) 
        return st[si]; 
    	if (se < qs || ss > qe) 
        return 0; 
    	int mid = getMid(ss, se); 
    	return getSumUtil(st, ss, mid, qs, qe, 2*si+1) + 
           	getSumUtil(st, mid+1, se, qs, qe, 2*si+2); 
} 
void updateValueUtil(int *st, int ss, int se, int i, int diff, int si) 
{ 
    	if (i < ss || i > se) 
        return; 
    	st[si] = st[si] + diff; 
    	if (se != ss) 
    	{ 
        	int mid = getMid(ss, se); 
        	updateValueUtil(st, ss, mid, i, diff, 2*si + 1); 
        	updateValueUtil(st, mid+1, se, i, diff, 2*si + 2); 
    	} 
} 
  
void updateValue(int arr[], int *st, int n, int i, int new_val) 
{ 
    	if (i < 0 || i > n-1) 
    	{ 
        	printf("Invalid Input"); 
        	return; 
    	} 
  
    	int diff = new_val - arr[i]; 
   	arr[i] = new_val; 
    	updateValueUtil(st, 0, n-1, i, diff, 0); 
} 
  
int getSum(int *st, int n, int qs, int qe) 
{ 
    	if (qs < 0 || qe > n-1 || qs > qe) 
    	{ 
        	printf("Invalid Input"); 
        	return -1; 
    	} 
  
    	return getSumUtil(st, 0, n-1, qs, qe, 0); 
} 
  
int constructSTUtil(int arr[], int ss, int se, int *st, int si) 
{ 
    	if (ss == se) 
    	{ 
        	st[si] = arr[ss]; 
        	return arr[ss]; 
    	} 
    	int mid = getMid(ss, se); 
    	st[si] =  constructSTUtil(arr, ss, mid, st, si*2+1) + 
              constructSTUtil(arr, mid+1, se, st, si*2+2); 
    	return st[si]; 
} 
  
int *constructST(int *arr, int n) 
{ 
    	int x = (int)(ceil(log2(n)));  
 	int max_size = 2*(int)pow(2, x) - 1;  
    	int *st = new int[max_size]; 
    	constructSTUtil(arr, 0, n-1, st, 0); 
    	return st; 
} 
int *par,*size;
int parent(int root)
{
	if(root == par[root])
	return root;
	return parent(par[root]);
}
void join(int x,int y,int *arr,int *st,int n)
{
	x = parent(x);
	y = parent(y);
	if(x == y)
	return ;
	updateValue(arr, st, n, size[x], arr[size[x]]-1);
	updateValue(arr, st, n, size[y], arr[size[y]]-1);
	updateValue(arr, st, n, size[y]+size[x], arr[size[y]+size[x]]+1); 
	if(size[x] > size[y])
	{
		size[x] += size[y];
		par[y] = x;	
	}
	else
	{
		size[y] += size[x];
		par[x] = y;
	}
}

int main()
{
	int n,q;
	char name[10];
	scanf("%d%d",&n,&q);
	par = new int[n];
	size = new int[n];
	int *arr = new int[n+1];
	for(int i=0;i<n;++i)
	{
		par[i] = i;
		size[i] = 1;
		arr[i] = 0;
	}
	arr[n] = 0;
	arr[1] = n;
	int *st = constructST(arr, n+1);
	while(q--)
	{
		int x,y;
		scanf("%s%d%d",name,&x,&y);
		if(strcmp(name,"Charlie") == 0)
		join(x,y,arr,st,n+1);
		else
		{
			//for(int i=0;i<n+1;++i)
			//printf("%d ",arr[i]);
			int sum = getSum(st, n+1, x, y);
			printf("%d\n",sum);
		}
	}
	delete [] par,size;
	return 0;
}
