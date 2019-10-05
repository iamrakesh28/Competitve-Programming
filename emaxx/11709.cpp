#include <bits/stdc++.h>

#define N 1005
using namespace std;
list <int> adj[N],radj[N];
bool visit[N];
map <string,int> mp;
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
	while(scanf("%d%d",&n,&m) != EOF && (n || m)) {
		int cnt;	
		mp.clear();
		char ch = getchar();
		for(int i=0;i<n;++i) {
			adj[i].clear();
			radj[i].clear();
			visit[i] = false;
			string a;
			getline(cin,a);
			mp.insert({a,i});
		}
		for(int i=0;i<m;i++) {
			string a,b;
			getline(cin,a);
			getline(cin,b);
			int u,v;
			u = mp[a];
			v = mp[b];
			adj[u].push_back(v);
			radj[v].push_back(u);
		}
		for(int i=0;i<n;++i) {
			if(!visit[i])
				dfs1(i);
		}
		cnt = 0;
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
