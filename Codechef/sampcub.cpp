#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)
#define mk make_pair

typedef long long int lli;

lli possible(lli n)
{
	lli count=0,a,b=1;
	for(a=2;a*a*a*b<=n;++a)
	{
		for(;b*a*a*a<=n;++b)
		{
			count++;
		}
		b=1;
	}
	return count;
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		lli n;
		cin>>n;
		lli ans = possible(n);
		cout<<ans<<endl;
	}
	return 0;
}
