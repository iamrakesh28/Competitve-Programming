#include <iostream>
#include <cstring>

typedef long long ll;
using namespace std;

const int N = 3e3 + 5, prime = 998244353;
ll dp[N][N], cnt[N][N];
int n, m;
char T[N], S[N];

// T, S
ll solve(int s, int a) {
  if (s == 0) {
  }
  if (dp[s][a] == -1) {
    dp[s][a] = 0;
    cnt[s][a] = 0;
    if (T[a - 1] != S[s - 1])
      dp[s][a] = power[s];
    else {
      dp[s][a] = solve(s - 1, a + 1);
      cnt[s][a] = cnt[s - 1][a + 1];
    }

    int l = n - s - a;
    if (T[l] != S[s - 1]) {
      dp[s][a] = dp[s][a] + solve(s - 1, a) % prime;
    }
  }
  return dp[s][a];
}

int main() {
  scanf("%s%s", S, T);
  n = strlen(S);
  m = strlen(T);
  ll ans = solve();
  printf("%lld\n", ans);
  return 0;
}
