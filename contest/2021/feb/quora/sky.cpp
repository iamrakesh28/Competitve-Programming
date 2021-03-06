#include <iostream>

using namespace std;

const int N = 3e5 + 5;
int t[N << 2], lazy[N << 2], h[N];
bool marked[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = h[tl];
    marked[v] = false;
    return;
  }

  int tm = (tl + tr) >> 1;
  build(2 * v + 1, tl, tm);
  build(2 * v + 2, tm + 1, tr);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
 
  return;
}

void push(int v) {
  if (marked[v]) {
    lazy[2 * v + 1] = lazy[2 * v + 2] = lazy[v];
    t[2 * v + 1] = t[2 * v + 2] = lazy[v];
    marked[2 * v + 1] = marked[2 * v + 2] = true;
    marked[v] = false;
  }
}

void update(int v, int tl, int tr, int l, int r, int x) {
  if (l > r)
    return;
  if (tl == l && tr == r) {
    t[v] = lazy[v] = x;
    marked[v] = true;
    return;
  }
  push(v);
  int tm = (tl + tr) >> 1;
  update(2 * v + 1, tl, tm, l, min(tm, r), x);
  update(2 * v + 2, tm + 1, tr, max(tm + 1, l), r, x);

  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  
  return;
}

int query(int v, int tl, int tr, int l, int r) {

  if (l > r)
    return -1;
  if (l == tl && r == tr)
    return t[v];

  push(v);
  int tm = (tl + tr) >> 1;
  return max(query(2 * v + 1, tl, tm, l, min(tm, r)),
             query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r));

}

int solve(int i, int n) {

  int range = 1, hi = query(0, 0, n - 1, i, i);
  int beg = i, end = n - 1, ans1;
  while (beg <= end) {
    int mid = (beg + end) >> 1;
    if (query(0, 0, n - 1, i, mid) <= hi) {
      ans1 = mid;
      beg = mid + 1;
    }
    else
      end = mid - 1;
  }

  int ans2;
  beg = 0, end = i;
  while (beg <= end) {
    int mid = (beg + end) >> 1;
    // cout << i + 1 << " " << mid << " " << query(0, 0, n - 1, 0, mid) << " " << hi << endl;
    if (query(0, 0, n - 1, mid, i) <= hi) {
      ans2 = mid;
      end = mid - 1;
    }
    else
      beg = mid + 1;
  }

  // cout << ans1 << " " << ans2 << endl;
  range = ans1 - ans2 + 1;
    
  return range;
}

inline int scan() {

  char ch = getchar_unlocked();
  int x = 0;
  while (!(ch == '\n' || ch == ' ')) {
    x = 10 * x + (ch - '0');
    ch = getchar_unlocked();
  }

  return x;
}

int main() {

  int n, q;
  n = scan();
  q = scan();
  // cout << n << " " << q << endl;
  for (int i = 0; i < n; ++i)
    h[i] = scan();

  build(0, 0, n - 1);
  while (q--) {
    int id, i;
    id = scan();
    i = scan();
    if (id == 1) {
      printf("%d\n", solve(i - 1, n));
    }
    else if (id == 2) {
      int x;
      x = scan();
      update(0, 0, n - 1, i - 1, i - 1, x);
    }
    else {
      int j, x;
      j = scan();
      x = scan();
      update(0, 0, n - 1, i - 1, j - 1, x);
    }
  }
  return 0;
}
