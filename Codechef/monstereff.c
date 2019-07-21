#include <stdio.h>
#include <stdlib.h>

long int traverse(long int *arr,long int x, long int y, long int n)
{
	long int count=0;
	arr[x]-=y;
	if(arr[x]<=0)
	count++;
	//printf(" %ld ",ar);
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
	long int q,x,y,val=0;
	scanf("%ld",&q);
	for(long int i=0;i<q;++i)
	{
		scanf("%ld%ld",&x,&y);
		val+=traverse(arr,x,y,n);
		printf("%ld\n",n-val);
	}
	free(arr);
	return 0;
}
