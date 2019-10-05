#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
list <int> adj[36];
int cap[36][36];

int bfs(int s, int t, vector <int> &parent) {

	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue <pair <int, int>> q;
	q.push({s, inf});
	while (!q.empty()) {
		int u = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (int it : adj[u]) {
	
			if (cap[u][it] && parent[it] == -1) {
				int net_flow = min(flow, cap[u][it]);
				parent[it] = u;
				if (it == t)
					return net_flow;
				q.push({it, net_flow});
				
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
			cap[prev][cur] -= net_flow;
			cap[cur][prev] += net_flow; 
			cur = prev;
		}
	}
	return flow;
}
int main() {

	int q;
	scanf("%d", &q);
	for (int r = 0; r < q; ++r) {
		int n, m, s, t;
		scanf("%d%d", &n, &m);
		s = 0, t = n + m;
		for (int i = 0; i < n; ++i) {
			int x;
			scanf("%d", &x);
			for (int j = 0; j < x; ++j) {
				int tick;
				scanf("%d", &tick);
				cap[i][tick + n - 1]++;
			}
		}
		for (int i = 0; i < m; ++i) {
			cap[i + n][t] = 1;
			adj[i + n].push_back(t);
			adj[t].push_back(i + n);
			if (cap[0][i + n]) {
				adj[0].push_back(i + n);
				adj[0 + n].push_back(0);
			}
		}
		for (int i = 1; i < n; ++i) {
			for (int k = 0; k < m; ++k) {
				if (cap[i][k + n]) {
					cap[i][k + n]--;
					if (cap[i][k + n]) {
						adj[i].push_back(k + n);
						adj[k + n].push_back(i);
					}
				}
				else {
					adj[i].push_back(k + n);
					adj[k + n].push_back(i);
					cap[k + n][i] = 1;
				}
			}
		}
		printf("Case #%d: %d\n", r + 1, maxflow(s, t, n + m + 1));
		for (int i = 0; i <= n + m; ++i) {
			adj[i].clear();
			memset(cap[i], 0, sizeof(int) * (n + m + 1));
		}
	}
	return 0;
}
