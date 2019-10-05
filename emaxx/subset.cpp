#include <bits/stdc++.h>

#define N 105
using namespace std;

int arr[N], dp[N + 1][1024];

int ans(int i, int digit) {

	if (i == 0)
		return 0;
	if (dp[i][digit] == -1) {
		int d = digit, num = arr[i - 1], r;
		bool present = false;
		while (num) {
			r = num % 10;
			if ((1 << r) & digit) {
				present = true;
				break;
			}
			d = d | (1 << r);
			num = num / 10;
		}
		if (!present)
			dp[i][digit] = max(ans(i - 1, digit), ans(i - 1, d) + arr[i - 1]);
		else
			dp[i][digit] = ans(i - 1, digit);
	}
	return dp[i][digit];
}
int main() {

	int t;	
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
			memset(dp + i, -1, sizeof(int) * 1024);
		}
		memset(dp + n, -1, sizeof(int) * 1024);
		printf("%d\n",ans(n, 0));
	}
	return 0;
}
