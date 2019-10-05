#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
int h[101], dist[100];

list <pair <int, int>> adj[101];

bool bellman(int n) {
	
	int x;
	h[n] = 0;
	for (int i = 0; i < n; ++i) {
		x = -1;
		for (int j = 0; j <= n; ++j)
			for (auto it : adj[j])
				if (h[it.second] > h[j] + it.first) {
					h[it.second] = h[j] + it.first;
					x = it.second;
				}
	}
	if (x == -1)
		return true;
	return false;
		
}

void dijkstra(int s, int n) {

	for (int i = 0; i < n; ++i)
		dist[i] = inf;
	set <pair<int, int>> q;
	q.insert(make_pair(0, s));
	dist[s] = 0;
	while (!q.empty()) {
		
		auto p = *q.begin();
		q.erase(q.begin());
		int u = p.second;
		for (auto it : adj[u]) {
			if (dist[it.second] == inf) {
				dist[it.second] = dist[u] + it.first;
				q.insert(make_pair(dist[it.second], it.second));
			}
			else if (dist[it.second] > dist[u] + it.first) {
				q.erase(q.find(make_pair(dist[it.second], it.second)));
				dist[it.second] = dist[u] + it.first;
				q.insert(make_pair(dist[it.second], it.second));
			}
		}
	}
	return;
}
int main() {
	
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, m;
		scanf("%d%d", &n, &m);
		adj[n].clear();
		for (int j = 0; j < n; ++j) {
			adj[j].clear();
			adj[n].push_back(make_pair(0, j));
			h[j] = 0;
		}
		for (int j = 0; j < m; ++j) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			adj[u - 1].push_back(make_pair(w, v - 1));
		}
		if (bellman(n) == false) {
			printf("graph %d no\n\n", i + 1);
			continue;
		}
		printf("graph %d yes\n\n", i + 1);
		for (int j = 0; j <= n; ++j)
			printf("%d ", h[j]);
		printf("\n\n");
		for (int j = 0; j < n; ++j) {
			for (auto it = adj[j].begin(); it != adj[j].end(); ++it)
				(*it).first += h[j] - h[(*it).second];
		}
		for (int j = 0; j < n; ++j) {
			dijkstra(j, n);
			for (int k = 0; k < n; ++k) {
				if (dist[k] == inf)
					printf("# ");
				else
					printf("%d ", dist[k] - h[j] + h[k]);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}
