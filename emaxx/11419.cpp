#include <bits/stdc++.h>

#define N 1000
using namespace std;

int cap[2 * N + 2][2 * N + 2];
list <int> adj[2 * N + 2];


int bfs(int s, int t, vector <int> &parent) {

	fill(parent.begin(), parent.end(), -1);
	queue <pair <int, int>> q;
	parent[s] = -2;
	q.push({s, 1e9});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		for (int next : adj[cur])
			if (cap[cur][next] && parent[next] == -1) {
				int net_flow = cap[cur][next];
				net_flow = min(net_flow, flow);
				parent[next] = cur;
				if (next == t)
					return net_flow;
				q.push({next, net_flow});
			}
	}
	return 0;
}

int maxflow(int s, int t, vector <int> &parent) {
	int flow = 0;
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

	int r, c, n, s, t;
	while (scanf("%d%d%d", &r, &c, &n) != EOF && (r || c || n)) {
		s = 0, t = r + c + 1;
		int x, y;
		for (int i = 0; i < r; ++i) {
			adj[i + 1].push_back(s);
			adj[s].push_back(i + 1);
			cap[s][i + 1] = 1;
		}
		for (int i = 0; i < n; ++i) {
			scanf("%d%d", &x, &y);
			adj[x].push_back(y + r);
			adj[r + y].push_back(x);
			cap[x][y + r] = 1;
			adj[t].push_back(y + r);
			adj[y + r].push_back(t);
			cap[y + r][t] = 1;
		}
		vector <int> parent(r + c + 2);
		printf("%d ", maxflow(s, t, parent));
		x = bfs(s, t, parent);
		for (int i = 0; i < r; ++i) {
			if (parent[i + 1] == -1)
				printf("r%d ", i + 1);
		}
		for (int i = 0; i < c; ++i)
			if (parent[i + 1 + r] != -1)
				printf("c%d ", i + 1);
		printf("\n");
		for (int i = 0; i < r + c + 2; ++i) {
			adj[i].clear();
			memset(cap[i], 0, sizeof(int) * (r + c + 2));
		}
	}
	return 0;
}
