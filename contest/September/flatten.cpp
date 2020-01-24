#include <iostream>

using namespace std;

const int inf = 1e5;
int dp[105][105][1005], arr[105], minPre[105][105][1005], minSuf[105][105][1005];

int main() {

	int q;
	scanf("%d", &q);
	for (int t = 0; t < q; ++t) {
		int n, k, maxm = -1;
		scanf("%d%d", &n, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i), maxm = max(maxm, arr[i]);
		for (int i = 0; i <= n; ++i) {
			for (int j = 0; j <= k; ++j) {
				minPre[i][j][1] = inf;
				for (int a = 1; a <= maxm; ++a) {
					if (i == 0)
						dp[i][j][a] = 0;
					else if (j == 0) {
						if (arr[i - 1] == a)
							dp[i][j][a] = dp[i - 1][j][a];
						else
							dp[i][j][a] = dp[i - 1][j][a] + 1;
					}
					else if (arr[i - 1] == a)
						dp[i][j][a] = min(dp[i - 1][j][a], min(minPre[i - 1][j - 1][a], minSuf[i - 1][j - 1][a]));
					else
						dp[i][j][a] = min(dp[i - 1][j][a], min(minPre[i - 1][j - 1][a], minSuf[i - 1][j - 1][a])) + 1;				
					minPre[i][j][a + 1] = min(minPre[i][j][a], dp[i][j][a]);
				}
				minSuf[i][j][maxm] = inf;
				for (int a = maxm; a > 0; --a)
					minSuf[i][j][a - 1] = min(minSuf[i][j][a], dp[i][j][a]);
			}
		}
		int ans = inf;
		//cout<<maxm<<endl;
		for (int i = 0; i <= k; ++i)
			for (int j = 1; j <= maxm; ++j)
				ans = min(ans, dp[n][i][j]);
		printf("Case #%d: %d\n", t + 1, ans);
	}
	return 0;
}
