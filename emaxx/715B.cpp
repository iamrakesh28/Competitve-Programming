#include <bits/stdc++.h>

using namespace std;
typedef pair <long long, int> ipair;

const long long inf = -1;
list <pair <int, int>> adj[1000];
long long dist[1000];
int mark[10000];
pair <int, int > par[1000];

struct Edge {
	int assin, u, v;
	long long w;
} edge[10000];

int dijsktra(int n, int s, int t, long long L, int k, int m)
{
	set <ipair> q;
	q.insert(make_pair(0, s));
	for (int i = 0; i < n; ++i)
		dist[i] = inf;
	dist[s] = 0;
	par[s].first = -1;
	while (!q.empty()) {
		auto p = *q.begin();
		q.erase(q.begin());
		int u = p.second;
		for (auto it : adj[u]) {
			if (dist[it.second] == inf) {
				dist[it.second] = dist[u] + edge[it.first].w;
				q.insert(make_pair(dist[it.second], it.second));
				par[it.second].second = it.first;
				par[it.second].first = u;
			}
			else if (dist[it.second] > dist[u] + edge[it.first].w) {
				q.erase(q.find(make_pair(dist[it.second], it.second)));
				dist[it.second] = dist[u] + edge[it.first].w;
				q.insert(make_pair(dist[it.second], it.second));
				par[it.second].second = it.first;
				par[it.second].first = u;
			}
		}
	}
	//cout<<t<<" "<<dist[t]<<endl;
	if (dist[t] >  L || dist[t] == -1)
		return -1;
	if (dist[t] == L)
		return 1;
	int found = -1;
	for (int i = t; i != -1; i = par[i].first) {
		if (edge[par[i].second].assin == 0) {
			found = 2;
			edge[par[i].second].assin = 1;
			edge[par[i].second].w += L - dist[t];
			break;
		}
	}
	if (k == 0) {
		for (int i = t; i != -1; i = par[i].first)
			mark[par[i].second] = 1;
		for (int i = 0; i < m; ++i) {
			if (mark[i] == 0 && edge[i].assin == 0) {
				edge[i].assin = 1;
				edge[i].w += L;
			}
		}
	}
	return found;
}

int main()
{
	int n, m, L, s, t;
	cin>>n>>m>>L>>s>>t;
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long x;
		cin>>u>>v>>x;
		adj[u].push_back(make_pair(i, v));
		adj[v].push_back(make_pair(i, u));
		edge[i].w = x;
		edge[i].u = u;
		edge[i].v = v;
		edge[i].assin = 1;
		if (x == 0) {
			edge[i].assin = 0;
			edge[i].w = 1;
		}
		mark[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		int ans = dijsktra(n, s, t, L, i, m);
		if (ans == -1) {
			cout<<"NO\n";
			break;
		}
		if (ans == 1) {
			cout<<"YES\n";
			for (int i = 0; i < m; ++i)
				cout<<edge[i].u<<" "<<edge[i].v<<" "<<edge[i].w<<endl;
			break;
		}
	}
	return 0;
}
