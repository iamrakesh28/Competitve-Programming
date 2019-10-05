#include <bits/stdc++.h>

using namespace std;

list <int> *adj;
vector <long long> *suffix, *prefix;
long long *dp, *ans;
int n, m;

void dfs1(int u, int p) {

	prefix[u].push_back(1);
	int cnt = 0;
	long long prod = 1;
	for (int nxt : adj[u]) {
		if (nxt != p) {
			dfs1(nxt, u);
			prod = prod * (dp[nxt] + 1) % m;
			prefix[u].push_back(prefix[u][cnt] * (dp[nxt] + 1) % m);
		}
		else
			prefix[u].push_back(prefix[u][cnt]);
		cnt++;
	}
	cnt = 0;
	suffix[u].push_back(1);
	for (auto nxt = adj[u].rbegin(); nxt != adj[u].rend(); ++nxt) {
		if (*nxt != p)
			suffix[u].push_back(suffix[u][cnt] * (dp[*nxt] + 1) % m);
		else
			suffix[u].push_back(suffix[u][cnt]);
		cnt++;
	}
	dp[u] = prod;
}

void dfs2(int u, int p, long long val) {

	int cnt = 0;
	long long temp;
	for (int nxt : adj[u]) {
		if (nxt != p) {
			int len = suffix[u].size();
			temp = suffix[u][len - cnt - 2] * prefix[u][cnt] % m;
			temp = temp * val % m;
			ans[nxt] = dp[nxt] * (temp + 1) % m;
			//cout<<temp<<" "<<u<<" "<<nxt<<endl;
			dfs2(nxt, u, (temp + 1) % m);
		}
		cnt++;
	}
}

int main() {

	scanf("%d%d", &n, &m);
	adj = new list <int> [n];
	suffix = new vector <long long> [n];
	prefix = new vector <long long> [n];
	dp = new long long [n];
	ans = new long long [n];
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		adj[y - 1].push_back(x - 1);
		adj[x - 1].push_back(y - 1);
	}
	dfs1(0, 0);
	//cout<<dp[3]<<endl;
	ans[0] = dp[0];
	dfs2(0, 0, 1);
	for (int i = 0; i < n; ++i)
		printf("%lld\n", ans[i]);
	//delete adj, suffix, prefix, dp, ans;
	return 0;
}
