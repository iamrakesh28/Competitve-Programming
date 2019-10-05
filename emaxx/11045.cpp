#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;
list <int> adj[38];
int cap[38][38];

int bfs(int s, int t, vector <int> &parent) {

	fill(parent.begin(), parent.end(), -1);
	parent[s] = -2;
	queue <pair <int, int>> q;
	q.push({s, inf});
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
	map <string, int> mp;
	mp["XXL"] = 0;
	mp["XL"] = 1;
	mp["L"] = 2;
	mp["M"] = 3;
	mp["S"] = 4;
	mp["XS"] = 5;
	while (q--) {
		int n, m, s, t;
		scanf("%d%d", &n, &m);
		s = 0, t = m + 7;
		for (int i = 0; i < m; ++i) {
			string a, b;
			cin>>a>>b;
			adj[s].push_back(i + 1);
			adj[i + 1].push_back(s);
			cap[s][i + 1] = 1;
			int u = mp.at(a);
			adj[i + 1].push_back(m + 1 + u);
			adj[m + 1 + u].push_back(i + 1);
			cap[i + 1][m + 1 + u] = 1;
			adj[t].push_back(m + 1 + u);
			adj[m + 1 + u].push_back(t);
			cap[m + 1 + u][t] = n / 6;
			u = mp.at(b);
			adj[i + 1].push_back(m + 1 + u);
			adj[m + 1 + u].push_back(i + 1);
			cap[i + 1][m + 1 + u] = 1;
			adj[t].push_back(m + 1 + u);
			adj[m + 1 + u].push_back(t);
			cap[m + 1 + u][t] = n / 6;
			
		}
		//cout<<q<<" "<<n<<" "<<m<<endl;
		if (m == maxflow(s, t, m + 8)) 
			printf("YES\n");
		else
			printf("NO\n");
		for (int i = 0; i < m + 8; ++i) {
			adj[i].clear();
			memset(cap[i], 0, sizeof(int) * (m + 8));
		}
	}
	return 0;
}
