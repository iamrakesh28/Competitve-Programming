#include <bits/stdc++.h>

#define pb(x) push_back(x)

using namespace std;

list <int> *adj;
int *dfs_num,*dfs_low,*par,con,root,point;
bool *visited;

void addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

void ArtPoint(int node)
{
	visited[node] = true;
	dfs_num[node] = dfs_low[node] = con++;
	for(auto it = adj[node].begin(); it != adj[node].end(); ++it)
	{
		if(visited[*it] == false)
		{
			par[*it] = node;
			if(node == 0)
			con++;
			ArtPoint(*it);
			if(dfs_low[*it] >= dfs_num[node])
			point++;
			dfs_low[node] = min(dfs_low[node],dfs_num[*it]);
		}
		else if(*it != par[node])
		dfs_low[node] = min(dfs_low[node],dfs_num[*it]);
	}
}

int main()
{
	int n;
	while(scanf("%d",&n) != EOF)
	{
		adj = new list <int> [n];
		dfs_num = new int[n];
		dfs_low = new int[n];
		visited = new bool[n];
		par = new int[n];
		point = 0;
		par[0] = 0;
		memset(visited,false,sizeof(bool)*n);
		int u;
		con = 0;
		scanf("%d",&u);
		while(u)
		{
			int v;
			for(int i=0;i<u;++i)
			{
				scanf("%d",&v);
				addEdge(u-1,v-1);
			}
			scanf("%d",&u);
		}
		ArtPoint(0);
		printf("%d\n",point);
	}
	return 0;
}
