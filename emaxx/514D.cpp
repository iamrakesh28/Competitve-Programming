#include <iostream>
#include <cmath>

using namespace std;

const int N = 1e5;
int droid[N][5], st[18][5][N];

int main() {

  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      scanf("%d", droid[i] + j), st[0][j][i] = droid[i][j];
  int logk = ceil(log2(n));
  for (int i = 1; i <= logk; ++i)
    for (int j = 0; j < m; ++j)
      for (int r = 0; r + (1 << i) <= n; ++r)
	st[i][j][r] = max(st[i - 1][j][r], st[i - 1][j][r + (1 << (i - 1))]);

  int ans = 0, cnt[m], ind, temp[m];
  for (int i = 0; i < m; ++i)
    cnt[i] = 0;
  for (int i = 0; i < n; ++i) {
    long long sum;
    int len = i;
    for (int j = 0; j < m; ++j)
      temp[j] = 0;
    for (int j = logk; j >= 0; j--) {
      sum = 0;
      if (len + (1 << j) > n)
	continue;
      for (int r = 0; r < m; ++r)
	sum += max(st[j][r][len], temp[r]);
      // cout<<sum<<" "<<i<<" "<<len<<" "<<j<<endl;
      if (sum <= k) { 
	for (int r = 0; r < m; ++r)
	  temp[r] =  max(st[j][r][len], temp[r]);
	len += (1 << j);
      }
    }
    if (ans < len - i) {
      ans = len - i;
      ind = i;
    }
  }
  //cout<<ans<<" "<<ind<<" "<<logk<<endl;
  if (ans) {
    for (int i = ind; i < ind + ans; ++i)
      for (int j = 0; j < m; ++j)
	cnt[j] = max(cnt[j], droid[i][j]);
  }
  for (int i = 0; i < m; ++i)
    printf("%d ", cnt[i]);
  puts("");
  return 0;
}
