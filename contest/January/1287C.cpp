#include <iostream>
#include <cstring>

using namespace std;

const int inf = 1e7;

int arr[105], pi[105], dp[105][105][105][2];

int solve(int i, int odd, int even, int last) {
  if (odd < 0 || even < 0)
    return inf;
  if (i == 0)
    return 0;
  if (dp[i][odd][even][last] == -1) {
    if (pi[i - 1]) {
      if (pi[i - 1] & 1) {
	if (last)
	  dp[i][odd][even][last] = solve(i - 1, odd, even, 1);
	else
	  dp[i][odd][even][last] = solve(i - 1, odd, even, 1) + 1;
      }
      else {
	if (last)
	  dp[i][odd][even][last] = solve(i - 1, odd, even, 0) + 1;
	else
	  dp[i][odd][even][last] = solve(i - 1, odd, even, 0);
      }
    }
    else {
      if (last)
	  dp[i][odd][even][last] = min(solve(i - 1, odd - 1, even, 1), solve(i - 1, odd, even - 1, 0) + 1);
      else
	  dp[i][odd][even][last] = min(solve(i - 1, odd - 1, even, 1) + 1, solve(i - 1, odd, even - 1, 0));
    }
  }
  return dp[i][odd][even][last];
}

int main() {
  int n, even = 0, odd = 0;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int p;
    scanf("%d", &p);
    pi[i] = p;
    arr[p] = 1;
  }
  for (int i = 1; i <= n; ++i)
    if (arr[i] == 0) {
      if (i & 1)
	odd++;
      else
	even++;
    }
  memset(dp, -1, sizeof dp);
  int ans;
  if (pi[n - 1] == 0)
    ans = min(solve(n - 1, odd - 1, even, 1), solve(n - 1, odd, even - 1, 0));
  else {
    if (pi[n - 1] & 1)
      ans = solve(n - 1, odd, even, 1);
    else
      ans = solve(n - 1, odd, even, 0);
  }
  printf("%d\n", ans);
  return 0;
}
