#include <iostream>

using namespace std;

// set the sizes appropriately
const int N = 1e3;
bool dp[N][N];
int vi[N];

int main() {
  int n, V = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", vi + i);
    V += vi[i];
  }

  // dp[i][j] -> tells whether it is possible to form a set among the items {1 ,..., i}
  // such that their total values is j
  int half = V / 2, ans;
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= half; ++j) {
      if (i == 0) {
	dp[i][j] = j ? false : true;
	continue;
      }
      dp[i][j] = dp[i - 1][j];
      if (j >= vi[i - 1])
	dp[i][j] = dp[i][j] || dp[i - 1][j - vi[i - 1]];

      // these two lines are not related to the above recurrence.
      // It finds the largest possible j
      if (i == n && dp[i][j])
	ans = j;
    }
  // minimum |a - b|
  // one person has ans other has V - ans.
  // V - ans - ans
  printf("%d\n", abs(V - 2 * ans));
  return 0;
}
