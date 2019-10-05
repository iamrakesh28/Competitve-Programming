#include <bits/stdc++.h>

#define N 100
using namespace std;

const int eps = 1e-9;
int xn[N], yN[N], xm[N], ym[N], cap[2 * N + 1][2 * N + 1];
list <int> adj[2 * N + 1];

double euclid(int x, int y) {
	return sqrt(x * x + y * y);
}

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

int maxflow(int s, int t, int n) {
	vector <int> parent(n);
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

	int l;
	scanf("%d", &l);
	while (l--) {
		int n, m, s, t;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", xn + i, yN + i);
		for (int i = 0; i < m; ++i)
			scanf("%d%d", xm + i, ym + i);
		s = 0, t = n + m;
		for (int i = 1; i < n; ++i) {
			double dist = euclid(xn[i] - xn[i - 1], yN[i] - yN[i - 1]);
			for (int j = 0; j < m; ++j)
				if (euclid(xn[i - 1] - xm[j], yN[i - 1] - ym[j]) + euclid(xn[i] - xm[j], yN[i] - ym[j]) <= 2 * dist) {
				adj[i].push_back(n + j);
				adj[n + j].push_back(i);
				cap[i][n + j] = 1;
				adj[t].push_back(n + j);
				adj[n + j].push_back(t);
				cap[n + j][t] = 1;
				adj[i].push_back(s);
				adj[s].push_back(i);
				cap[s][i] = 1;
			}
		}
		printf("%d\n", maxflow(s, t, t + 1) + n);
		printf("%d %d ", xn[0], yN[0]);
		for (int i = 1; i < n; ++i) {
			for (int next : adj[i])
				if (cap[i][next] == 0 && next != s)
					printf("%d %d ", xm[next - n], ym[next - n]);
			if (i != n - 1)
				printf("%d %d ", xn[i], yN[i]);
			else
				printf("%d %d", xn[i], yN[i]);
		}
		puts("\n");
		for (int i = 0; i <= t; ++i) {
			adj[i].clear();
			memset(cap[i], 0, sizeof(int) * (t + 1));
		}
	}
	return 0;
}
