#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N = 4e3 + 5, inf = 1e9;

int k, H[N], sum[N], dp[N][N << 1];

int solve(int i, int j) {
  if (i == 0)
    return (j >= k && sum[1] - j >= k) ? 0 : inf;

  if (dp[i][j] == -1) {
    dp[i][j] = inf;

    if (j >= k) {
      if (sum[i + 1] - j >= k)
        dp[i][j] = 0;
      else
        dp[i][j] = solve(i - 1, j) + 1;
    }
    else {
      dp[i][j] = solve(i - 1, j + H[i - 1]) + 1;
      if (sum[i + 1] - j < k)
        dp[i][j] = min(dp[i][j], solve(i - 1, j) + 1);
    }
  }
  
  return dp[i][j];
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {

    int n, maxval = -1;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i) {
      scanf("%d", H + i);
      maxval = max(maxval, H[i]);
    }

    int cnt = 1, parsum = 0;
    
    sort(H, H + n);
    sum[n + 1] = 0;
    for (int i = n; i > 0; i--) {
      sum[i] = sum[i + 1] + H[i - 1];

      if (i < n && parsum < k) {
        cnt++;
        parsum += H[i - 1];
      }
    }

    if (maxval >= k) {
      if (parsum >= k)
        printf("%d\n", cnt);
      else
        puts("-1");
      continue;
    }
    
    for (int i = 0; i <= n; ++i) {
      memset(dp[i], -1, sizeof(int) * (k + maxval + 1));
    }

    int ans = solve(n, 0);
    if (ans >= inf) {
      puts("-1");
    }
    else {
      printf("%d\n", ans);
    }
  }
  
  return 0;
}
