#include <bits/stdc++.h>

using namespace std;

list <int> adj[25], tree[25];
bool visit[25];
int dist, ind;

void bfs(int s) {

	visit[s] = true;
	queue <int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int next : adj[u])
			if (visit[next] == false) {
				visit[next] = true;
				tree[u].push_back(next);
				tree[next].push_back(u);
				q.push(next);
			}
	}
}

void dfs(int u, int p, int d) {

	for (int next : tree[u])
		if (next != p)
			dfs(next, u, d + 1);
	if (d > dist) {
		dist = d;
		ind = u;
	}
}
int main() {

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n, m, u, v;
		scanf("%d%d", &n, &m);
		for (int j = 0; j < n; ++j)
			adj[j].clear(), visit[j] = false;
		while (m--) {
			scanf("%d%d", &u, &v);
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int trail = 1e9;
		for (int j = 1; j < n; ++j) {
			bfs(j);
			dist = -1;
			dfs(j, j, 0);
			dfs(ind, ind, 0);
			trail = min(trail, dist);
			for (int k = 0; k < n; ++k)
				tree[k].clear(), visit[k] = false;
		}
		printf("Case #%d:\n%d\n\n", i + 1, trail);
	}
	return 0;
}
