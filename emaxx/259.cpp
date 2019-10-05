#include <bits/stdc++.h>

#define N 38
using namespace std;

const int inf = 1e9;
int capacity[N][N], s = 36, t = 37;
list <int> adj[N];

// s -> 36, t -> 37

int bfs(vector <int> &parent) {

	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue <pair <int, int>> q;
	q.push({s, inf});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();

		for (int next : adj[cur]) {
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
void maxflow(int req, vector <int> & temp) {
	int flow = 0;
	vector <int> parent(N);
	int net_flow;

	while (net_flow = bfs(parent)) {
		flow += net_flow;
		int cur = t;
		while (cur != s) {
			int prev = parent[cur];
			capacity[prev][cur] -= net_flow;
			capacity[cur][prev] += net_flow;
			cur = prev;
		}
	}
	if (flow < req)
		puts("!");
	else {
		int ans[10];
		for (int i = 0; i < 10; ++i)
			ans[i] = -1;
		for (auto v : temp) {
			for (auto it : adj[v]) {
				if (it == s)
					continue;
				if (capacity[it][v])
					ans[it - 26] = v;
			}
		}
		for (int i = 0; i < 10; ++i)
			if (ans[i] == -1)
				putchar('_');
			else
				putchar('A' + ans[i]);
		printf("\n");
	}
}
int main() {
	
	char line[128];
	int req = 0;
	vector <int> temp;
	while (scanf("%[^\n]s", line) != EOF) {
		char l = getchar_unlocked();
		if (strlen(line) == 0) {
			maxflow(req, temp);
			temp.clear();
			for (int i = 0; i < N; ++i) {
				adj[i].clear();
				for (int j = 0; j < N; ++j)
					capacity[i][j] = 0;
			}		
			req = 0;
			continue;
		}
		int u = line[0] - 'A';
		temp.push_back(u);
		adj[s].push_back(u);
		adj[u].push_back(s);
		capacity[s][u] = line[1] - '0';
		req += line[1] - '0';
		for (char *p = line + 3; *p != ';'; ++p) {
			int v = *p - '0' + 26;
			adj[u].push_back(v);
			adj[v].push_back(u);
			capacity[u][v] = 1;
			adj[v].push_back(t);
			adj[t].push_back(v);
			capacity[v][t] = 1;
		}
		line[0] = '\0';
	}
	maxflow(req, temp);
}
