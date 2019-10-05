#include <bits/stdc++.h>

using namespace std;

char mat[40][41];
int ant[40][40], cap[1600][1600], dy[] = {-1, 1, 0, 0}, dx[] = {0, 0, -1, 1};
list <int> adj[1600];

bool valid(int i, int j, int n, int m) {
	return i >= 0 && j >= 0 && i < n && j < m;
}
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
	while (q--) {
		int h, w, cnt = 0, s = 0, t;
		scanf("%d%d", &h, &w);
		for (int i = 0; i < h; ++i) {
			for (int j = 0; j < w; ++j) {
				scanf(" %c", mat[i] + j);
				if (mat[i][j] == '*')
					ant[i][j] = cnt++;
			}
		}
		t = cnt + 1;
		for (int i = 0; i < h; ++i)
			for (int j = 0; j < w; ++j)
				if (mat[i][j] == '*' && (i + j) % 2) {
					int u = ant[i][j] + 1;
					adj[u].push_back(s);
					adj[s].push_back(u);
					cap[s][u] = 1;
					for (int d = 0; d < 4; ++d) {
						int r = dy[d] + i, c = dx[d] + j;
						if (valid(r, c, h, w) && mat[r][c] == '*') {
							adj[u].push_back(ant[r][c] + 1 );
							adj[ant[r][c] + 1].push_back(u);
							cap[u][ant[r][c] + 1] = 1;
							adj[t].push_back(ant[r][c] + 1 );
							adj[ant[r][c] + 1].push_back(t);
							cap[ant[r][c] + 1][t] = 1;
						}
					}
				}
		printf("%d\n", cnt - maxflow(s, t, cnt + 2));
		for (int i = 0; i <= cnt; ++i) {
			adj[i].clear();
			memset(cap[i], 0, sizeof(int) * (cnt + 2));
		}
	}
	return 0;
}
