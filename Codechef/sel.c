#include <stdio.h>
#include <stdlib.h>

void sortn(int k, int n, int *sort)
{
	for(int i=0;i<k;++i)
	{
		int min=sort[i];
		for(int j=i+1;j<n;++j)
		{
			if(min>sort[j])
			{
				min=sort[j];
				int num=sort[i];
				sort[i]=sort[j];
				sort[j]=num;	
			}
		}
	}
}
int main()
{
	int n,k;
	int *arr=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;++i)
	{	
		scanf("%d",arr+i);
	}
	int *sort=(int *)malloc(sizeof(int)*n*(n+1)/2);
	int min,or,count=0;
	for(int i=0;i<n;++i)
	{	
		min=arr[i];
		or=arr[i];
		for(int j=i;j<n;++j)
		{
			if(arr[j]<min)
			min=arr[j];
			or=or^arr[j];
			sort[count]=min*or;
			count++;
		}
	}
	sortn(k,n,sort);
	printf("%d\n",sort[k-1]);
	return 0;
}