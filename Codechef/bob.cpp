#include <bits/stdc++.h>

#define ulli unsigned long long int
#define PRIME 1000000007
#define large 1000000000000000000

using namespace std;

void fill(vector <ulli> & rem,vector <ulli> & val)
{
	ulli push;
	int i=2;
	rem.push_back(576923081);
	rem.push_back(576923081);
	val.push_back(1);
	val.push_back(1);
	while(push <= large)
	{
		push = (rem[i-1] * rem[i-2])%PRIME;
		rem.push_back(push);
		push = val[i-1] + val[i-2];
		val.push_back(push);
		i++;
	}
	push = (rem[i-1] + rem[i-2])%PRIME;
	rem.push_back(push);
	push = val[i-1] + val[i-2];
	val.push_back(push);
	
}
ulli remainder(ulli n, vector <ulli> & rem,vector <ulli> & val,int i)
{
	if(n == 0)
	{
		return 1;
	}	
	if(n >= val[i])
	{
		return (rem[i] * remainder(n-val[i],rem,val,i))%PRIME;
	}
	
	return remainder(n,rem,val,i-1);
}

int main()
{
	int q;
	scanf("%d",&q);
	vector <ulli> rem;
	vector <ulli> val;
	fill(rem,val);
	/*for(int i = 0 ;i< rem.size(); ++i)
	{
		printf("%llu %llu\n",rem[i],val[i]);
	}*/
	while(q--)
	{
		ulli n,ans=1;
		scanf("%llu",&n);
		for(ulli i=2;i<=n;++i)
		{
			ans = (ans+remainder(i-ceil(i/2),rem,val,rem.size()-1))%PRIME;	
		}
		printf("%llu\n",ans);
	}
}
