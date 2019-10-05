#include <bits/stdc++.h>

#define N 4005
using namespace std;

int dp[805][N], arr[N][N], sum[N][N];

void compute(int i, int l, int r, int optl, int optr) {

	if (l > r)
		return;
	int mid = (l + r) >> 1;
	pair <int, int> best = {1e9, -1};
	int sat = 0;
	for (int k = min(mid, optr); k >= optl; k--) {
		best = min(best, {dp[i - 1][k - 1] + (sum[mid][mid] - sum[mid][k - 1] - sum[k - 1][mid] + sum[k - 1][k - 1]) / 2, k});
	}
	int opt = best.second;
	dp[i][mid] = best.first;
	compute(i, l, mid - 1, optl, opt);
	compute(i, mid + 1, r, opt, optr);
}
int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i) {
		dp[0][i] = 1e9;
		for (int j = 0; j < n; ++j) {
			char ch;
			while ((ch = getchar()) && (ch < '0' || ch > '9'))
				;
			arr[i][j] = ch - '0';
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] + arr[i][j] - sum[i][j];
		}
	}
	dp[0][0] = 0, dp[0][n] = 1e9;
	for (int i = 1; i <= k; ++i) {
		dp[i][0] = 0;
		compute(i, 1, n, 1, n);
	}
	printf("%d\n", dp[k][n]);
	return 0;
}
