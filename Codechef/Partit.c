#include <stdio.h>
#include <stdlib.h>

int finder(bool *arr,int n)
{
	for(int i=1;i<=n;++i)
	{
		if(arr[i]==true)
		return i;
	}
}
void  prition(int sum, int n)
{
	bool **arr=(bool **)malloc(sizeof(bool **)*(sum+1));
	//for(int i=0;i<sum+1;++i)
	*arr=(bool *)malloc((n+1)*sizeof(bool));
	for(int i=0;i<=n;++i)
	*((*arr)+i)=true;
	for(int i=1;i<=sum;++i)
	{
		*(arr+i)=(bool *)malloc((n+1)*sizeof(bool));
		**(arr+i)=false;
		for(int j=1;j<=n;++j)
		{
			arr[i][j] = arr[i][j-1];
                        if (i >= j)
           		arr[i][j] = arr[i][j] || arr[i - j][j-1];	
		}
	}
	for(int i;i;++i)
	{
	
	}
	for(int i=1;i<=n;++i)
	printf("%d ",arr[sum][i]);
}


int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int x,n,sum;
		scanf("%d%d",&x,&n);
		sum=n*(n+1)/2-x;
		if(sum%2==0)
		{
			prition(sum/2,n);
		}
	}
	return 0;
}
