#include <bits/stdc++.h>

#define N 2005
using namespace std;

list <int> adj[N], radj[N];
bool visit[N];
stack <int> s;
void dfs1(int u)
{
	visit[u] = true;
	for(auto it : adj[u]) {
		if(visit[it] == false)
			dfs1(it);
	}
	s.push(u);
}
void dfs2(int u)
{
	visit[u] = true;
	for(auto it : radj[u]) {
		if(visit[it] == false)
			dfs2(it);
	}
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF && (n || m)) {
		for(int i=0;i<n;++i) {
			visit[i] = false;
			adj[i].clear();
			radj[i].clear();		
		}
		for(int i=0;i<m;++i) {
			int v,w,p;
			scanf("%d%d%d",&v,&w,&p);
			adj[v-1].push_back(w-1);
			radj[w-1].push_back(v-1);
			if(p == 2) {
				adj[w-1].push_back(v-1);
				radj[v-1].push_back(w-1);
			}
		}
		for(int i=0;i<n;++i)
			if(visit[i] == false)
				dfs1(i);
		int cmp = 0;
		memset(visit,false,sizeof(bool)*n);
		while(!s.empty()) {
			int u = s.top();
			s.pop();
			if(visit[u] == false) {
				dfs2(u);
				cmp++;
			}
		}
		if(cmp == 1)
			printf("1\n");
		else
			printf("0\n");
	}
	return 0;
}
