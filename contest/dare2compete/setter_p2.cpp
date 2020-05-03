#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 5;
int t1[N << 2], t2[N << 2];

// t1 -> up
// t2 -> down

void update(int t[], int v, int tl, int tr, int pos, int val) {
  if (tl == tr) {
    t[v] = val;
    return;
  }
  int tm = tl + tr >> 1;
  if (pos <= tm)
    update(t, 2 * v + 1, tl, tm, pos, val);
  else
    update(t, 2 * v + 2, tm + 1, tr, pos, val);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
}

int query(int t[], int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  int tm = tl + tr >> 1;
  return max(query(t, 2 * v + 1, tl, tm, l, min(tm, r)),
	     query(t, 2 * v + 2, tm + 1, tr, max(l, tm + 1), r));
}

int main() {
  
  memset(t1, 0, sizeof t1);
  memset(t2, 0, sizeof t2);
  int n, d, ans = 0;
  scanf("%d%d", &n, &d);
  for (int i = 0; i < n; ++i) {
    int ai, val1, val2;
    scanf("%d", &ai);
    ai--;
    val1 = query(t2, 0, 0, N - 1, 0, ai - d) + 1;
    val2 = query(t1, 0, 0, N - 1, ai + d, N - 1) + 1;
    ans = max(val1, ans);
    ans = max(val2, ans);
    update(t1, 0, 0, N - 1, ai, val1);
    update(t2, 0, 0, N - 1, ai, val2);
  }
  printf("%d\n", ans);
  return 0;
}
