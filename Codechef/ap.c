#include <stdio.h>

long int mod(long int a)
{
	if(a<0)
	return -a;
	return a;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long int a,b,c,mid,ways;
		scanf("%ld%ld%ld",&a,&b,&c);
		mid = (a+c)/2;
		if(2*mid==a+c)
		{
			ways=mod(b-mid);
			printf("%ld\n",ways);
		}
		else
		{
			if(mid>b)
			{
				ways=(mid-b)+1;
			}
			else
			{
				ways=(b-mid-1)+1;
			}
			printf("%ld\n",ways);
		}
	}
	return 0;
}
