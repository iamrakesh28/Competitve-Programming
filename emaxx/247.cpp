#include <bits/stdc++.h>

using namespace std;
list <int> adj[25],radj[25];
map <string,int> mp;
bool visit[25];
int cmp[25];
stack <int> s;
string name[25];
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

void dfs2(int u,int root)
{
	visit[u] = true;
	for(auto it : radj[u]) {
		if(!visit[it]) {
			dfs2(it,root);
		}
	}
	if(u == root)
		cout<<name[u]<<endl;
	else
		cout<<name[u]<<", ";
}

int main()
{
	int n,m,ind = 1;
	while(scanf("%d%d",&n,&m) != EOF && (n || m)) {
		mp.clear();
		int cnt = 0;
		if(ind != 1)
			printf("\n");	
		for(int i=0;i<n;++i) {
			adj[i].clear();
			radj[i].clear();
			visit[i] = false;
		}
		for(int i=0;i<m;++i) {
			string a,b;
			cin>>a>>b;
			if(!mp.count(a)) {
				mp.insert({a,cnt++});
				name[cnt-1] = a;
			}
			if(!mp.count(b)) {
				mp.insert({b,cnt++});
				name[cnt-1] = b;
			}
			adj[mp[a]].push_back(mp[b]);
			radj[mp[b]].push_back(mp[a]);
		}
		for(int i=0;i<n;++i) {
			if(!visit[i])
				dfs1(i);
		}
		memset(visit,false,sizeof visit);
		printf("Calling circles for data set %d:\n",ind);
		while(!s.empty()) {
			int p = s.top();
			s.pop();
			if(!visit[p])
				dfs2(p,p);
		}
		ind++;
	}
	return 0;
}
