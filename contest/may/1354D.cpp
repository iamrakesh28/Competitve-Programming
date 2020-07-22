#include <iostream>

using namespace std;

const int N = 1e6 + 5;
int t[N << 2], arr[N];

void build(int v, int l, int r) {
  if (l == r) {
    t[v] = arr[v];
    return;
  }
  int tm = l + r >> 1;
  build(2 * v + 1, l, tm);
  build(2 * v + 2, tm + 1, r);
}

void update(int v, int tl, int tr, int pos, int del) {
  if (tl == tr) {
    if (del)
      t[v]--;
    else
      t[v]++;
    return;
  }
  int tm = tl + tr >> 1;
  if (pos <= tm)
    update(2 * v + 1, tl, tm, pos, del);
  else
    update(2 * v + 2, tm + 1, tr, pos, del);
  t[v] = t[t * v + 1] + t[2 * v + 2];
}

int query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  int tm = tl + tr >> 1;
  return query(2 * v + 1, tl, tm, l, min(r, tm)) +
    query(2 * v + 2, tm + 1, tr, max(tm + 1, l), r);
}

int find(int k) {
  int beg = 0, end = N - 1, ans = -1, mid;
  while (beg <= end) {
    mid = beg + end >> 1;
    int sum = query(0, 0, N - 1, 0, mid);
    if (sum >= k) {
      ans = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }
  return ans;
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i) {
    int ch;
    scanf("%d", &ch);
    arr[ch - 1]++;
  }
  build(0, 0, N - 1);
  while (q--) {
    int k;
    scanf("%d", &k);
    if (k > 0)
      update(0, 0, N - 1, k - 1, 0);
    else {
      int f = find(-k);
      update(0, 0, N - 1, f, 1);
    }
  }
  int ans = find(1);
  if (ans == -1)
    puts("0");
  else
    printf("%d\n", ans + 1);
  return 0;
}
