#include <stdio.h>
#include <stdlib.h>

long int traverse(long int *arr, long int x, long int y, long int n)
{
	long int count=0;
	for(long int i=0;i<n;++i)
	{
		long int num=i&x;
		if(num==i)
		arr[i]-=y;
		if(arr[i]<=0)
		count++;
	}
	return count;
}

int main()
{
	long int n;
	scanf("%ld",&n);	
	long int *arr=(long int *)malloc(sizeof(long int)*n);
	for(long int i=0;i<n;++i)
	{
		scanf("%ld",arr+i);
	}
	long int q,x,y;
	scanf("%ld",&q);
	for(long int i=0;i<q;++i)
	{
		scanf("%ld%ld",&x,&y);
		long int val=traverse(arr,x,y,n);
		printf("%ld\n",n-val);
	}
	free(arr);
	return 0;
}

