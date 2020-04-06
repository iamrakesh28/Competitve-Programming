#include <iostream>

using namespace std;

const int N = 55, inf = -1e9;
int dp[N][N * N], stak[N][N];

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int n, k, p;
    scanf("%d%d%d", &n, &k, &p);
    for (int r = 0; r < n; ++r)
      for (int c = 0; c < k; ++c)
	scanf("%d", stak[r] + c);
    for (int r = 0; r <= n; ++r)
      for (int c = 0; c <= p; ++c) {
	if (r == 0) {
	  if (c == 0)
	    dp[r][c] = 0;
	  else
	    dp[r][c] = inf;
	  continue;
	}
	if (c == 0) {
	  dp[r][c] = dp[r - 1][c];
	  continue;
	}
	int sum = 0;
	dp[r][c] = inf;
	for (int m = 0; m <= k; ++m) {
	  if (m)
	    sum += stak[r - 1][m - 1];
	  if (c >= m)
	    dp[r][c] = max(dp[r][c], dp[r - 1][c - m] + sum);
	}
      }
    printf("Case #%d: %d\n", i + 1, dp[n][p]);
  }
  return 0;
}
