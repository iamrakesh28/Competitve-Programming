#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
int a[N];
ll dp[N], t[N << 2];

void build(int n) {
  for (int i = 0; i < 4 * n; ++i)
    t[i] = 0;
  return;
}

void update(int v, int tl, int tr, int pos, ll val) {
  if (tl == tr) {
    t[v] = val;
    dp[v] = val;
    return;
  }
  int mid = (tl + tr) >> 1;
  if (pos <= mid)
    update(2 * v + 1, tl, mid, pos, val);
  else
    update(2 * v + 2, mid + 1, tr, pos, val);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}

ll query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (tl == l && tr == r)
    return t[v];
  int mid = (tl + tr) >> 1;
  return max(query(2 * v + 1, tl, mid, l, min(r, mid)),
	     query(2 * v + 2, mid + 1, tr, max(l, mid + 1), r));
}


int main() {
  int n, d, m;
  scanf("%d%d%d", &n, &d, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  build(n);
  for (int i = n - 1; i >= 0; i--) {
    if (a[i] <= m) {
      ll val = query(0, 0, n - 1, i + 1, n - 1);
      update(0, 0, n - 1, i, val + a[i]);
      continue;
    }
    ll val1 = query(0, 0, n - 1, i + 1, n - 1);
    ll val2 = query(0, 0, n - 1, i + d + 1, n - 1);
    val2 = val2 + a[i];
    update(0, 0, n - 1, i, max(val1, val2));
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans = max(ans, dp[i]);
  printf("%lld\n", ans);
  return 0;
}
