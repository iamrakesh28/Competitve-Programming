#include <stdio.h>
#include <stdlib.h>

typedef unsigned int un;

/*un product(un a, un b)
{
	un and=0;
	for(int i=31;i>=0;i--)
	{
		if( (1 << i & a) == (1 << i & b) )
		{
			and = and | (1 << i & a);
		}
		else
		break;
	}
	return and;
}
*/
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		un n,and;
		scanf("%u",&n);
		un *arr = (un *)malloc(sizeof(un)*n);
		for(int i=0;i<n;++i)
		scanf("%u",arr+i);
		and = arr[0]^arr[n-1];
		if(n%2==0)
		and = 0;
		printf("%u\n",and);
	}
	return 0;
}
