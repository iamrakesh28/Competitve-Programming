#include <stdio.h>
#include <stdlib.h>

float calculate(int n,long int *arr,int c)
{
	float time=0;
	//float lag=0;
	for(int i=0;i<n;++i)
	{
		if(arr[i]>time)
		{		
		time+=arr[i]-time;
		//lag=arr[i];
		}
	}
	return time;
}


int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i)
	{
		int n;
		scanf("%d",&n);
		long int *arr=(long int*)malloc(sizeof(long int)*n);
		int c,d,s;
		float time=0;
		for(int j=0;j<n;++j)
		{
			scanf("%d",arr+j);
		}
		scanf("%d%d%d",&c,&d,&s);
		time=calculate(n,arr,c);
		printf("%0.9f\n",time);
	}

	return 0;
}
