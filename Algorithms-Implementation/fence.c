#include <stdio.h>
#include <stdlib.h>

int minm(int a,int b)
{
	return a<b?a:b;
}

int main()
{
	int n,k,sum,min,index;
	scanf("%d%d",&n,&k);
	int *fence = (int*)malloc(sizeof(int)*n);
	for(int i=0;i<n;++i)
	{
		scanf("%d",fence+i);
		if(i < k)
		min += fence[i];
	}
	sum = min;
	index = 0;
	for(int i=k;i<n;++i)
	{
		sum-=fence[i-k];
		sum+=fence[i];
		min = minm(sum,min);
		if(sum == min)
		index = i-k+1;
	}
	printf("%d\n",index+1);
	return 0;
}
