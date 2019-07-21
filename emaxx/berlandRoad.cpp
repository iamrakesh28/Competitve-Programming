#include <bits/stdc++.h>

using namespace std;

long long dp[300][300];

long long solve(int n)
{
	long long ans = 0;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < i; ++j)
			ans += dp[i][j];
	return ans;
}

int main()
{
	int n, k;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin>>dp[i][j];
	scanf("%d", &k);
	for (int i = 0; i < k; ++i) {
		int a, b;
		long long x;
		cin>>a>>b>>x;
		if (x < dp[a - 1][b - 1])
		for (int r = 0; r < n; ++r) {
			for (int c = 0; c < n; ++c) {
				dp[r][c] = min(dp[r][c], dp[r][a - 1] + x + dp[b - 1][c]);
				dp[r][c] = min(dp[r][c], dp[r][b - 1] + x + dp[a - 1][c]);
			}
		}
		cout<<solve(n)<<" ";
	}
	printf("\n");
	return 0;
}
