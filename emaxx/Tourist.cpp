#include <bits/stdc++.h>

#define N 400005
using namespace std;

struct edge{
	int v;
	int ind;
};

vector <edge> adj[N];
vector <pair<int,int>> E(N);
int cnt=0,dfs_num[N], dfs_low[N];
bool visit[N],brid[N];

void dfs1(int u,int par)
{
	visit[u] = true;
	dfs_num[u] = dfs_low[u] = cnt++;
	vector <edge> :: iterator it;
	for(it=adj[u].begin();it != adj[u].end(); ++it) {
		if(visit[(*it).v] == false) {
			dfs1((*it).v,u);
			if(dfs_low[(*it).v] > dfs_num[u]) {
				brid[(*it).ind] = true;
			}
			dfs_low[u] = min(dfs_low[u],dfs_low[(*it).v]);
		}
		else if((*it).v != par)
			dfs_low[u] = min(dfs_low[u],dfs_low[(*it).v]);
	}
}

void dfs2(int u,int par)
{
	visit[u] = true;
	for(auto it=adj[u].begin();it != adj[u].end(); ++it) {
		if(visit[(*it).v] == false) {
			if(brid[(*it).ind] == true) {
				//pair<int,int> p = {}
				E[(*it).ind] = {(*it).v,u};
			}
			else 
				E[(*it).ind] = {u,(*it).v};
			dfs2((*it).v,u);
		}
		else if((*it).v != par && E[(*it).ind].first == -1) 
			E[(*it).ind] = {u,(*it).v};
	}
}
int cmp(int u,int par)
{
	visit[u] = true;
	int cnt=1;
	for(auto it=adj[u].begin();it != adj[u].end(); ++it) {
		if(visit[(*it).v] == false) {
			if(brid[(*it).ind] == false) {
				cnt += cmp((*it).v,u);
			}
		}
	}
	return cnt;
}
int main()
{
	int n,m;	
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)
		visit[i] = false;
	for(int i=0;i<m;++i) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u-1].push_back({v-1,i});
		adj[v-1].push_back({u-1,i});
		E[i] = {-1,-1};
		brid[i] = false;
	}
	dfs1(0,0);
	int c=0,v;
	for(int i=0;i<n;++i)
		visit[i] = false;
	for(int i=0;i<n;++i) {
		if(visit[i] == false) {
			int cd = cmp(i,i);
			if(cd > c) { c = cd,v = i; }
		}
	}
	for(int i=0;i<n;++i)
		visit[i] = false;
	dfs2(v,v);
	printf("%d\n",c);
	for(int i=0;i<m;++i) {
		printf("%d %d\n",E[i].first+1,E[i].second+1);
	}
	return 0;
}
