#include <bits/stdc++.h>

using namespace std;

list <int> adj[1000];
int tin[1000], tout[1000], up[1000][11], l, tim;

void dfs(int u, int p) {

	tin[u] = tim++;
	up[u][0] = p;
	for (int i = 1; i <= l; ++i)
		up[u][i] = up[up[u][i - 1]][i - 1];

	for (int it : adj[u]) {
		if (it != p)
			dfs(it, u);
	}
	tout[u] = tim++;
}

bool ancestor(int u, int v) {

	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {

	if (ancestor(u, v))
		return u;
	if (ancestor(v, u))
		return v;
	for (int i = l; i >= 0; --i) {
		if (!ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}
int main() {
	
	int t, cnt = 0;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		tim = 0, l = ceil(log2(n));
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		for (int i = 0; i < n; ++i) {
			int m;
			scanf("%d", &m);
			int v;
			while (m--) {
				scanf("%d", &v);
				adj[i].push_back(v - 1);
				adj[v - 1].push_back(i);
			}
		}
		int q;
		dfs(0, 0);
		scanf("%d", &q);
		printf("Case %d:\n", cnt + 1);
		while (q--) {
			int v, w;
			scanf("%d%d", &v, &w);
			printf("%d\n", lca(v - 1, w - 1) + 1);
		}	
		cnt++;
	}
	return 0;
}
