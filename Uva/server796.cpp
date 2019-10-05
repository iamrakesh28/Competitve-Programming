#include <bits/stdc++.h>

#define pb(x) push_back(x)
#define WHITE -1

using namespace std;

list <int> *adj,*link;
int *dfs_num,*dfs_low,counter,dis;

void addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

void bridge(int u,int par)
{
	dfs_low[u] = dfs_num[u] = counter++;
	for(auto it = adj[u].begin();it != adj[u].end(); ++it)
	{
		if(dfs_num[*it] == WHITE)
		{
			bridge(*it,u);
			//bridges
			if(dfs_low[*it] > dfs_num[u])
			{
				link[min(*it,u)].pb(max(*it,u));
				dis++;
			}
			dfs_low[u] = min(dfs_low[*it],dfs_low[u]);
		}
		else if(*it != par)
		dfs_low[u] = min(dfs_num[*it],dfs_low[u]);
	}
}
int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		adj = new list<int>[n];
		link = new list<int>[n];
		dfs_num = new int[n];
		dfs_low = new int[n];
		counter=0,dis = 0;
		memset(dfs_num,WHITE,sizeof(int)*n);
		for(int j=0;j<n;++j)
		{
			int u,m;
			scanf("%d (%d)",&u,&m);
			for(int i=0;i<m;++i)
			{
				int v;
				scanf("%d",&v);
				addEdge(u,v);
			}
		}
		for(int i=0;i<n;++i)
		{
			if(dfs_num[i] == WHITE);
			bridge(i,i);
		}
		printf("%d critical links\n",dis);
		for(int i=0;i<n;++i)
		{
			link[i].sort();
			for(auto it = link[i].begin();it != link[i].end(); ++it)
			printf("%d - %d\n",i,*it);
		}
		putchar('\n');
		delete[] adj,link,dfs_num,dfs_low;
	}
	return 0;
}
