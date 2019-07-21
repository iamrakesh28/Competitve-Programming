#include <bits/stdc++.h>

using namespace std;

vector <int> par, size, dist;
vector <pair <int, pair <int, int>>> edge;
vector < vector <int>> mat;
list <pair <int, int>> adj[2000];

int find(int u) {

	if (u == par[u])
		return u;
	return find(par[u]);
}

void join(int u, int v, int w) {

	int x = find(u), y = find(v);
	if (x == y)
		return;
	if (size[x] > size[y]) {
		size[x] += size[y];
		par[y] = x;
	}
	else {
		size[y] += size[x];
		par[x] = y;
	}
	adj[u].push_back({w, v});
	adj[v].push_back({w, u});
	return;
}

void dfs(int u, int p) {

	for (auto it : adj[u]) {
		if (it.second != p) {
			dist[it.second] = dist[u] + it.first;
			dfs(it.second, u);
		}
	}
}
int main() {

	int n;
	scanf("%d", &n);
	par.resize(n);
	dist.resize(n);
	size.resize(n);
	edge.resize(n * n);
	mat.resize(n, vector <int> (n));
	bool tree = true;
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		size[i] = 1;
		for (int j = 0; j < n; ++j) {
			int d;
			scanf("%d", &d);
			if (i != j && d == 0) {
				printf("NO\n");
				return 0;
			}
			edge[i * n + j].first = d;
			edge[i * n + j].second.second = j;
			edge[i * n + j].second.first = i;
			mat[i][j] = d;
		}
	}
	sort(edge.begin(), edge.end());
	for (int i = 0; i < n * n; ++i)
		join(edge[i].second.first, edge[i].second.second, edge[i].first);
	for (int i = 0; i < n; ++i) {
		dist[i] = 0;
		dfs(i, i);
		for (int j = 0; j < n; ++j) {
			if (dist[j] != mat[i][j]) {
				tree = false;
				break;	
			}
		}
		if (!tree)
			break;
	}
	if (tree)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}
