#include <bits/stdc++.h>

using namespace std;

list <int> adj[100];
int cnt,child,art[100],dfs_low[100],dfs_num[100];
bool visit[100];
void dfs(int u, int par)
{
	visit[u] = true;
	dfs_low[u] = dfs_num[u] = cnt++;
	for(auto it : adj[u]) {
		if(visit[it] == false) {	
			dfs(it,u);
			if(u == 0)
				child++;
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
	int n;
	char ch;
	while(scanf("%d",&n) != EOF && n) {
		for(int i=0;i<n;++i) {
			visit[i] = false;
			art[i] = false;
			adj[i].clear();
		}
		int u,x=0;
		child = cnt = 0;
		scanf("%d",&u);
		while(u) {
			ch = getchar();
			while((ch = getchar()) && ch != '\n') {
				if(ch == ' ') {
					adj[u-1].push_back(x-1);
					adj[x-1].push_back(u-1);
					x = 0;
				}
				else
					x = x*10 + ch - '0';
			}
			adj[u-1].push_back(x-1);
			adj[x-1].push_back(u-1);
			scanf("%d",&u);
			x = 0;
		}
		dfs(0, 0);
		art[0] = (child > 1);
		cnt=0;
		for(int i=0;i<n;++i)
			if(art[i])
				cnt++;
		printf("%d\n",cnt);	
	}
	return 0;
}

