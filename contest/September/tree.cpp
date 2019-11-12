#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
const long long inf = 1e14;
long long dp[N][2], B[N], ans[N][2];
vector <long long> suffix[N][2], prefix[N][2];
list <int> adj[N];

void dfs1(int u, int p) {
 
	prefix[u][0].push_back(0);
	prefix[u][1].push_back(0);
	int cnt = 0;
	dp[u][0] = 0;
	dp[u][1] = B[u];
	long long val = inf;
	for (int nxt : adj[u]) {
		if (nxt != p) {
			dfs1(nxt, u);
			dp[u][1] += max(dp[nxt][0] + B[nxt], dp[nxt][1]);
			dp[u][0] += max(dp[nxt][0], dp[nxt][1] + B[u]);
			prefix[u][0].push_back(prefix[u][0][cnt] + max(dp[nxt][0], dp[nxt][1] + B[u]));
			prefix[u][1].push_back(prefix[u][1][cnt] + max(dp[nxt][0] + B[nxt], dp[nxt][1]));
		}
		else {
			prefix[u][0].push_back(prefix[u][0][cnt]);
			prefix[u][1].push_back(prefix[u][1][cnt]);
		}
		cnt++;
	}
	cnt = 0;
	suffix[u][0].push_back(0);
	suffix[u][1].push_back(0);
	for (auto nxt = adj[u].rbegin(); nxt != adj[u].rend(); ++nxt) {
		if (*nxt != p) {
			suffix[u][0].push_back(suffix[u][0][cnt] + max(dp[*nxt][0], dp[*nxt][1] + B[u]));
			suffix[u][1].push_back(suffix[u][1][cnt] + max(dp[*nxt][0] + B[*nxt], dp[*nxt][1]));
		}
		else {
			suffix[u][0].push_back(suffix[u][0][cnt]);
			suffix[u][1].push_back(suffix[u][1][cnt]);
		}
		cnt++;
	}
	return;
}

void dfs2(int u, int p, long long val0, long long val1) {
 
	int cnt = 0;
	long long temp;
	for (int nxt : adj[u]) {
		if (nxt != p) {
			int len = suffix[u].size();
			temp = max(suffix[u][0][len - cnt - 2] + prefix[u][0][cnt], suffix[u][1][len - cnt - 2] + prefix[u][1][cnt]);
			ans[nxt][1] = temp;
			ans[nxt] = dp[nxt] * (temp + 1) % m;
			//cout<<temp<<" "<<u<<" "<<nxt<<endl;
			dfs2(nxt, u, (temp + 1) % m);
		}
		cnt++;
	}
}

int main() {
	
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int v;
		scanf("%d", &v);
		for (int i = 0; i < v; ++i) {
			scanf("%d", B + i);
			adj[i].clear();
			suffix[i][0].clear();
			prefix[i][0].clear();
			suffix[i][1].clear();
			prefix[i][1].clear();
		}
		for (int i = 0; i < v - 1; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			adj[u - 1].push_back(v - 1);
			adj[v - 1].push_back(u - 1);
		}
		dfs1(0, 0);
		ans[0] = dp[0];
		dfs2(0, 0, 1);
	}
	return 0;
}
