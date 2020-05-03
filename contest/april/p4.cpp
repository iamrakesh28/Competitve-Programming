#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e2 + 5;
double dp[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int w, h, l, u, r, d;
    scanf("%d%d%d%d%d%d", &w, &h, &l, &u, &r, &d);
    memset(dp, 0.0, sizeof dp);
    dp[0][0] = 1.0;
    for (int r = 0; r < h; ++r)
      for (int c = 0; c < w; ++c) {
	if (r >= u && r <= d && c >= l && c <= r)
	  dp[r][c] = 0;
	if (r + 1 == h - 1)
	  dp[r + 1][c] = dp[r][c];
	else if (r + 1 < h)
	  dp[r + 1][c] += dp[r][c] / 2.0;
	if (c + 1 == w - 1)
	  dp[r][c + 1] = dp[r][c];;
	if (c + 1 < w)
	  dp[r][c + 1] = dp[r][c] / 2.0;
      }
    printf("Case #%d: %lf\n", i + 1,dp[h][w]);
  }
  return 0;
}
