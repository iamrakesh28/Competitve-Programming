#include <bits/stdc++.h>

using namespace std;

const int maxm = 1e5;
pair <int, pair <int, int>> edge[maxm];
int par[3000], size[3000], visit[3000];
list <pair <int, int>> adj[3000];

int find(int u) 
{
	if (u == par[u])
		return u;
	return find(par[u]);
}

void Union(int u, int v, int w)
{
	int u1 = u, v1 = v;
	u = find(u);
	v = find(v);
	if (u == v)
		return;
	if (size[u] > size[v]) {
		par[v] = u;
		size[u] += size[v];
	}
	else {
		par[u] = v;
		size[v] += size[u];
	}
	adj[u1].push_back(make_pair(w, v1));
	adj[v1].push_back(make_pair(w, u1));
}

int dfs(int u, int y, int parent)
{
	for (auto it : adj[u]) {
		if (it.second != parent) {
			if (it.second == y)
				return it.first;
			int val = dfs(it.second, y, u);
			if (val != -1)
				return max(val, it.first);
		}
	}
	return -1;
}

int main()
{
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) {
			int a, b, w;
			scanf("%d%d%d", &a, &b, &w);
			edge[i].first = w;
			edge[i].second.first = a - 1;
			edge[i].second.second = b - 1;
		}
		sort(edge, edge + m);
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			size[i] = 1;
			adj[i].clear();
		}
		for (int i = 0; i < m; ++i)
			Union(edge[i].second.first, edge[i].second.second, edge[i].first);
		int t;
		scanf("%d", &t);
		printf("Case %d\n",i + 1);
		while (t--) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("%d\n",dfs(x - 1, y - 1, x - 1));
		}
		printf("\n");
	}
	return 0;
}
