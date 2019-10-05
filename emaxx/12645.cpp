#include <bits/stdc++.h>

#define N 1005
using namespace std;
list <int> adj[N];
bool visit[N];
stack <int> s;
void dfs1(int u) 
{	
	visit[u] = true;
	for(auto it : adj[u]) {
		if(!visit[it]) {
			dfs1(it);
		}
	}
	s.push(u);
}

void dfs2(int u)
{
	visit[u] = true;
	for(auto it : adj[u]) {
		if(!visit[it]) {
			dfs2(it);
		}
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF) {
		n++;
		int cnt = 0;	
		for(int i=0;i<n;++i) {
			adj[i].clear();
			visit[i] = false;
		}
		for(int i=0;i<m;++i) {
			int a,b;
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
		}
		for(int i=0;i<n;++i) {
			if(!visit[i])
				dfs1(i);
		}
		memset(visit,false,sizeof visit);
		dfs2(0);
		cnt++;
		while(!s.empty()) {
			int p = s.top();
			s.pop();
			if(!visit[p]) {
				dfs2(p);
				cnt++;
			}
		}
		printf("%d\n",cnt-1);
	}
	return 0;
}
