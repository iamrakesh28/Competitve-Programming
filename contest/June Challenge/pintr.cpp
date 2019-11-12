#include <bits/stdc++.h>

#define N 300000
using namespace std;

list <int> adj[N];
long long path[N];
vector <long long> sub[N];
int size[N], n;
bool visit[N];

int dfs(int u, int p) {
	
	int cnt = 1, ind = -1, i = 0;
	for (int v : adj[u]) {
		if (v != p) {
			int tree = dfs(v, u);
			cnt += tree;
			sub[u].push_back(tree);
		}
		else {
			ind = i;
			sub[u].push_back(0);
		} 
		i++;
	}
	if (ind != -1)
		sub[u][ind] = n - cnt;
	long long prod = 0;
	i = 0;
	for (int v : adj[u]) {
		prod += sub[u][i] * (n - sub[u][i] - 1);
		i++;
	}
	path[u] = prod / 2;
	size[u] = cnt;
	return cnt;
}

bool dfs1(int u, int p, int x) {
	if (u == x) {
		visit[x] = true;
		return true;
	}
	for (int v : adj[u]) {
		if (v != p) {
			if (dfs1(v, u, x)) {
				visit[v] = true;
				return true;
			}
		}
	}
	return false;
}
long long solve(int u, int p, int x, int y) {

	long long ans = 0, a = 0, b = 0;
	int i = 0;
	ans = path[u] + 1;
	for (int v : adj[u]) {
		if (v != p && visit[v] == true) {
			ans += solve(v, u, x, y);
			b = sub[u][i];
			ans -= b * (n - b - 1);
		}
		else if (v != p)
			ans += sub[u][i];
		else {
			a = sub[u][i];
			ans -= a * (n - a - 1);
		}
		i++;
	}
	ans += a * b;
	//cout<<ans<<" "<<u + 1<<" "<<a<<" "<<b<<endl;
	return ans;
}
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int q;
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; ++i) {
			adj[i].clear();
			visit[i] = false;
			sub[i].clear();
		}
		for (int i = 0; i < n - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}
		size[0] = dfs(0, 0);
		while (q--) {
			int u, v;
			scanf("%d%d", &u, &v);
			memset(visit, false, sizeof(bool) * n);
			bool f = dfs1(u - 1, u - 1, v - 1);
			printf("%lld\n", solve(u - 1, u - 1, u - 1, v - 1));
		}
	}
}

