#include <bits/stdc++.h>

using namespace std;
typedef pair <long long, int> ipair;

const long long inf = 1e18;
list <pair <int, int>> adj[200000];
long long dist[200000];
int last[200000];

struct Edge {
	int u, v, road;
	long long w;
} edge[500000];

int dijsktra(int n, int k)
{
	set <ipair> q;
	q.insert(make_pair(0, 0));
	for (int i = 0; i < n; ++i)
		dist[i] = inf;
	dist[0] = 0;
	while (!q.empty()) {
		auto p = *q.begin();
		q.erase(q.begin());
		int u = p.second;
		for (auto it : adj[u]) {
			if (dist[it.second] == inf) {
				dist[it.second] = dist[u] + edge[it.first].w;
				q.insert(make_pair(dist[it.second], it.second));
				last[it.second] = it.first;
			}
			else if (dist[it.second] > dist[u] + edge[it.first].w) {
				q.erase(q.find(make_pair(dist[it.second], it.second)));
				dist[it.second] = dist[u] + edge[it.first].w;
				q.insert(make_pair(dist[it.second], it.second));
				last[it.second] = it.first;
			}
			else if (dist[it.second] == dist[u] + edge[it.first].w) {
					if (edge[last[it.second]].road == 0)
					last[it.second] = it.first;
			}
		}
	}
	int ans = 0;
	for (int i = 1; i < n; ++i) {
		//cout<<dist[train[i].first - 1]<<endl;
		if (edge[last[i]].road == 0)
			ans++;
	}
	return k - ans;
}

int main()
{
	int n, m, k;
	cin>>n>>m>>k;
	for (int i = 0; i < m; ++i) {
		int u, v;
		long long x;
		cin>>u>>v>>x;
		adj[u - 1].push_back(make_pair(i, v - 1));
		adj[v - 1].push_back(make_pair(i, u - 1));
		edge[i].w = x;
		edge[i].road = 1;
	}
	for (int i = 0; i < k; ++i) {
		long long a;
		int b;
		cin>>b>>a;
		edge[i + m].w = a;
		edge[i + m].road = 0;
		adj[0].push_back(make_pair(i + m, b - 1));
		adj[b - 1].push_back(make_pair(i + m, 0));
	}
	cout<<dijsktra(n, k)<<endl;
	return 0;
}
