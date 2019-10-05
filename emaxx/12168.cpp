#include <bits/stdc++.h>

#define V 500
using namespace std;

list <int> adj[V + 2];
int cap[V + 2][V + 2];
char cat[V][6], dog[V][6];

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
		int c, d, v, s = 0, t;
		scanf("%d%d%d", &c, &d, &v);
		t = v + 1;
		for (int i = 0; i < v; ++i)
			scanf("%s%s", cat[i], dog[i]);
		for (int i = 0; i < v; ++i)
				for (int j = i + 1; j < v; ++j) {
					if (strcmp(cat[i], dog[j]) == 0 || strcmp(cat[j], dog[i]) == 0) {
						int u, v;
						if (cat[i][0] == 'C')
							u = i + 1, v = j + 1;
						else
							u = j + 1, v = i + 1;						
						cap[u][v] = 1;
						adj[u].push_back(v);
						adj[v].push_back(u);
						cap[s][u] = 1;
						adj[s].push_back(u);
						adj[u].push_back(s);
						cap[v][t] = 1;
						adj[v].push_back(t);
						adj[t].push_back(v);
					}
				}
		printf("%d\n",v - maxflow(s, t, v + 2));
		for (int i = 0; i < v + 2; ++i) {
			memset(cap[i], 0, sizeof(int) * (v + 2));
			adj[i].clear();
		}
	}	
	return 0;
}
