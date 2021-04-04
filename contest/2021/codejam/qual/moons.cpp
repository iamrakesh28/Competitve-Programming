#include <iostream>
#include <cstring>

using namespace std;

const int N = 1005, INF = 1e9;
char S[N];
int dp[N][2];

int solve(int x, int y) {
  int n = strlen(S);

  if (S[0] == '?') {
    dp[0][0] = dp[0][1] = 0;
  }
  else {
    if (S[0] == 'C') {
      dp[0][0] = 0;
      dp[0][1] = INF;
    }
    else {
      dp[0][1] = 0;
      dp[0][0] = INF;
    }
  }
  
  for (int i = 1; i < n; i++) {
    if (S[i] == '?') {
      dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
      dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
    }
    else {
      if (S[i] == 'C') {
        dp[i][0] = min(dp[i - 1][0], dp[i - 1][1] + y);
        dp[i][1] = INF;
      }
      else {
        dp[i][1] = min(dp[i - 1][1], dp[i - 1][0] + x);
        dp[i][0] = INF;
      }
    }
  }

  return min(dp[n - 1][0], dp[n - 1][1]);
}

int main() {

  int t;
  scanf("%d", &t);

  for (int q = 0; q < t; ++q) {
    int x, y;
    scanf("%d%d%s", &x, &y, S);

    printf("Case #%d: %d\n", q + 1, solve(x, y));
  }
  return 0;
}
