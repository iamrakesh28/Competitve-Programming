#include <iostream>

using namespace std;

const int N = 21;

long long a[N], b[N], arr1[1 << 20], arr2[1 << 20], dp[N][1 << 20];

long long ls(int i, int bit, int h) {
	
	if (i < 0) {
		if (arr2[bit] >= h)
			return 1;
		return 0;
	}
	if (dp[i][bit] == -1) {
		dp[i][bit] = ls(i - 1, bit | (1 << i), h);
		if (bit & (1 << i))
			dp[i][bit] += ls(i - 1, bit ^ (1 << i), h);
	}
	return dp[i][bit];
}
long long solve(int n, long long h) {
	// A
	
	int cnt = 0;
	long long cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < (1 << n); ++i) {
		long long val = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				val += a[j];
		arr1[cnt++] = val;
	}

	cnt = 0;
	for (int i = 0; i < (1 << n); ++i) {
		long long val = 0;
		for (int j = 0; j < n; ++j)
			if (i & (1 << j))
				val += b[j];
		arr2[cnt++] = val;
	}
	for (int i = 0; i < cnt; ++i)
		if (arr2[i] >= h)
			cnt2++;
	long long ans = 0;
	for (int j = 0; j < 21; ++j)
		for (int i = 0; i < (1 << n); ++i)
			dp[j][i] = -1;
	for (int i = 0; i < (1 << n); ++i) {
		dp[n - 1][i] = ls(n - 1, i, h);
		if (arr1[i] >= h)
			ans = ans + dp[n - 1][i];
	}
	return ans;
		
}

int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		long long h;
		scanf("%d%lld", &n, &h);
		for (int j = 0; j < n; ++j)
			scanf("%lld", a + j);
		for (int j = 0; j < n; ++j)
			scanf("%lld", b + j);
		long long ans = solve(n, h);
		printf("Case #%d: %lld\n", i + 1, ans);
	}
	return 0;
}
