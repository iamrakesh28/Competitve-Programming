#include <bits/stdc++.h>

const int N = 10005;

using namespace std;

int dp[N], par[N], tick[N], pick[N];

int maxSum(int i)
{
	if (i <= 0)
		return 0;
	if (dp[i] == -1) {
		int x = maxSum(i - 2) + tick[i - 1], y = maxSum(i - 1);
		if (x > y) {
			par[i] = i - 2;
			pick[i] = 1;
		}
		else
			par[i] = i - 1;
		dp[i] = max(x, y);
	}
	return dp[i];
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--) {
		int n;
		scanf("%d",&n);
		for (int i = 0; i < n; ++i) {
			scanf("%d",tick + i);
			dp[i] = -1;
			pick[i] = -1;
		}
		dp[n] = -1;
		pick[n] = -1;
		int d = maxSum(n);
		if (pick[n] == 1)
			printf("%d",tick[n-1]);
		for (int i = par[n]; i > 0; i = par[i]) {
			if (pick[i] == 1)
				printf("%d",tick[i-1]);
		}
		putchar('\n');
	}
}
