#include <stdio.h>
#include <math.h>

int div(int n)
{
	int sq=sqrt(n);
	for(int i=2;i<=sq;++i)
	{
		if(n%(i*i)==0)
		return 0;
	}
	return 1;
}

int main()
{
	int n;
	scanf("%d",&n);
	if(div(n))
	{
		printf("%d\n",n);
		return 0;
	}
	for(int i=n/2;i>1;i--)
	{
		if(n%i==0)
		if(div(i))
		{
			printf("%d\n",i);
			return 0;
		}
		
	}
	return 0;
}