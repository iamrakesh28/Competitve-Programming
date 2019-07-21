#include <stdio.h>

long long int gcd(long long int a, long long int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		long long int n,m,sum,x,y;
		scanf("%lld%lld",&n,&m);
		sum=n*(n+1)/2;
		if(sum<m)
		{
			printf("No\n");
			continue;
		}
		x=(sum-m)/2;
		y=(sum+m)/2;
		if(x+y!=sum)
		{
			printf("No\n");
			continue;
		}
		if(gcd(x,y)!=1)
		{
			printf("No\n");
			continue;
		}
		printf("Yes\n");
			
	}

}
