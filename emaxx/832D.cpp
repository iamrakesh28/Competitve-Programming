#include <bits/stdc++.h>

#define N 100000
using namespace std;

list <int> adj[N];
int dist[N], tin[N], tout[N], up[N][18], l, cnt;

void dfs(int u, int p) {

	tin[u] = cnt++;
	up[u][0] = p;
	for (int i = 1; i <= l; ++i)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto it : adj[u]) {
		if (it != p) {
			dist[it] = dist[u] + 1;
			dfs(it, u);
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

int solve(int a, int b, int c) {
	
	if (ancestor(a, b) && ancestor(a, c)) {
		int lc = lca(b, c);
		return dist[lc] - dist[a] + 1;
	}
	if (ancestor(a, b))
		return 1;
	if (ancestor(a, c))
		return 1;
	int l1 = lca(a, b), l2 = lca(a, c);
	if (l1 != l2) {
		l1 = dist[a] - dist[l1] + 1;
		l2 = dist[a] - dist[l2] + 1;
		return min(l1, l2);
	}
	int d = dist[a] - dist[l1] + 1;
	l2 = lca(b, c);
	d += dist[l2] - dist[l1];
	return d;
}
int main() {

	int n, q;
	scanf("%d%d", &n, &q);
	for (int i = 1; i < n; ++i) {
		int v;
		scanf("%d", &v);
		adj[i].push_back(v - 1);
		adj[v - 1].push_back(i);
	}
	l = ceil(log2(n)), cnt = 0;
	dist[0] = 0;
	dfs(0,0);
	while (q--) {

		int a, b, c, ans;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--, c--;
		// a
		ans = solve(a, b, c);	
		// b
		ans = max(ans, solve(b, a, c));
		// c
		ans = max(ans, solve(c, a, b));
		printf("%d\n", ans);
	}
	return 0;
}
