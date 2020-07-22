#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;

const int prime = 1e9 + 7, N = 10;
int pairs[6];
ll dp[61][N][N][N][N][N][N][3];

ll solve(int i, int a, int b, int c, int d, int e, int f, int prev) {
  if (i == 0) {
    return 1;
  }
  if (dp[i][a][b][c][d][e][f][prev] == -1) {
    dp[i][a][b][c][d][e][f][prev] = solve(i - 1, a, b, c, d, e, f, prev);
    if (prev == 0) {
      if (c > 0)
	dp[i][a][b][c][d][e][f][prev] = (dp[i][a][b][c][d][e][f][prev] +
					 solve(i - 1, a, b, c - 1, d, e, f, 1)) % prime;
      if (e > 0)
	dp[i][a][b][c][d][e][f][prev] = (dp[i][a][b][c][d][e][f][prev] +
					 solve(i - 1, a, b, c, d, e - 1, f, 2)) % prime;
    }
    else if (prev == 1) {
      if (a > 0)
	dp[i][a][b][c][d][e][f][prev] = (dp[i][a][b][c][d][e][f][prev] +
					 solve(i - 1, a - 1, b, c, d, e, f, 0)) % prime;
      if (f > 0)
	dp[i][a][b][c][d][e][f][prev] = (dp[i][a][b][c][d][e][f][prev] +
					 solve(i - 1, a, b, c, d, e, f - 1, 0)) % prime;
    }
    else  {
      if (b > 0)
	dp[i][a][b][c][d][e][f][prev] = (dp[i][a][b][c][d][e][f][prev] +
					 solve(i - 1, a, b - 1, c, d, e, f, 0)) % prime;
      if (d > 0)
	dp[i][a][b][c][d][e][f][prev] = (dp[i][a][b][c][d][e][f][prev] +
					 solve(i - 1, a, b, c, d - 1, e, f, 0)) % prime;
    }
  }
  return dp[i][a][b][c][d][e][f][prev];
}

int main() {
  int n, sum = 0;
  scanf("%d", &n);
  for (int i = 0; i < 6; ++i) {
    scanf("%d", pairs + i);
    sum += pairs[i];
  }
  if (sum < n - 1) {
    puts("0");
    return 0;
  }
  memset(dp, -1, sizeof dp);
  ll ans = solve(n - 1, pairs[0], pairs[1], pairs[2], pairs[3], pairs[4], pairs[5], 0);
  ll ans1 = solve(n - 1, pairs[0], pairs[1], pairs[2], pairs[3], pairs[4], pairs[5], 1);
  ll ans2 = solve(n - 1, pairs[0], pairs[1], pairs[2], pairs[3], pairs[4], pairs[5], 2);
  ans = (ans + ans1 + ans2) % prime;
  printf("%lld\n", ans);
  return 0;
}
