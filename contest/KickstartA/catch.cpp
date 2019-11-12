#include <iostream>
#include <vector>
#include <algorithm>

#define N 1002
using namespace std;

int dp[N][N][2];
vector <int> color[N];

int solve(int c, int k, int last) {
	if (c == 0 && k == 0)
		return 0;
	if (k < 0 || c == 0)
		return 1e9;
	if (dp[c][k][last] == -1) {
		dp[c][k][last] = solve(c - 1, k, last);
		if (last) {
			for (int i = 0; i < color[c - 1].size(); ++i) {
				dp[c][k][last] = min(dp[c][k][last], solve(c - 1, k - i - 1, 0) + color[c - 1][i]);
				dp[c][k][last] = min(dp[c][k][last], solve(c - 1, k - i - 1, 1) + 2 * color[c - 1][i]);
			}
		}
		else {
			for (int i = 0; i < color[c - 1].size(); ++i)
				dp[c][k][last] = min(dp[c][k][last], solve(c - 1, k - i - 1, last) + 2 * color[c - 1][i]);
		}
	}
	return dp[c][k][last];
}
int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n, k, m = 0;
		scanf("%d%d", &n, &k);
		vector <int> pos(n);
		for (int j = 0; j < n; ++j)
			scanf("%d", &pos[j]);
		for (int j = 0; j < n; ++j) {
			int c;
			scanf("%d", &c);
			m = max(m, c);
			color[c - 1].push_back(pos[j]);
		}
		for (int j = 0; j < m; ++j)
			sort(color[j].begin(), color[j].end());
		for (int j = 0; j <= m; ++j)
			for (int r = 0; r <= k; ++r)
				dp[j][r][0] = dp[j][r][1] = -1;
		printf("Case #%d: %d\n", i + 1, solve(m, k, 1));
		for (int j = 0; j < m; ++j)
			color[j].clear();
	}
	return 0;
}
