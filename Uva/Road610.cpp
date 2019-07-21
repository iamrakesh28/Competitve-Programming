#include <bits/stdc++.h>

#define pb(x) push_back(x)
#define WHITE -1

using namespace std;

list <int> *adj;
int *dfs_num,*dfs_low,counter,*par;

void addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

void bridge(int u)
{
	dfs_num[u] = dfs_low[u] = counter++;
	for(auto it = adj[u].begin();it != adj[u].end(); ++it)
	{
		if(dfs_num[*it] == WHITE)
		{
			par[*it] = u;
			printf("%d %d\n",u+1,(*it)+1);
			bridge(*it);
			if(dfs_low[*it] > dfs_num[u])
			printf("%d %d\n",(*it)+1,u+1);
			dfs_low[u] = min(dfs_low[u],dfs_low[*it]);
		}
		else if(*it != par[u])
		{
			dfs_low[u] = min(dfs_low[u],dfs_num[*it]);
			if(dfs_num[*it] < dfs_num[u])
			printf("%d %d\n",u+1,(*it)+1);
		}
	}
}
int main()
{
	int n,m,i=0;
	while(scanf("%d%d",&n,&m) && m && n)
	{
		adj = new list<int>[n];
		dfs_num = new int[n];
		dfs_low = new int[n];
		memset(dfs_num,WHITE,sizeof(int)*n);
		par = new int[n];
		par[0] = 0;
		counter = 0;
		for(int i=0;i<m;++i)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			addEdge(u-1,v-1);
		}
		printf("%d\n\n",++i);
		bridge(0);
		printf("#\n");
		delete [] adj,dfs_low,dfs_num,par;
	}
	return 0;
}
