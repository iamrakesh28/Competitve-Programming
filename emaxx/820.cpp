#include <bits/stdc++.h>

#define N 100
using namespace std;

const int inf = 1e9;
int capacity[N][N];
list <int> adj[N];

int bfs(int s, int t, vector <int> &parent) {

	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue <pair <int, int>> q;
	q.push({s, inf});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (auto next : adj[cur]) {
			if (parent[next] == -1 && capacity[cur][next]) {
				parent[next] = cur;
				int net_flow = min(flow, capacity[cur][next]);
				if (next == t)
					return net_flow;
				q.push({next, net_flow});
			}
		}
	}
	return 0;
}
int maxflow(int s, int t, int n) {

	int flow = 0, net_flow;
	vector <int> parent(n);
	while (net_flow = bfs(s, t, parent)) {
		flow += net_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			capacity[prev][cur] -= net_flow;
			capacity[cur][prev] += net_flow;
			cur = prev;
		}
	}
	return flow;
}
int main() {
	int n, cnt = 0;
	while (scanf("%d", &n) != EOF && n) {
		
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			for (int j = 0; j < n; ++j)
				capacity[i][j] = 0;
		}
		int s, t, c;
		scanf("%d%d%d", &s, &t, &c);
		for (int i = 0; i < c; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			if (capacity[u - 1][v - 1]) {
				capacity[u - 1][v - 1] += w;
				capacity[v - 1][u - 1] = capacity[u - 1][v - 1];
				continue;
			}
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
			capacity[u - 1][v - 1] = w;
			capacity[v - 1][u - 1] = w;
		}
		printf("Network %d\nThe bandwidth is %d.\n\n", cnt + 1, maxflow(s - 1, t - 1, n));
		cnt++;
	}
}
