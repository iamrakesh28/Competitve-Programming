#include <iostream>
#include <cstring>

using namespace std;

const int N = 25, inf = 1e9;
int eff[N][N], dp[N][1 << 10], p, d;

int solve(int i, int bit) {
  if (i == 0)
    return 0;
  if (dp[i][bit] == -1) {
    dp[i][bit] = inf;
    for (int dc = 0; dc < d; ++dc) {
      if ((1 << dc) & bit)
	continue;
      int nxt = bit | (1 << dc);
      int sum = 0;
      for (int j = i; j > 0; j--) {
	sum += eff[dc][j - 1];
	dp[i][bit] = min(dp[i][bit], solve(j - 1, nxt) + sum);
      }
    }
  }
  return dp[i][bit];
}

int main() {
  scanf("%d%d", &p, &d);
  for (int i = 0; i < d; ++i)
    for (int j = 0; j < p; ++j)
      scanf("%d", eff[i] + j);
  memset(dp, -1, sizeof dp);
  printf("%d\n", solve(p, 0));
  return 0;
}
