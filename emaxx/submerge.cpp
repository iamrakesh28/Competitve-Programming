#include <bits/stdc++.h>

#define N 10005
#define M 100005
using namespace std;

list <int> adj[N];
int dfs_low[N],dfs_num[N],cnt,root,child;
bool art[N],visit[N];
void dfs(int u,int par)
{
	visit[u] = true;
	dfs_low[u] = dfs_num[u] = cnt++;
	for(auto it : adj[u]) {
		if(visit[it] == false) {
			if(u == root)
				child++;
			dfs(it,u);
			if(dfs_low[it] >= dfs_num[u])
				art[u] = true;
			dfs_low[u] = min(dfs_low[u],dfs_low[it]);
		}
		else if(it != par)
			dfs_low[u] = min(dfs_low[u],dfs_num[it]);
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF && (n || m)) {
		for(int i=0;i<n;++i) {
			visit[i] = false;
			adj[i].clear();
			art[i] = false;
		}
		for(int i=0;i<m;++i) {
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);	
		}
		int c = 0;
		root = 0,cnt = 0,child = 0;
		dfs(0,-1);
		art[0] = (child > 1);
		for(int i=0;i<n;++i) {
			if(art[i])
				c++;
		}
		printf("%d\n",c);
	}
	return 0;
}
