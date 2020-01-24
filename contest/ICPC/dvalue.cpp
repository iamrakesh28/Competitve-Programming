#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 3005, prime = 987654319;
long long dp[N][N][7], sum[N][N][7];
int arr[N];
vector <int> large[N];

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j)
			if (arr[j] < arr[i])
				large[i].push_back(j);
	}
	// 2 length
	memset(dp, sizeof dp, 0);
	memset(sum, sizeof sum, 0);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (arr[j] < arr[i])
				dp[i][j][1] = 1;
			sum[i][j + 1][1] = sum[i][j][1] + dp[i][j][1];
		}
	}

	// 3 length
	for (int k = 2; k < 7; ++k)
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (arr[j] < arr[i])
					dp[i][j][k] = (sum[j][n][k - 1] - sum[j][i][k - 1] + prime) % prime;
				sum[i][j + 1][k] = (sum[i][j][k] + dp[i][j][k]) % prime;
			}
		}

	long long ans = 0;
	for (int i = 0; i < n; ++i)
		ans = (ans + sum[i][n][6] - sum[i][i][6] + prime) % prime;
	printf("%lld\n", ans);
	return 0;
}
