#include<stdio.h>

int rec(int *arr,int n, int start, int x, int val, int sum, int iter,int result)
{
//	if(result==0)
	for(int i=start;i<n-iter;++i)
	{
		arr[i]=1;
		if(val==sum)
		{	if(arr[x-1]==0)
			result=1;
			return result;
		}
		rec();
	}

}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int x,n;
		scanf("%d%d",&x,&n);
		int sum;
		sum=n*(n+1)/2-x;
		int *arr=(int *)calloc(n,sizeof(int));
	}
	return 0;
}
