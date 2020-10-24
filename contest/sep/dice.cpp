#include <iostream>

using namespace std;

const int N = 55;
const double inf = 1e18, eps = 1e-9;
double dp[N][N];
int A[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < k; ++i)
      scanf("%d", A + i);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= k; ++j) {
	if (i == 0 || j > i || j == 0) {
	  dp[i][j] = 0.0;
	  continue;
	}
	//cout << i << " " << j << " ";
	double p = (double)j / k;
	dp[i][j] = dp[i - 1][j] + A[j - 1] / p;
	//cout << dp[i][j] << " ";
	if (abs(1 - p) > eps)
	  dp[i][j] = min(dp[i][j], dp[i - 1][j - 1] + A[j - 1] / (1 - p));
	//cout << dp[i][j] << " " << p << " " << k << endl;
      }
    printf("Case: #%d: %0.10lf\n", q + 1, dp[n][k]);
  }
  return 0;
}
