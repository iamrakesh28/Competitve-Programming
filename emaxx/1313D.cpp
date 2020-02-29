#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
int dp[N][1 << 8], bit[N], n, k;
bool odd[1 << 8];

struct interval {
  int x, end, i;
} interval[N];

bool compare(struct interval &a, struct interval &b) {
  if (a.x != b.x)
    return a.x < b.x;
  return a.end < b.end;
}

int solve(int i, int mask) {
  if (i == (n << 1))
    return 0;
  if (dp[i][mask] == -1) {
    int ans = 0;
    if (odd[mask]) {
      ans = interval[i].x - interval[i - 1].x;
      if (interval[i - 1].end == 1)
	ans--;
    }
    int pos = bit[interval[i].i];
    dp[i][mask] = ans;
    if (interval[i].end == -1)
      dp[i][mask] += max(solve(i + 1, mask | (1 << pos)), solve(i + 1, mask));
    else {
      if (interval[i].end == 1 && odd[mask])
	dp[i][mask]++;
      //cout<<mask<<" "<<i<<" "<<dp[i][mask]<<endl;
      int temp = mask;
      if (mask & (1 << pos))
	temp = mask ^ (1 << pos);
      dp[i][mask] += solve(i + 1, temp);
    }
  }
  return dp[i][mask];
}

int main() {

  int m;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    interval[i << 1] = {l, -1, i};
    interval[(i << 1) + 1] = {r, 1, i};
  }
  sort(interval, interval + (n << 1), compare);
  for (int i = 1; i < (1 << 8); ++i) {
    int cnt = 0, num = i;
    while (num) {
      num = num & (num - 1);
      cnt++;
    }
    if (cnt & 1)
      odd[i] = true;
  }
  int ans, mask = 0;
  for (int i = 0; i < (n << 1); ++i) {
    int ind = interval[i].i;
    if (interval[i].end == -1) {
      int j;
      for (j = 0; j < k; ++j)
	if (((1 << j) & mask) == 0)
	  break;
      bit[ind] = j;
      mask = mask | (1 << j);
    }
    else {
      int pos = bit[ind];
      mask = mask ^ (1 << pos);
    }
  }
  memset(dp, -1, sizeof dp);
  int pos = bit[interval[0].i];
  ans = max(solve(1, 1 << pos), solve(1, 0));
  printf("%d\n", ans);
  return 0;
}
