#include <bits/stdc++.h>

using namespace std;

int adj[500][500], dp[500][500][500], xi[500], ans[500];

int solve(int i, int j, int k)
{
	if (k == -1)
		return adj[xi[i] -1][xi[j] - 1];
	if (dp[i][j][k] == -1) {
		dp[i][j][k] = min(solve(i, j, k - 1), solve(i, k, k - 1) + solve(k, j, k - 1));
	}
	return dp[i][j][k];
}

int calc(int i)
{
	int ans = 0;
	for (int r = 0; r <= i; ++r) 
		for (int c = 0; c <= i; ++c)
			ans += dp[r][c][i];
	return ans;
}

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%d", adj[i] + j);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			for (int k = 0; k < n; ++k)
				dp[i][j][k] = -1;
	for (int i = 0; i < n; ++i)
		scanf("%d", xi + i);
	reverse(xi, xi + n);
	for (int i = 0; i < n; i++) {
		for (int r = 0; r <= i; ++r)
			for (int c = 0; c <= i; ++c)
				int v = solve(r, c, i);
		ans[i] = calc(i);
	}
	//cout<<adj[][]<<endl;
	reverse(ans, ans + n);
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
