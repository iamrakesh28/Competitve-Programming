#include <iostream>
#include <cstring>

typedef long long ll;
using namespace std;

const int N = 2e3 + 5;
const ll inf = 1e15;
ll dp[N][N << 1];
int x[N], t[N], n;

ll solve(int i, int time) {
  if (i == 0) {
    if (time < 0)
      return inf;
    return 0;
  }
  if (dp[i][N + time] == -1) {
    dp[i][N + time] = solve(i - 1, time - 1);
    int tm = time + t[i - 1];
    if (tm >= n)
      dp[i][N + time] = min(dp[i][N + time], (ll)x[i - 1]);
    else
      dp[i][N + time] = min(dp[i][N + time], solve(i - 1, tm) + x[i - 1]);
  }
  return dp[i][N + time];
}

int main() {
  scanf("%d", &n);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", t + i, x + i);
  ll ans = solve(n, 0);
  printf("%lld\n", ans);
  return 0;
}
