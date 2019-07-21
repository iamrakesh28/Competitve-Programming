#include <iostream>

#define N 5001
using namespace std;

int n, k, dp[N][N], arr[N], hap[N][N];
const int inf = 1e9;

void compute(int i, int l, int r, int optl, int optr) {
	if (l > r)
		return;
	int mid = (l + r) >> 1;
	pair <int, int> best = {inf, -1};
	for (int j = mid; j >= min(optl, optr); j--) {
		best = min(best, {dp[i - 1][j - 1] + hap[mid][mid] - hap[mid][j - 1] - hap[j - 1][mid] + hap[j - 1][j - 1], j});
	}
	dp[i][mid] = best.first;
	int opt = best.second;
	compute(i, l, mid - 1, optl, opt);
	compute(i, mid + 1, r, opt, optr);
}
int main() {

	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i), dp[0][i] = inf;	
	dp[0][n] = inf, dp[0][0] = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= i; ++j) {
			hap[i][j] = hap[i][j - 1] + hap[i - 1][j] - hap[i - 1][j - 1];
			if (arr[j - 1] > arr[i - 1])
				hap[i][j]++;
		}
		for (int j = i + 1; j <= n; ++j) {
			hap[i][j] = hap[i][j - 1] + hap[i - 1][j] - hap[i - 1][j - 1];
			//cout<<hap[i][j]<<" ";
		}
	}
	for (int i = 1; i <= k; ++i) {
		dp[i][0] = 0;
		compute(i, 1, n, 1, n);
	}
	printf("%d\n", dp[k][n]);
	return 0;
}
