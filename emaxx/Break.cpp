#include <bits/stdc++.h>

#define M 30005
#define N 1005
#define INF 2000000005
using namespace std;

struct edge{
	int v,w,ind;
};
bool E[M],visit[N],Evisit[M];
int wi[M];
vector <edge> adj[N];
pair <int,int> pat[N];
vector <int> sp;
int cnt=0,dfs_low[N],dfs_num[N];
void bridge(int u,int remove) 
{
	visit[u] = true;
	dfs_low[u] = dfs_num[u] = cnt++;
	for(auto it=adj[u].begin(); it!= adj[u].end(); ++it) {
		if(visit[(*it).v] == false && (*it).ind != remove) {
			Evisit[(*it).ind] = true;
			bridge((*it).v,remove);
			if(dfs_low[(*it).v] > dfs_num[u])
				E[(*it).ind] = true;
			dfs_low[u] = min(dfs_low[u],dfs_low[(*it).v]);
		}
		else if(Evisit[(*it).ind] == false && (*it).ind != remove) {
			Evisit[(*it).ind] = true;
			dfs_low[u] = min(dfs_low[u],dfs_low[(*it).v]);		
		}
	}
}

bool bfs(int s,int t,int n)
{
	queue <int> q;
	for(int i=0;i<n;++i) {
		visit[i] = false;
		dfs_low[i] = INF;
	}
	visit[s] = true;	
	q.push(s);
	dfs_low[s] = 0;
	pat[s].first = s;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		if(p == t)
			break;
		for(auto it=adj[p].begin(); it!= adj[p].end(); ++it) {
			if(visit[(*it).v] == false) {
				visit[(*it).v] = true;
				q.push((*it).v);
				pat[(*it).v] = {p,(*it).ind};
				dfs_low[(*it).v] = dfs_low[p] + 1;
			}
		}
	}
	if(dfs_low[t] == INF)
		return false;
	for(int i=t;i != s; i = pat[i].first)
		sp.push_back(pat[i].second);
	return true;
}
pair<int,int> path(int s,int t,int rem,int n)
{
	queue <int> q;
	for(int i=0;i<n;++i) {
		visit[i] = false;
		dfs_low[i] = INF;
	}
	visit[s] = true;	
	q.push(s);
	pat[s].first = s;
	while(!q.empty()) {
		int p = q.front();
		q.pop();
		if(p == t)
			break;
		for(auto it=adj[p].begin(); it!= adj[p].end(); ++it) {
			if(visit[(*it).v] == false && (*it).ind != rem) {
				visit[(*it).v] = true;
				q.push((*it).v);
				pat[(*it).v] = {p,(*it).ind};
				dfs_low[(*it).v] = dfs_low[p] + 1;
			}
		}
	}
	if(dfs_low[t] == INF)
		return {INF,0};
	int w=INF,ind;
	for(int i=t;i != s; i = pat[i].first) {
		if(E[pat[i].second]) {
			if(wi[pat[i].second] < w) {
				w = wi[pat[i].second];
				ind = pat[i].second;
			}
		}
	}
	return {w,ind};
}

int main()
{
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=0;i<m;++i) {
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		E[i] = Evisit[i] = false;
		wi[i] = w;
		adj[u-1].push_back({v-1,w,i});
		adj[v-1].push_back({u-1,w,i});
	}
	bool f = bfs(s-1,t-1,n);
	if(f == false) {
		printf("0\n0\n");
		return 0;
	}
	int minPath = INF,c,r1,r2;
	pair <int,int> p;
	for(auto it : sp) {
		for(int i=0;i<m;++i) {
			E[i] = Evisit[i] = false;		
		}
		for(int i=0;i<n;++i)
			visit[i] = false;
		cnt=0;
		bridge(s-1,it);
		p = path(s-1,t-1,it,n);
		if(p.first != INF) {
			if(wi[it] + p.first < minPath) {
				minPath = wi[it] + p.first;
				r1 = it;
				r2 = p.second;
				c = 2;
			}
		}	
		cnt = 0;
	}
	for(int i=0;i<m;++i) {
		E[i] = Evisit[i] = false;		
	}
	for(int i=0;i<n;++i)
		visit[i] = false;
	bridge(s-1,-1);
	p = path(s-1,t-1,-1,n);
	if(p.first != INF) {
		if(p.first < minPath) {
			minPath = p.first;
			r1 = p.second;
			c = 1;
		}
	}
	if(minPath == INF) {
		printf("-1\n");
		return 0;
	}
	printf("%d\n%d\n",minPath,c);
	if(c == 2) {
		printf("%d %d\n",r1+1,r2+1);
	}
	else
		printf("%d\n",r1+1);
	return 0;
}
