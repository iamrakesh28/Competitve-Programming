#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 5, inf = 1e9;
int pos[N], v[N];
int dp[N][4];

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    int k;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
      int ai;
      scanf("%d", &ai);
      v[i] = ai;
    }
    reverse(v, v + k);
    for (int i = 0; i < k; ++i)
      for (int r = 0 ; r < 4; ++r) {
	if (i == 0) {
	  dp[i][r] = 0;
	  continue;
	}
	dp[i][r] = inf;
	if (v[i - 1] == v[i])
	  dp[i][r] = dp[i - 1][r];
	if (v[i - 1] > v[i])
	  for (int m = 0; m < 4; ++m) {
	    if (m <= r)
	      dp[i][r] = min(dp[i][r], dp[i - 1][m] + 1);
	    else
	      dp[i][r] = min(dp[i][r], dp[i - 1][m]);
	  }
	else if (v[i - 1] < v[i]) {
	  for (int m = 0; m < 4; ++m) {
	    if (m >= r)
	      dp[i][r] = min(dp[i][r], dp[i - 1][m] + 1);
	    else
	      dp[i][r] = min(dp[i][r], dp[i - 1][m]);
	  }
	}
      }
    
    int ans = dp[k - 1][0];
    ans = min(dp[k - 1][1], ans);
    ans = min(dp[k - 1][2], ans);
    ans = min(dp[k - 1][3], ans);
    printf("Case #%d: %d\n", j + 1, ans);
  }
  return 0;
}
