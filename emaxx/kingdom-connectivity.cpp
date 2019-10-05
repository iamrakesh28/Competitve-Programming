#include <bits/stdc++.h>

using namespace std;

const int m = 1e9;
vector <int> temp[10000], rev[10000];
vector <pair <int, int>> adj[10000];
bool visit[10000], cmp[10000], reach[10000];
int cycle[10000];
long long dp[10000];

void dfs1(int u) {

	reach[u] = true;
	cycle[u] = 1;
	for (auto it : temp[u]) {
		if (cycle[it] == 1)
			cmp[it] = true;
		else if (cycle[it] == 0)
			dfs1(it);
	}
	cycle[u] = 2;
}

bool dfs2(int u) {

	visit[u] = true;
	bool ret = true;
	if (cmp[u] == true)
		ret = false;
	for (auto it : rev[u]) {
		if (visit[it] == false && reach[it] == true)
			ret = ret && dfs2(it);
	}
	return ret;
}
void solve(int u, int n) {
	visit[u] = true;
	if (u == n - 1)
		dp[u] = 1;
	else
		dp[u] = 0;
	for (auto it : adj[u]) {
		if (visit[it.first] == false)
			solve(it.first, n);
		//cout<<u+1<<" "<<it.first+1<<endl;
		dp[u] = (dp[u] + it.second * dp[it.first]) % m;
	}
}

int main() {

	int n, m;
	scanf("%d%d", &n, &m);
	while (m--) {
		int u, v;
		scanf("%d%d", &u, &v);
		temp[--u].push_back(--v);
		rev[v].push_back(u);
	}
	for (int i = 0; i < n; ++i) {
		cycle[i] = 0;
		reach[i] = cmp[i] = false;
	}
	dfs1(0);
	if (reach[n - 1] == false) {
		puts("0");
		return 0;
	}
	memset(visit, false, sizeof(bool) * n);
	bool check = dfs2(n - 1);
	if (check == false) {
		puts("INFINITE PATHS");
		return 0;
	}
	for (int i = 0; i < n; ++i) {
		if (reach[i] == false)
			continue;
		sort(temp[i].begin(), temp[i].end());
		int s = temp[i].size();
		if (s == 0)
			continue;
		int cnt = 1, prev = temp[i][0];
		for (int j = 1; j < s; ++j) {
			if (prev != temp[i][j]) {
				adj[i].push_back({prev, cnt});
				cnt = 1, prev = temp[i][j];
			}
			else
				cnt++;
		}
		adj[i].push_back({prev, cnt});
	}
	memset(visit, false, sizeof(bool) * n);
	solve(0, n);
	printf("%lld\n", dp[0]);
	return 0;
}
