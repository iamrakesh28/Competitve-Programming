#include <iostream>
#include <vector>

#define N 1050005
using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	vector <int> arr(N), dp(N), freq(N, 0);
	while (q--) {
		int n;
		long long ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &arr[i]);
			freq[arr[i]]++;
		}
		for (int mask = 0; mask < N; ++mask)
			dp[mask] = freq[mask];
		for (int i = 0; i <= 20; ++i) {
			for (int mask = 0; mask < N; ++mask)
				if (mask & (1 << (i - 1)))
					dp[mask] += dp[mask ^ (1 << (i - 1))];
		}
		for (int i = 0; i < n; ++i) {
			ans += dp[(1 << 20) - 1 - arr[i]];
			freq[arr[i]] = 0;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
