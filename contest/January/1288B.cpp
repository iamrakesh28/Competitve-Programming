#include <iostream>

using namespace std;

const int prime = 1e9 + 7, N = 1e3 + 5;
long long dp[11][N][N], sum[11][N][N];

long long get(int i, int j, int k) {
	if (j < 1 || k < 1)
		return 0;
	return sum[i][j][k];
}

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				if (i == 0) {
					if (j <= k)
						dp[i][j][k] = 1;
					else
						dp[i][j][k] = 0;
					sum[i][j][k] = (get(i, j - 1, k) + get(i, j, k - 1) - get(i, j - 1, k - 1) + dp[i][j][k] + prime) % prime;
					sum[i][j][k] = (sum[i][j][k] + prime) % prime;
					//cout<<sum[i][j][k]<<" "<<i<<" "<<j<<" "<<k<<endl;
					continue;
				}
				if (j > k)
					dp[i][j][k] = 0;
				else
					dp[i][j][k] = (get(i - 1, k, k) - get(i - 1, j - 1, k) + prime) % prime;
				sum[i][j][k] = (get(i, j - 1, k) + get(i, j, k - 1) - get(i, j - 1, k - 1) + dp[i][j][k] + prime) % prime;
				sum[i][j][k] = (sum[i][j][k] + prime) % prime;
			}
		}
	}
	/*
	for (int i = 0; i <= m; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k)
				cout<<sum[i][j][k]<<" ";
			cout<<endl;
			}
		cout<<endl;
	}
	*/
	long long ans = get(m - 1, n, n);
	cout<<ans<<endl;
	return 0;
}
