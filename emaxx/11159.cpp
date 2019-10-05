#include <bits/stdc++.h>

using namespace std;

list <int> adj[202];
int A[100], B[100], cap[202][202];

int bfs(int s, int t, vector <int> &parent) {

	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue <pair <int, int>> q;
	q.push({s, 1e9});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (int next : adj[cur]) {
			if (cap[cur][next] && parent[next] == -1) {
				int net_flow = min(flow, cap[cur][next]);
				parent[next] = cur;
				if (next == t)
					return net_flow;
				q.push({next, net_flow});
			}
		}
	}
	return 0;
}
int maxflow(int s, int t, int n) {

	int flow = 0;
	vector <int> parent(n);
	int net_flow;
	while (net_flow = bfs(s, t, parent)) {
		flow += net_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			cap[cur][prev] += net_flow;
			cap[prev][cur] -= net_flow;
			cur = prev;
		}
	}
	return flow;
}
int main() {

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n, m, s = 0 , t;
		scanf("%d", &n);
		for (int j = 0; j < n; ++j) {
			scanf("%d", A + j);
			cap[s][j + 1] = 1;
			adj[s].push_back(j + 1);
			adj[j + 1].push_back(s);
		}
		scanf("%d", &m);
		t = n + m + 1;
		for (int j = 0; j < m; ++j) {
			scanf("%d", B + j);
			cap[j + n + 1][t] = 1;
			adj[t].push_back(j + n + 1);
			adj[j + n + 1].push_back(t);
		}
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < m; ++k) {
				if (!A[j] && B[k])
					continue;
				if (B[k] == 0 || B[k] % A[j] == 0) {
					cap[j + 1][n + k + 1] = 1;
					adj[j + 1].push_back(k + n + 1);
					adj[k + n + 1].push_back(j + 1);	
				}
			}
		printf("Case %d: %d\n", i + 1, maxflow(s, t, n + m + 2));
		for (int j = 0; j < n + m + 2; j++) {
			adj[j].clear();
			memset(cap[j], 0, sizeof(int) * (n + m + 2));
		}
	}
}
