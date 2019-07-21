#include <bits/stdc++.h>

#define N 200005
using namespace std;

int l, cnt, tin[N], tout[N], up[N][20];
list <int> adj[N];

void dfs(int u, int p) {

	tin[u] = cnt++;
	up[u][0] = p;
	for (int i = 1; i <= l; ++i)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (auto it : adj[u]) {
		if (it != p)
			dfs(it, u);
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
int main() {

	int n, k;
	scanf("%d", &n);
	l = ceil(log2(n));
	cnt = 0;
	for (int i = 0; i < n - 1; ++i) {

		int a, b;
		scanf("%d%d", &a, &b);
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
	}
	dfs(0, 0);
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int r, u, v, ans, lc;
		scanf("%d%d%d", &r, &u, &v);
		u--, v--, r--;
		lc = lca(u, v);
		if (ancestor(lc, r) && lc != r) {
			int l1 = lca(r, u), l2 = lca(r, v);
			if (ancestor(l1, l2))
				ans = l2;
			else
				ans = l1;
		}
		else
			ans = lc;
		printf("%d\n", ans + 1);
	}
}
