#include <iostream>
#include <algorithm>
#include <cassert>

#define N 1005
using namespace std;

const long long inf = 1e15;
long long arr[N];
long long dp[N][N];

void solve(int j, int l, int r, int optl, int optr, int n) {
	if (l > r)
		return;
	//cout<<optl<<" "<<optr<<endl;
	//assert(optl <= optr);
	if (abs(optl - optr) <= 1)
		optl = 1, optr = r;
	int mid = (l + r) >> 1, opt;
	pair <long long, int> best = {inf, -1}; 
	if (mid >= 2)
		if (dp[j - 1][mid - 1] != inf)
		best = {dp[j - 1][mid - 1] - arr[mid - 2] * (n - mid + 1) + arr[mid - 1] * (n - mid + 1), mid - 1};
	for (int i = optl; i <= min(mid - 1, optr); ++i)
		if (dp[j - 1][i] != inf)
		best = min(best, {dp[j - 1][i] - (n - mid + 1) * arr[i - 1] + arr[mid - 1] * (n - mid  + 1), i});

	opt = best.second;
	//cout<<best.first<<" "<<mid<<endl;
	dp[j][mid] = best.first;
	if (opt == -1) {
		solve(j, l, mid - 1, optl, optr, n);
		solve(j, mid + 1, r, optl, optr, n);
		return;
	}
	solve(j, l, mid - 1, opt, optr, n);
	solve(j, mid + 1, r, optl, opt, n);

}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, z;
		long long ans = inf;
		scanf("%d%d", &n, &z);
		for (int i = 0; i < n; ++i)
			scanf("%lld", arr + i);
		sort(arr, arr + n);
		dp[1][0] = inf;
		for (int i = 1; i <= n; ++i)
			dp[1][i] = arr[i - 1] * (n - i + 1);
		for (int i = 2; i <= z; ++i) {
			dp[i][0] = inf;
			solve(i, 1, n, 1, n, n);
		}
		for (int i = 1; i <= n; ++i)
			ans = min(ans, dp[z][i]);
		assert(ans >= 0);
		printf("%lld\n", ans);
	}
	return 0;
}



