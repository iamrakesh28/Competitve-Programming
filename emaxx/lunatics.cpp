#include <iostream>

#define N 8005
using namespace std;

int l, g;
long long dp[805][N], arr[N], pre[N];

void compute(int i, int l, int r, int optl, int optr) {

	if (l > r)
		return;
	int mid = (l + r) >> 1;
	pair <long long, int> best = {1e18, -1};
	for (int k = min(mid, optr); k >= optl; k--) {
		best = min(best, {dp[i - 1][k - 1] + (pre[mid] - pre[k - 1]) * (mid - k + 1), k});
	}
	int opt = best.second;
	//cout<<i<<endl;
	dp[i][mid] = best.first;
	compute(i, l, mid - 1, optl, opt);
	compute(i, mid + 1, r, opt, optr);
}
int main() {

	int l, g;
	scanf("%d%d", &l, &g);
	pre[0] = 0;
	for (int i = 0; i < l; ++i) {
		scanf("%lld", arr + i), dp[0][i] = 1e18;
		pre[i + 1] = pre[i] + arr[i];
	}
	dp[0][l] = 1e18, dp[0][0] = 0;
	for (int i = 1; i <= g; ++i) {
		dp[i][0] = 0;
		compute(i, 1, l, 1, l);
	}
	printf("%lld\n", dp[g][l]);
	return 0;
}
