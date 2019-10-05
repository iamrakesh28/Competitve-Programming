#include <stdio.h>
#include <math.h>
#include <stdlib.h>

unsigned int calc(unsigned int *arr, int l,int r,unsigned int value)
{
	unsigned int num=0;
	for(int i=l;i<r;++i)
	{
		num+=arr[i]^value;
	}
	return num;
}

int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	unsigned int *arr=(unsigned int *)malloc(sizeof(unsigned int)*n);
	unsigned int power,min=0,max;
	for(int i=0;i<n;++i)
	{
		scanf("%u",arr+i);
	}
	while(q--)
	{
		int l,r;
		scanf("%d%d",&l,&r);
		power=pow(2,31)-1;
		max=calc(arr,l-1,r,power);
		min=power;
		//printf("%u %u",min,max);
		power--;
		for(int i=0;i<1000;++i)
		{
			unsigned int val=calc(arr,l-1,r,power);
			if(val>=max)
			{
				max=val;
				min=power;
			}
			power--;
			//printf("%u\n",max);
		}
		printf("%u\n",min);
	}
	return 0;
}
