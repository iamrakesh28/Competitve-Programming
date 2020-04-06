#include <iostream>
#include <vector>

using namespace std;

const int N = 4e4 + 5;
int a[N], b[N];
vector <int> up, righ;
vector <pair <int, int>> fact;

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  for (int i = 0; i < m; ++i)
    scanf("%d", b + i);
  int cnt = 0;
  for (int i = 0; i < m; ++i) {
    if (b[i] == 1)
      cnt++;
    if (b[i] == 0 && i && b[i - 1]) {
      righ.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt)
    righ.push_back(cnt);
  cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 1)
      cnt++;
    if (a[i] == 0 && i && a[i - 1]) {
      up.push_back(cnt);
      cnt = 0;
    }
  }
  if (cnt)
    up.push_back(cnt);
  for (int i = 1; i * i <= k; ++i) {
    if (k % i)
      continue;
    fact.push_back({i, k / i});
  }
  long long ans = 0;
  m = righ.size();
  n = up.size();
  for (auto it : fact) {
    int l = it.first, r = it.second;
    cnt = 0;
    for (int i = 0; i < m; ++i) {
      if (righ[i] >= l)
	cnt = cnt + righ[i] - l + 1;
    }
    int cnt2 = 0;
    for (int i = 0; i < n; ++i) {
      if (up[i] >= r)
	cnt2 = cnt2 + up[i] - r + 1;
    }
    ans = ans + (long long)cnt * cnt2;
    if (l != r) {
      cnt = 0;
      for (int i = 0; i < m; ++i) {
	if (righ[i] >= r)
	  cnt = cnt + righ[i] - r + 1;
      }
      cnt2 = 0;
      for (int i = 0; i < n; ++i) {
	if (up[i] >= l)
	  cnt2 = cnt2 + up[i] - l + 1;
      }
    ans = ans + (long long)cnt * cnt2;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
