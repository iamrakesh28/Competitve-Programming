#include <iostream>

using namespace std;
typedef long long ll;

const int N = 2e6 + 5, prime = 1e9 + 7;
ll dp[N][2];

int main() {
  dp[0][0] = dp[0][1] = 0;
  dp[1][0] = dp[1][1] = 0;
  dp[2][0] = 4;
  dp[2][1] = 0;
  for (int i = 3; i < N; ++i) {
    dp[i][0] = (dp[i - 2][1] + dp[i - 1][1] + dp[i - 2][1] + 4) % prime;
    dp[i][1] = (2 * max(dp[i - 2][0], dp[i - 2][1]) + max(dp[i - 1][0], dp[i - 1][1])) % prime;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    ll ans = max(dp[n - 1][0], dp[n - 1][1]);
    printf("%lld\n", ans);
  }
  return 0;
}
