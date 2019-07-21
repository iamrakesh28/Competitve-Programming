#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int min_fun(  int a,   int b)
{
	return a > b ? b : a;
}
void reverse(  int *arr, int start, int end)
{
	int n =end-start+1;
	  int val;
	for(int i = 0 ; i  < n/2  ; ++i)
	{
		val = arr[i + start];
		arr[i + start] = arr[end - i];
		arr[end-i] = val;
	}
}
int check(int *arr,int n)
{
	for(int i =0 ;i < n-1 ;++i)
	{
		if(arr[i] > arr[i+1])
		return 0;
	}
	return 1;
}

void minimum(int *arr,int n,int start,  int *min,   int prev)
{
	int steps;
	for(int i = start +1 ;i < n ; ++i)
	{
		steps = 0;
		minimum(arr,n,start+1,min,steps+prev);
		reverse(arr,start,i);
		steps++;
		if(check(arr,n))
		{
			if(*min)
			*min = min_fun(steps+prev,*min);
			else
			*min = steps+prev;
			reverse(arr,start,i);
			break;
		}
		minimum(arr,n,start+1,min,steps+prev);
		reverse(arr,start,i);
	}
}

int main()
{
		  int n,*arr,min=0,j;
		scanf("%d",&n);
		arr = (  int *)malloc(sizeof(  int )*n);
		for(j=0;j<n;++j)
		{
			scanf("%d",arr+j);
		}
		if(check(arr,n))
		min = 0;
		else
		minimum(arr,n,0,&min,0);
		printf("%d\n ",min);
	return 0;	
}
