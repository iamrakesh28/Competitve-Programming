#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)

int count;

int gcd(int a,int b)
{
	if(b==0)
	return a;
	return gcd(b,a%b);
}

void DFS(int *parent,list <int> *adj,int node,int *st,int *end)
{
	st[node] = ::count;
	list <int> :: iterator it;
	for(it = adj[node].begin();it!= adj[node].end();++it)
	{
		if(*it != parent[node])
		{
			(::count)++;
			parent[*it] = node;
			DFS(parent,adj,*it,st,end);
		}
	}
	end[node] = ::count;
}

int main()
{	
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		list <int> *adj = new list <int> [n];
		for(int i=0;i<n-1;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u-1].pb(v-1);
			adj[v-1].pb(u-1);
		}
		::count = 0;
		int *parent = new int[n];
		int *st = new int[n];
		int *end = new int[n];
		parent[0] = -1;
		DFS(parent,adj,0,st,end);
		int *cm = new int[n+1];
		memset(cm,0,sizeof(int)*(n+1));
		int g,k;
		scanf("%d%d",&g,&k);
		for(int i=0;i<g;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			if(parent[v-1] == u-1)
			{
				cm[0]++;
				cm[st[v-1]]--;
				cm[end[v-1]+1]++;
				cm[n]--;
			}
			else
			{
				cm[st[u-1]]++;
				cm[end[u-1]+1]--;
			}
		}
		int sum=0;
		for(int i=1;i<n;++i)
		{
			cm[i] += cm[i-1];
			//printf("%d ",cm[i]);
			if(cm[i] >= k)
			sum++;
		}
		if(cm[0] >= k)
		sum++;
		if(sum > 0 )
		{
			int p,q,_gcd = gcd(sum,n);
			p = sum/_gcd;
			q = n/_gcd;
			printf("%d/%d\n",p,q);
		}
		else
		printf("0/1\n",n);
		//delete [];
	}
	return 0;
}
