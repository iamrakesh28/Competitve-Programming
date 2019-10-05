#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)
#define mk make_pair

typedef long long int lli;
typedef pair <lli,int> ii;

bool compare(ii &a,ii &b)
{
	if(a.first < b.first)
	return true;
	else if(a.first > b.first)
	return false;
	return (a.second < b.second);
}

lli possible(lli n)
{
	lli count=0,start;
	int cur=0;
	vector <ii> V;
	for(lli i=2;i*i*i<=n;++i)
	{
		lli prod = i*i*i;
		lli q = n/prod;
		V.pb(mk(prod,-1));
		V.pb(mk(prod*q,1));
	}
	sort(V.begin(),V.end(),compare);
	for(auto it = V.begin();it!=V.end();++it)
	{
		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	for(auto it = V.begin();it!=V.end();++it)
	{
		if((*it).second == -1)
		{
			if(cur==0)
			start = (*it).first;
			cur++;
		}
		else
		{
			cur--;
			if(cur == 0)
			count += (*it).first - start + 1;
		}
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
