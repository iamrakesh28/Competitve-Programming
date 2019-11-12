#include <iostream>

#define N 405
using namespace std;

const long long inf = 1e15;
long long arr[N], dp[N][N], pre[N];
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		pre[0] = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%lld", arr + i);
			pre[i + 1] = pre[i] + arr[i];
		}
		// i < j
		for (int l = 1; l <= n; ++l) {
			for (int i = 0; i < n; ++i) {
				if (l == 1) {
					dp[i][i] = 0;
					continue;
				}
				int j = (i + l - 1) % n;
				dp[i][j] = inf;
				long long sum1, sum2;
				for (int k = i; k != j; k = (k + 1) % n) {
					if (k >= i) {
						sum1 = pre[k + 1] - pre[i];
						if (j > i)
							sum2 = pre[j + 1] - pre[k + 1];
						else
							sum2 = pre[n] - pre[k + 1] + pre[j + 1];
					}
					else {
						sum1 = pre[n] - pre[i] + pre[k + 1] - pre[0];
						sum2 = pre[j + 1] - pre[k + 1];
					}
					//cout<<i<<" "<<j<<" "<<k<<" "<<sum1<<" "<<sum2<<" "<<pre[j+1]<<" "<<pre[k]<<endl;
					dp[i][j] = min(dp[i][j], sum1 + sum2 + dp[i][k] + dp[(k + 1) % n][j]);
				}
			}
		}
		long long ans = inf;
		for (int i = 0; i < n; ++i)
			ans = min(ans, dp[i][(i + n - 1) % n]);
		printf("%lld\n", ans);
	}
	return 0;
}
