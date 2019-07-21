#include <bits/stdc++.h>

#define N 50000
using namespace std;

int par[N], size[N], tin[N], tout[N], up[N][20], Max[N][20], l, cnt;
list <pair <int, int>> adj[N];
pair <int, pair <int, int> >edge[100000];

int find(int u) {

	if (u == par[u])
		return u;
	return find(par[u]);
}

void join(int u, int v, int w) {

	int x = u, y = v;
	u = find(u), v = find(v);
	if (u == v)
		return;
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
	}
	else {
		size[v] += size[u];
		par[u] = v;
	}
	adj[x].push_back({w, y});
	adj[y].push_back({w, x});
	return;
}

void dfs(int u, int p, int w) {

	up[u][0] = p;
	tin[u] = cnt++;
	if (u == p)
		Max[u][0] = -1;
	else
		Max[u][0] = w;
	for (int i = 1; i <= l; i++) {
		Max[u][i] = max(Max[u][i - 1], Max[up[u][i - 1]][i - 1]);
		up[u][i] = up[up[u][i - 1]][i - 1];
	}
	for (auto it : adj[u]) {
		if (it.second != p)
			dfs(it.second, u, it.first);
	}
	tout[u] = cnt++;
	return;
}

bool ancestor(int u, int v) {

	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int solve(int s, int t) {

	int ans = -1;
	for (int i = l; i >= 0; i--) {
		if (!ancestor(up[s][i], t)) {
			ans = max(ans, Max[s][i]);
			s = up[s][t];
		}
	}
	return max(ans, Max[s][0]);
}
int main() {

	int n, m;
	while (scanf("%d%d", &n, &m) != EOF) {
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			par[i] = i;
			size[i] = 1;
		}
		l = ceil(log2(n));
		cnt = 0;
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edge[i].first = w;
			edge[i].second.first = u - 1;
			edge[i].second.second = v - 1;
		}
		sort(edge, edge + m);
		for (int i = 0; i < m; ++i)
			join(edge[i].second.first, edge[i].second.second, edge[i].first);
		dfs(0, 0, 0);
		int q;
		scanf("%d", &q);
		while (q--) {
			int s, t, ans;
			scanf("%d%d", &s, &t);
			s--, t--;
			if (ancestor(s, t))
				ans = solve(t, s);
			else if (ancestor(t, s))
				ans = solve(s, t);
			else {
				ans = solve(s, t);
				ans = max(ans, solve(t, s));
			}
			printf("%d\n", ans);
		}
		printf("\n");
	}
}
