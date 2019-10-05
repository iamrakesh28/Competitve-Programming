#include <bits/stdc++.h>

#define N 10000
using namespace std;

int l, cnt, tin[N], tout[N], up[N][18], dist[N], path[N], power[20];
list <pair <int, int >> adj[N];

void dfs(int u, int p) {

	tin[u] = cnt++;
	up[u][0] = p;
	for (int i = 1; i <= l; ++i)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto it : adj[u]) {
		if (it.second != p) {
			dist[it.second] = dist[u] + it.first;
			path[it.second] = path[u] + 1;
			dfs(it.second, u);
		}
	}
	tout[u] = cnt++;
}

bool ancestor(int u, int v) {

	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {

	if (ancestor(u,v))
		return u;
	if (ancestor(v,u))
		return v;
	for (int i = l; i >= 0; i--) {
		if (!ancestor(up[u][i], v))
			u = up[u][i];
	}
	return up[u][0];
}

int solve(int u, int k) {

	int ans = 1, node = u;
	for (int i = l; i >= 0; i--) {
		if (ans + power[i] <= k) {
			ans += power[i];
			node = up[u][i];
			u = up[u][i];
		}
	}
	return node + 1;
}
int main() {

	int t;
	scanf("%d", &t);
	power[0] = 1;
	for (int i = 1; i < 20; ++i)
		power[i] = power[i - 1] * 2;
	while (t--) {
		int n;
		scanf("%d", &n);
		assert(n <= N);
		l = ceil(log2(n));
		cnt = 0;
		for (int i = 0; i < n; ++i)
			adj[i].clear();
		for (int i = 0; i < n - 1; ++i) {

			int a, b, c;
			scanf("%d%d%d", &a, &b, &c);
			adj[a - 1].push_back({c, b - 1});
			adj[b - 1].push_back({c, a - 1});
		}
		dist[0] = path[0] = 0;
		dfs(0, 0);
		int a, b;
		char q[6];
		while (scanf("%s", q) != EOF && strcmp(q, "DONE") != 0) {
			scanf("%d%d", &a, &b);
			a--, b--;
			int lc = lca(a, b);
			if (strcmp(q, "DIST") == 0)
				printf("%d\n", dist[a] + dist[b] - 2* dist[lc]);
			else {
				int k, v, v1, u;
				scanf("%d", &k);
				v = path[a] + path[b] - 2 * path[lc] + 1;
				v1 = path[a] - path[lc] + 1;
				if (v1 >= k)
					printf("%d\n", solve(a, k));
				else
					printf("%d\n", solve(b, v - k + 1));
			}
		}
		printf("\n");
	}
}
