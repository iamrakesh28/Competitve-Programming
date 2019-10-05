#include <bits/stdc++.h>

#define pb(x) push_back(x)
using namespace std;
int max(int a,int b)
{
	return a>b?a:b;
}

bool compare(pair<long int,long int> &a, pair<long int,long int> &b)
{
	if(a.first < b.first)
	return true;
	else if(a.first > b.first)
	return false;
	return (a.second < b.second);
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,count=0,maxm=0;
		scanf("%d",&n);
		vector < pair <long int, long int> >fish;
		long int s,e;
		for(int i=0;i<n;++i)
		{
			scanf("%ld%ld",&s,&e);
			fish.pb(make_pair(s,-1));
			fish.pb(make_pair(e,1));
		}
		sort(fish.begin(),fish.end(),compare);
		for(int i=0;i<2*n;++i)
		{
			if(fish[i].second == 1)
			count++;
			else
			count--;
			maxm = max(maxm,count);
		}
		printf("%d\n",maxm);
	}
	return 0;
}
