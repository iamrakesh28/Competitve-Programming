#include <bits/stdc++.h>

#define N 100
using namespace std;
list <int> adj[N],radj[N];
bool visit[N];
stack <int> s;
char line[105];
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
	int n,q;
	scanf("%d",&q);
	while(q--) {
		int cnt = 0;
		scanf("%d",&n);	
		for(int i=0;i<n;++i) {
			adj[i].clear();
			radj[i].clear();
			visit[i] = false;
		}
		for(int i=0;i<n;++i) {
			scanf("%s",line);
			for(int j=0;j<n;++j) {
				if(line[j] == 'Y') {
					adj[i].push_back(j);
					radj[j].push_back(i);
				}
			}
		}
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
		}
		printf("%d\n",cnt);
	}
	return 0;
}
