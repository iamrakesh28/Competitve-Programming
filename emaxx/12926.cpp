#include <bits/stdc++.h>

#define N 5005
using namespace std;
list <int> adj[N],radj[N];
int adjMat[N][N];
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
	for(auto it : radj[u]) {
		if(!visit[it]) {
			dfs2(it);
		}
	}
}

int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF) {
		int cnt = 0,d;	
		for(int i=0;i<n;++i) {
			adj[i].clear();
			radj[i].clear();
			visit[i] = false;
			memset(adjMat[i],0,sizeof(int)*n);
		}
		for(int i=0;i<m;++i) {
			int a,b;
			scanf("%d%d",&a,&b);
			adjMat[a-1][b-1] = 1;
		}
		scanf("%d",&d);
		for(int i=0;i<n;++i) {
			for(int j=0;j<n;++j) {
				if(i == j)
					continue;
				if(adjMat[i][j] == 0) {
					adj[i].push_back(j);
					radj[j].push_back(i);
				}
			}
		}/*
		for(int i=0;i<n;++i) {
			if(!visit[i])
				dfs1(i);
		}
		memset(visit,false,sizeof(bool)*n);
		while(!s.empty()) {
			int p = s.top();
			s.pop();
			if(!visit[p]) {
				dfs2(p);
				cnt++;
			}
		}*/
		printf("%d\n",d*cnt);
	}
	return 0;
}
