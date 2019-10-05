#include <stdio.h>
#include <stdlib.h>

int recursion(int *arr, int n,int start, int sum,int m)
{
	for(int i=start;i<n;++i)
	{
		sum+=arr[i];
		if(sum%m==0)
		return 1;
		if(recursion(arr,n,i+1,sum,m))
		return 1;
		sum-=arr[i];
	}
	return 0;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int *arr=(int *)malloc(n*sizeof(int));
	for(int i=0;i<n;++i)
	{
		scanf("%d",arr+i);
	}
	if(recursion(arr,n,0,0,m))
	printf("YES");
	else
	printf("NO");
	return 0;
}
