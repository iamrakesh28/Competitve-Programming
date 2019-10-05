#include <stdio.h>
#include <stdlib.h>

int mod(int num)
{
	if(num<0)
	return -num;
	return num;
}

int main()
{
	int n,even=0,odd=0;
	scanf("%d",&n);
	long int *arr=(long int*)malloc(sizeof(long int)*n);
	long int *cumev=(long int*)calloc(n,sizeof(long int));
	long int *cumod=(long int*)calloc(n,sizeof(long int));
	long int subarr=0;
	for(int i=0;i<n;++i)
	{
		scanf("%ld",arr+i);
	}
	cumod[0]=1;
	for(int i=0;i<n;++i)
	{
		if(arr[i]%2==0)
		{
			even++;
		}
		else
		{
			odd++;
		}
		if(even>odd)
		cumev[even-odd]++;
		else
		cumod[odd-even]++;
	}
	for(int i=0;i<n;++i)
	{
		subarr+=cumev[i]*(cumev[i]-1)/2;
		subarr+=cumod[i]*(cumod[i]-1)/2;
	}
	printf("%ld\n",subarr);
	return 0;
}
