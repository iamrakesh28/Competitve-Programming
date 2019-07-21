#include <iostream>
#include <cstring>

using namespace std;

const int prime = 1e9 + 7;
char K[10005];
int dp[10005][101][2], len, d;

int solve(int i, int j, int k) {

	if (dp[i][j][k] == -1) {
		int limit;
		if (k == 0)
			limit = 9;
		else
			limit = K[i] - '0';
		dp[i][j][k] = 0;
		for (int r = 0; r < limit; ++r) {
			if (i == len - 1) {
				if (j == (r % d))
					dp[i][j][k] = (dp[i][j][k] + 1) % prime;
				continue;
			}
			dp[i][j][k] = (dp[i][j][k] + solve(i + 1, (j - r + d) % d, 0)) % prime;
		}
		if (i == len - 1) {
			if (j == (limit % d))
				dp[i][j][k] = (dp[i][j][k] + 1) % prime;
		}
		else
			dp[i][j][k] = (dp[i][j][k] + solve(i + 1, (j - limit + d) % d, k)) % prime;
	}
	//cout<<dp[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<endl;
	return dp[i][j][k];
}
int main() {

	scanf("%s%d", K, &d);
	len = strlen(K);
	for (int i = 0; i <= len; ++i)
		for (int j = 0; j <= d; ++j)
			for (int k = 0; k < 2; ++k)
				dp[i][j][k] = -1;
	printf("%d\n", (solve(0, 0, 1) - 1 + prime) % prime);
	return 0;
}
