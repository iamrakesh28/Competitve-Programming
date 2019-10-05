#include <bits/stdc++.h>

#define N 50000
using namespace std;

list <pair <int, int>> adj[N];
int dist[N], tin[N], tout[N], up[N][17], l, cnt;

void dfs(int u, int p) {

	tin[u] = cnt++;
	up[u][0] = p;
	for (int i = 1; i <= l; ++i)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto it : adj[u]) {
		if (it.second != p) {
			dist[it.second] = dist[u] + it.first;
			dfs(it.second, u);
		}
	}
	tout[u] = cnt++;
}

bool ancestor(int u, int v) {

	return tin[u] <= tin[v] && tout[u] >= tout[v]; 
}

int lca(int u, int v) {

	if (ancestor(u, v))
		return u;
	if (ancestor(v, u))
		return v;	
	for (int i = l; i >= 0; --i)
		if (!ancestor(up[u][i], v))
			u = up[u][i];
	return up[u][0];
}
int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		adj[u].push_back({w, v});
		adj[v].push_back({w, u});
	}
	l = ceil(log2(n)), cnt = 0;
	dist[0] = 0;
	dfs(0,0);
	int m;
	scanf("%d", &m);
	while (m--) {

		int u, v;
		scanf("%d%d", &u, &v);
		int lc = lca(u, v);
		//cout<<lc<<endl;
		printf("%d\n", dist[u] + dist[v] - 2 * dist[lc]);
	}
	return 0;
}
