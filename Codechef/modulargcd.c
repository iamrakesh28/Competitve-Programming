#include <stdio.h>
#include <stdlib.h>

#define PRIME 1000000007
typedef unsigned long long int ul;

ul gcd(ul a, ul b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
ul repeat(ul time,ul p,ul t)
{
	ul r=1;
	while(time)
	{
		if(time%2)
		r = (r*p)%t;
		p = (p*p)%t;
		time/=2;
	}
	return r%t;
}

int main()
{
	int q;
	scanf("%d",&q);
	ul a = 1000000000;
	printf("%llu\n",a*a);
	while(q--)
	{
		ul a,b,n,mod,ans,an,bn;
		scanf("%llu%llu%llu",&a,&b,&n);
		mod = a-b;
		//printf("%lld %lld",mod,a-b);
		if(mod == 0)
		{
			an = repeat(n,a%PRIME,PRIME);
			ans = (an + an)%PRIME;
			printf("%lu\n",ans);
			continue;
		}
		an = repeat(n,a%mod,mod);
		bn = repeat(n,b%mod,mod);
		ans = gcd(mod,(an+bn)%mod)%PRIME;
		printf("%llu\n",ans);
		
	}
	return 0;
}
