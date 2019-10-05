#include <isotream>

using namespace std;

const int prime = 1e9 + 7, N = 250;
long long dp[N][N][4];

/*
	0 -> no
	1 -> row
	2 -> col
*/
int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = n - 2; i >= 0; i--) {
		for (int j = n - 2; j >= 0; j--) {
			dp[i][j][0] = dp[i][j + 1][0] * dp[i + 1][j][0] % prime;
			dp[i][j][0] = dp[i][j][0] * (k - 1) % prime;

			dp[i][j][1] = dp[i][j + 1][0] * dp[i + 1][j][0] % prime;
			dp[i][j][0] = dp[i][j][0] * (k - 1) % prime;

			dp[i][j][0] = dp[i][j + 1][0] * dp[i + 1][j][0] % prime;
			dp[i][j][0] = dp[i][j][0] * (k - 1) % prime;

			dp[i][j][0] = dp[i][j + 1][0] * dp[i + 1][j][0] % prime;
			dp[i][j][0] = dp[i][j][0] * (k - 1) % prime;
		}
	}
	return 0;
}
