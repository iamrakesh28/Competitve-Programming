#include <bits/stdc++.h>

#define N 100000
using namespace std;

int l, cnt, tin[N], tout[N], up[N][18], Max[N][18], Min[N][18];
list <pair <int, int>> adj[N];

void dfs(int u, int p, int w) {

	tin[u] = cnt++;
	up[u][0] = p;
	if (u == p) {
		Max[u][0] = INT_MIN, Min[u][0] = INT_MAX;
	}
	else
		Max[u][0] = Min[u][0] = w;
	for (int i = 1; i <= l; ++i) {
		up[u][i] = up[up[u][i - 1]][i - 1];
		Max[u][i] = max(Max[u][i - 1], Max[up[u][i - 1]][i - 1]);
		Min[u][i] = min(Min[u][i - 1], Min[up[u][i - 1]][i - 1]);
	}
	for (auto it : adj[u]) {
		if (it.second != p)
			dfs(it.second, u, it.first);
	}
	tout[u] = cnt++;
}

bool ancestor(int u, int v) {

	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

pair <int, int> ans(int u, int v) {

	int mi = INT_MAX, ma = INT_MIN, u1 = u;
	if (!ancestor(u,v)) {
		for (int i = l; i >= 0; i--) {
			if (!ancestor(up[u][i], v)) {
				mi = min(Min[u][i], mi);
				ma = max(Max[u][i], ma);
				u = up[u][i];
			}
		}
		//if (Min[u][0])
		mi = min(mi, Min[u][0]);
		ma = max(ma, Max[u][0]);
		u = u1;
	}
	if (!ancestor(v, u)) {
		for (int i = l; i >= 0; i--) {
			if (!ancestor(up[v][i], u)) {
				mi = min(Min[v][i], mi);
				ma = max(Max[v][i], ma);
				v = up[v][i];
			}
		}
		//if (Min[v][0])
		mi = min(mi, Min[v][0]);
		ma = max(ma, Max[v][0]);
	}
	return {mi, ma};
}
int main() {

	int n, k;
	scanf("%d", &n);
	l = ceil(log2(n));
	cnt = 0;
	for (int i = 0; i < n - 1; ++i) {

		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a - 1].push_back({c, b - 1});
		adj[b - 1].push_back({c, a - 1});
	}
	dfs(0, 0, 0);
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		u--, v--;
		auto it = ans(u, v);
		printf("%d %d\n", it.first, it.second);
	}
}
