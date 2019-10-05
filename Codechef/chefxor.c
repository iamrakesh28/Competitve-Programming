#include <stdio.h>
#include <stdlib.h>

typedef unsigned int un;

un* xor(un n, un k)
{
	int bits;
	un *arr = (un *)calloc(n,sizeof(un));
	for(int i=0;i<32;++i)
	{
		if(1<<i > k)
		{
			bits=i;
			break;
		}
	}
	bits--;
	arr[0] = arr[0] | 1<<bits;
	for(int i=1;i<n;++i)
	{
		for(int j=bits-i;j>=0;j-=n-1)
		{
			arr[i] = arr[i] | 1<<j;
		}
	}
	return arr;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		unsigned int n,k,x=0;
		scanf("%u%u",&n,&k);
		un *arr = xor(n,k);
		for(int i=0;i<n;++i)
		{
			x = x^arr[i];
			printf("%u ",arr[i]);
		}
		//printf("%u ",x);
		printf("\n");
	}
	return 0;
}
