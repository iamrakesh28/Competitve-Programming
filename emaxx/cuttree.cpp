#include <iostream>
#include <vector>

using namespace std;

int n, k;
vector <int> adj[50];
long long dp[51][51], temp[51][51];

void dfs(int u, int p) {
	
	vector <int> arr;
	for (int it : adj[u]) {
		if (it != p) {
			dfs(it, u);
			arr.push_back(it);
		}
	}
	int len = arr.size();
	for (int i = 0; i <= len; ++i) {
		for (int j = 0; j <= k; ++j) {
			if (i == 0) {
				if (j == 0)
					temp[i][j] = 1;
				else
					temp[i][j] = 0;
				continue;
			}
			temp[i][j] = 0;
			for (int m = 0; m <= j; ++m)
				temp[i][j] += dp[arr[i - 1]][m] * temp[i - 1][j - m];
		}
	}
	if (len)
		dp[u][1]++;
	for (int i = 0; i <= k; ++i)
		dp[u][i] += temp[len][i];//, cout<<u+1<<" "<<i<<" "<<dp[u][i]<<endl;
	return;
}

int main() {

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		scanf("%d%d", &u, &v);
		adj[v - 1].push_back(u - 1);
		adj[u - 1].push_back(v - 1);
	}
	long long ans = 1;
	dfs(0, 0);
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < k; ++j)
			ans = ans + dp[i][j];
	for (int j = 0; j <= k; ++j)
		ans = ans + dp[0][j];
	printf("%lld\n", ans);
	return 0;
}
