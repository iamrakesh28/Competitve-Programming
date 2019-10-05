#include <bits/stdc++.h>

#define N 1025
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
void maxflow(int s, int t, int n, int req, int nk) {

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
	if (req != flow) {
		printf("0\n");
		return;
	}
	printf("1\n");
	for (int i = 0; i < nk; ++i) {
		for (auto it : adj[i]) {
			if (it == t)
				continue;
			if (capacity[i][it])
				printf("%d ", it - nk + 1);
		}
		printf("\n");
	}
	return ;
}
int main() {
	int nk, np, s, t, req;
	while (scanf("%d%d", &nk, &np) != EOF && (nk || np)) {
		// nk, np, s, t
		s = nk + np;
		t = s + 1;
		req = 0;
		for (int i = 0; i <= t; ++i) {
			adj[i].clear();
			for (int j = 0; j <= t; ++j)
				capacity[i][j] = 0;
		}
		for (int i = 0; i < nk; ++i) {
			int cat;
			scanf("%d", &cat);
			adj[i].push_back(t);
			adj[t].push_back(i);
			capacity[i][t] = cat;
			req += cat;
		}
		for (int i = 0; i < np; ++i) {
			int d, v;
			scanf("%d", &d);
			adj[s].push_back(i + nk);
			adj[i + nk].push_back(s);
			capacity[s][i + nk] = 1;
			for (int j = 0; j < d; ++j) {
				scanf("%d", &v);
				adj[i + nk].push_back(v - 1);
				adj[v - 1].push_back(i + nk);
				capacity[i + nk][v - 1] = 1;
			}
		}
		maxflow(s, t, t + 1, req, nk);
	}
}
