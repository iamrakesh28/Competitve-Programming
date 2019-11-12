#include <bits/stdc++.h>

#define N 100005
using namespace std;

const int inf = 1e9;
int arr[N], cap[2500][2500];
list <int> adj[2500];

int bfs(int s, int t, vector <int> &parent) {
	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue <pair <int, int>> q;
	q.push({s, inf});
	while (!q.empty()) {
		int cur = q.front().first;
		int flow = q.front().second;
		q.pop();
		//cout<<flow<<" "<<cur<<endl;
		for (int next : adj[cur])
			if (cap[cur][next] && parent[next] == -1) {
				parent[next] = cur;
				int net_flow = min(flow, cap[cur][next]);
				if (next == t)
					return net_flow;
				q.push({next, net_flow});
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
		//cout<<net_flow<<endl;
		if (net_flow >= 1e8)
			return net_flow;
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
	for (int i = 0; i < q; ++i) {
		int n, h, v, s, t;
		scanf("%d%d", &n, &h);
		vector <pair <int, pair <int, int>>> ladd(n);
		for (int j = 0; j < n; ++j) {
			int x, a, b;
			scanf("%d%d%d", &x, &a, &b);
			ladd[j] = {x, {a, b}};
		}
		sort(ladd.begin(), ladd.end());
		v = n;
		for (int j = 0; j < n; ++j) {
			int l = ladd[j].second.first, u = ladd[j].second.second;
			//cout<<ladd[j].first<<" "<<l<<" "<<u<<endl;
			for (int k = l - 1; k <= u; ++k)
				arr[k] = 0;
			for (int k = j + 1; k < n; ++k) {
				int w = 0;
				int high = min(u,ladd[k].second.second), low = max(l,ladd[k].second.first);
				if (l == 0 && ladd[k].second.first == 0)
					w = inf;
				else if (u == h && ladd[k].second.second == h)
					w = inf;
				else {
					for (int s = high; s > low; --s)
						if (arr[s - 1] == 0) {
							arr[s - 1] = 1;
							w++;
						}
				}
				//cout<<j<<" "<<k<<" "<<w<<" "<<min(u,ladd[k].second.second)<<" "<<max(l,ladd[k].second.first)<<endl;
				if (w == 0)
					continue;
				adj[j].push_back(k);
				adj[k].push_back(j);
				cap[j][k] = w;
				adj[k].push_back(v);
				adj[v].push_back(k);
				cap[k][v] = w;
				adj[j].push_back(v);
				adj[v].push_back(j);
				cap[v][j] = w;
				v++;
				for (int s = high; s > low; --s)
					arr[s - 1] = 1;
			}
		}
		s = v;
		v++;
		t = v++;
		for (int j = 0; j < n; ++j)
			if (ladd[j].second.first == 0) {
				adj[s].push_back(j);
				adj[j].push_back(s);
				cap[s][j] = inf;
				break;
			}
		for (int j = 0; j < n; ++j)
			if (ladd[j].second.second == h) {
				adj[j].push_back(t);
				adj[t].push_back(j);
				cap[j][t] = inf;
				break;
			}
		/*cout<<v<<endl;
		for (int j = 0; j < v; ++j) {
			for (int k = 0; k < v; ++k)
				cout<<cap[j][k]<<" ";
			cout<<endl;
		}*/
		int flow = maxflow(s, t, v);
		//cout<<flow<<endl;
		printf("Case #%d: ", i + 1);
		if (flow >= 1e8)
			flow = -1;
		printf("%d\n", flow);
		for (int j = 0; j < v; ++j) {
			adj[j].clear();
			for (int k = 0; k < v; ++k)
				cap[j][k] = 0;
		}
	}
	return 0;
}
