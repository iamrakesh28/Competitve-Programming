#include <bits/stdc++.h>

#define N 1000005
using namespace std;

list <int> adj[N],radj[N];
bool visit[N];
int fun[N],cmp[N],cnt=0,E,S,n,m;
long long dp[N],cfun[N];
stack <int> s;
void dfs1(int u)
{
	visit[u] = true;
	for(auto it : adj[u]) {
		if(!visit[it])
			dfs1(it);
	}
	s.push(u);
}

void dfs2(int u)
{
	visit[u] = true;
	cmp[u] = cnt;
	for(auto it : radj[u]) {
		if(!visit[it])
			dfs2(it);
	}
}

void ans(int u)
{
	visit[u] = true;	
	if(cmp[u] == cmp[E]) {
		dp[cmp[u]] = cfun[cmp[u]];
		return;
	}
	dp[cmp[u]] = 0;
	for(auto it : adj[u]) {
		if(!visit[it])
			ans(it);
		if(cmp[u] != cmp[it])
			dp[cmp[u]] = max(dp[cmp[u]],dp[cmp[it]] + cfun[cmp[u]]);
		else
			dp[cmp[u]] = max(dp[cmp[u]],dp[cmp[it]]);
	}
}
int main()
{
	scanf("%d%d%d%d",&n,&m,&S,&E);
	S--, E--;
	for(int i=0;i<n;++i) {
		scanf("%d",fun+i);
		visit[i] = false;	
	}
	while(m--) {
		int u,v;
		scanf("%d%d",&u,&v);
		adj[u-1].push_back(v-1);
		radj[v-1].push_back(u-1);	
	}
	for(int i=0;i<n;++i) 
		if(!visit[i])
			dfs1(i);
	memset(visit,false,sizeof(bool)*n);
	while(!s.empty()) {
		int p = s.top();
		s.pop();
		if(!visit[p]) {
			dfs2(p);	
			cnt++;	
		}
	}
	memset(cfun,0,sizeof(long long)*cnt);
	for(int i=0;i<n;++i) {
		cfun[cmp[i]] += fun[i]; 
	}
	memset(visit,false,sizeof(bool)*n);
	ans(S);
	printf("%ld\n",dp[cmp[S]]);
	return 0;
}
