#include <iostream>

#define N 10005
using namespace std;

long long dp[N][1005], cost[1005];
int c[1005];

int main() {

	int n, m = 0;
	long long w, b, x;
	scanf("%d%lld%lld%lld", &n, &w, &b, &x);
	for (int i = 0; i < n; ++i) {
		scanf("%d", c + i);
		m += c[i];
	}
	for (int i = 0; i < n; ++i)
		scanf("%lld", cost + i);
	for (int i  = 0 ; i <= m; ++i)
		for (int j = 0; j <= n; ++j)
			dp[i][j] = -1;
	dp[0][0] = w;
	int ans = 0;
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int ci = 0; ci <= min(c[j - 1], i); ci++) {
					if (dp[i - ci][j - 1] == -1)
						continue;
					long long man = min(dp[i - ci][j - 1] + x, w + (i - ci) * b) - cost[j - 1] * ci;
					if (man < 0)
						continue;
					dp[i][j] = max(dp[i][j], man);
					ans = max(ans, i);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
