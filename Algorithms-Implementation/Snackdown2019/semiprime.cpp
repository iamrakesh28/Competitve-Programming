#include <bits/stdc++.h>

#define pb(x) push_back(x)
using namespace std;

void semi(int n,vector <int> &V)
{
	int num = n;
	vector <int> f;
	while(n % 2 == 0)
	{
		f.pb(2);
		n = n/2;
	}
	for(int i = 3;i*i <= n; i+=2)
	{
		while(n%i ==0)
		{
			f.pb(i);
			n = n/i;
		}
	}
	if(n > 2)
	f.pb(n);
	if(f.size()==2 && f[0] != f[1])
	V.pb(num);
}
void prime(vector <int> &V,set <int> &p)
{
	for(int i = 3; i <= 200; i++)
	semi(i,V);
	for(int i = 0;i < V.size();i++)	
	{
		for(int j = i;j < V.size();++j)
		p.insert(V[i]+V[j]);
	}
}

int main()
{
	int q;
	scanf("%d",&q);
	vector <int> V;
	set <int> p;
	prime(V,p);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		auto it = p.find(n);
		if(it == p.end())
		printf("NO\n");
		else
		printf("YES\n");
	}
	return 0;
}
