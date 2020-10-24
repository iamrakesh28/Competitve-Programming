#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5, inf = 1e9;
char s[N];
int dp[N][2];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%s", s);
    int n = strlen(s);
    int ans = n - 2;
    for (int i = 0; i <= 9; ++i)
      for (int j = 0; j <= 9; ++j) {
	for (int k = n; k >= 0; k--) {
	  for (int d = 0; d < 2; ++d) {
	    if (k == n) {
	      if (d == 1 && i != j)
		dp[k][d] = inf;
	      else
		dp[k][d] = 0;
	      continue;
	    }
	    dp[k][d] = dp[k + 1][d] + 1;
	    if (d == 0) {
	      if ((int)(s[k] - '0') == i)
		dp[k][d] = min(dp[k][d], dp[k + 1][1 - d]);
	    }
	    else {
	      if ((int)(s[k] - '0') == j)
		dp[k][d] = min(dp[k][d], dp[k + 1][1 - d]);
	    }
	  }
	}
	ans = min(ans, dp[0][0]);
      }
    printf("%d\n", ans);
  }
  return 0;
}
