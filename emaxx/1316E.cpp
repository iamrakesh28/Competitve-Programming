#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
const long long inf = -1e16;
long long dp[N][1 << 7], sum[N];
int s[N][7], n, k, p;
pair <int, int> a[N];

long long solve(int i, int mask) {
  if (i == 0) {
    if (mask != (1 << p) - 1)
      return inf;
    return 0;
  }
  if (dp[i][mask] == -1) {
    //cout<<i<<" "<<mask<<endl;
    int cnt = 0;
    int temp = mask;
    while (temp) {
      cnt++;
      temp = temp & (temp - 1);
    }
    int tot = n - i - cnt;
    tot = k - tot;
    if (mask == (1 << p) - 1) {
      long long aud = sum[i] - sum[i - tot];
      dp[i][mask] = aud;
    }
    else {
      if (tot > 0)
	dp[i][mask] = solve(i - 1, mask) + a[i - 1].first;
      else
	dp[i][mask] = solve(i - 1, mask);
      for (int j = 0; j < p; ++j) {
	if ((1 << j) & mask)
	  continue;
	int ind = a[i - 1].second;
	dp[i][mask] = max(dp[i][mask], solve(i - 1, mask | (1 << j)) + s[ind][j]);
      }
    }
  }
  return dp[i][mask];
}

int main() {
  scanf("%d%d%d", &n, &p, &k);
  for (int i = 0; i < n; ++i) {
    int d;
    scanf("%d", &d);
    a[i] = {d, i};
  }
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < p; ++j)
      scanf("%d", s[i] + j);
  sort(a, a + n);
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < n; ++i)
    sum[i + 1] = sum[i] + a[i].first;
  long long ans = solve(n, 0);
  printf("%lld\n", ans);
  return 0;
}
