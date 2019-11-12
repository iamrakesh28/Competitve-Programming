#include <bits/stdc++.h>

#define N 300000
using namespace std;

list <int> adj[N];
long long path[N], pre[N], size[N];
int n, timer, l, cur_pos, pos[N], heavy[N], parent[N], head[N], tin[N], tout[N], up[N][20];

int dfs(int u, int p) {
	
	int cnt = 1, s = 0;
	long long prod = 0;
	tin[u] = timer++;
	up[u][0] = p;
	for (int i = 1; i <= l; ++i)
		up[u][i] = up[up[u][i - 1]][i - 1];
	for (int v : adj[u]) {
		if (v != p) {
			parent[v] = u;
			int tree = dfs(v, u);
			cnt += tree;
			if (s < tree)
				s = tree, heavy[u] = v;
			prod += size[v] * (n - size[v] - 1);
		}
	}
	size[u] = cnt;
	prod += (n - size[u]) * (size[u] - 1);
	path[u] = prod / 2;
	tout[u] = timer++;
	return cnt;
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

void decompose(int u, int h) {

	long long ans = path[u] + size[u], a, b;
	head[u] = h, pos[u] = cur_pos++;
	if (heavy[u] != -1) {
		b = size[heavy[u]];
		ans -= b * (n - b - 1);
		a = n - size[u];
		ans -= a * (size[u] - 1);
		ans += a * b;
		ans -= size[heavy[u]];
		if (pos[u])
			pre[pos[u]] = pre[pos[u] - 1] + ans;
		else
			pre[0] = ans;
		decompose(heavy[u], h);
	}
	else
		pre[pos[u]] = pre[pos[u] - 1] + ans;
	for (int v : adj[u]) {
		if (v != parent[u] && v != heavy[u]) {
			decompose(v, v);
		}
	}
	return ;
}
long long lef, righ;
long long solve(int u, int l) {

	long long ans = 0, a, b, lower = 0;
	while (u != l) {
		b = n - size[u];
		ans += path[u] + size[u];
		//cout<<lower<<endl;
		ans -= lower * (n - lower - 1);
		ans -= b * (size[u] - 1);
		ans += lower * b;
		ans -= lower;
		if (ancestor(l, parent[head[u]]) && parent[head[u]] != head[u]) {
			if (u != head[u]) {
				b = n - size[head[u]];
				ans += path[head[u]] + n;
				a = size[heavy[head[u]]];
				ans -= a * (n - a - 1);
				ans -= b * (n - b - 1);
				ans -= (a + b);
				ans += a * b;
				int s = pos[u] - 1, t = pos[head[u]];
				ans += pre[s] - pre[t];
				//cout<<ans<<" "<<path[head[u]] + size[head[u]]<<" "<<endl;
			}
			lower = size[head[u]];
			u = parent[head[u]];
			lef = lower;
		}
		else {
			int t = pos[l], s = pos[u] - 1;
			ans += pre[s] - pre[t];
			lef = size[heavy[l]];
			return ans;
		}
	}
	return ans;
}
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int q;
		scanf("%d%d", &n, &q);
		cur_pos = 0, timer = 0, l = ceil(log2(n));
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			heavy[i] = -1;
		}
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}
		parent[0] = 0;
		size[0] = dfs(0, 0);
		decompose(0, 0);
		while (q--) {
			int u, v, l;
			long long ans;
			scanf("%d%d", &u, &v);
			u--, v--;
			l = lca(u, v);
			lef = 0, righ = 0;
			if (l == u || l == v) {
				if (l == u)
					u = v;
				ans = solve(u, l);
				//cout<<size[l]<<endl;
				ans += path[l] + n;
				ans -= lef * (n - lef - 1);
				ans -= lef;
			}
			else {
				ans = solve(u, l);
				righ = lef;
				ans += solve(v, l);
				//cout<<ans-2<<endl;
				ans += path[l] + n;
				ans -= lef * (n - lef - 1);
				ans -= righ * (n - righ - 1);
				ans += lef * righ;
				ans -= (lef + righ);
			}
			assert(ans>=0);
			printf("%lld\n", ans);
		}
	}
}
