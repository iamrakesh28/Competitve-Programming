#include <bits/stdc++.h>

#define PRIME 1000000007
#define ul int_128

using namespace std;

ul gcd(ul a, ul b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}
ul prd(ul a,ul b,ul t)
{
	ul r = 0,y=a;
	while(b>0)
	{
		if(b&1)
		r = (r+y)%t;
		y = (y + y)%t;
		b >>= 1;
	}
	return r;
}
ul repeat(ul time,ul p,ul t)
{
	ul r=1;
	while(time)
	{
		if(time%2)
		r = prd(r,p,t);
		p = prd(p,p,t);
		time/=2;
	}
	return r;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		ul a,b,n,mod,ans,an,bn;
		//scanf("%lu%lu%lu",&a,&b,&n);
		cin>>a>>b>>n
		mod = abs(a-b);
		if(mod == 0)
		{
			an = repeat(n,a%PRIME,PRIME);
			bn = repeat(n,b%PRIME,PRIME);
			ans = (an + bn)%PRIME;
			printf("%lu\n",ans);
			continue;
		}
		an = repeat(n,a%mod,mod);
		bn = repeat(n,b%mod,mod);
		ans = gcd(mod,(an+bn)%mod)%PRIME;
		cout<<ans<<endl;
		//printf("%lu\n",ans);
		
	}
	return 0;
}
