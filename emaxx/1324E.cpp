#include <iostream>

using namespace std;

const int N = 2e3 + 5;
int a[N], dp[N][N];

int main() {
  int n, h, l, r;
  scanf("%d%d%d%d", &n, &h, &l, &r);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for (int i = n - 1; i >= 0; i--)
    for (int j = 0; j <= h; ++j) {
      if (i == n - 1) {
	dp[i][j] = 0;
	if (j >= l && j <= r)
	  dp[i][j] = 1;
	continue;
      }
      dp[i][j] = max(dp[i + 1][(j + a[i + 1] - 1 + h) % h], dp[i + 1][(j + a[i + 1] + h) % h]);
      if (j >= l && j <= r)
	dp[i][j]++;
    }
  int ans = max(dp[0][a[0]], dp[0][a[0] - 1]);
  printf("%d\n", ans);
  return 0;
}
