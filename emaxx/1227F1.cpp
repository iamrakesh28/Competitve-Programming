#include <iostream>
#include <cstring>

using namespace std;

const int prime = 998244353, N = 2e3;

long long dp[N][2 * N + 5];
int h[N], n, k;

long long solve(int i, int diff) {
  if (i < 0) {
    if (diff > 0)
      return 1;
    return 0;
  }
  int offset = diff + N;
  if (dp[i][offset] == -1) {
    int j = (i + 1) % n;
    if (h[i] == h[j])
      dp[i][offset] = k * solve(i - 1, diff) % prime;
    else {
      dp[i][offset] = (k - 2) * solve(i - 1, diff) % prime;
      dp[i][offset] = (dp[i][offset] + solve(i - 1, diff + 1)) % prime;
      dp[i][offset] = (dp[i][offset] + solve(i - 1, diff - 1)) % prime;
    }
  }
  return dp[i][offset];
}

int main() {
  
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", h + i);
  memset(dp, -1, sizeof dp);
  long long ans = solve(n - 1, 0);
  printf("%lld\n", ans);
  return 0;
}
