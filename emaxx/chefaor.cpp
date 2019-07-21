#include <iostream>

#define N 5005
using namespace std;

long long dp[N][N];
int n, K, arr[N];

void compute(int i, int l, int r, int optl, int optr) {

	if (l > r)
		return;
	int mid = (l + r) >> 1;
	pair <long long, int> best = {-1, -1};
	long long sumor = 0;
	for (int k = mid; k >= optl ; --k) {
		sumor = sumor | arr[k - 1];
		best = max(best, {dp[i - 1][k - 1] + sumor, k});
	}
	dp[i][mid] = best.first;
	int opt = best.second;
	compute(i, l, mid - 1, optl, opt);
	compute(i, mid + 1, r, opt, optr);
}
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%d%d", &n, &K);
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i), dp[0][i] = 0;
		dp[0][n] = 0;
		for (int i = 1; i <= K; ++i) {
			dp[i][0] = 0;
			compute(i, 1, n, 1, n);
		}
		printf("%lld\n", dp[K][n]);
	}	
	return 0;
}
