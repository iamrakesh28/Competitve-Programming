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

int queryR(int v, int tl, int tr, int i, int hi) {

  if (i > tr)
    return -1;

  push(v);
  if (t[v] <= hi) {
    return tr;
  }
  if (tl == tr)
    return -1;
  
  int tm = (tl + tr) >> 1;
  int m2 = queryR(2 * v + 2, tm + 1, tr, i, hi);
  // cout << tm + 2 << " " << tr + 1 << " " << i + 1 << " m2: " << m2 << endl;
  if (i >= tm + 1)
    return m2;
  
  int m1 = queryR(2 * v + 1, tl, tm, i, hi);
  // cout << tm + 1 << " " << i + 1 << " m1: " << m1 << endl;
  if (m1 < tm)
    return m1;

  return max(m1, m2);

}

int queryL(int v, int tl, int tr, int i, int hi) {

  if (i < tl)
    return 1e9;

  push(v);
  if (t[v] <= hi) {
    return tl;
  }
  if (tl == tr)
    return 1e9;
  
  int tm = (tl + tr) >> 1;
  int m1 = queryL(2 * v + 1, tl, tm, i, hi);
  // cout << tm + 2 << " " << tr + 1 << " " << i + 1 << " m2: " << m2 << endl;
  if (i <= tm)
    return m1;
  
  int m2 = queryL(2 * v + 2, tm + 1, tr, i, hi);
  // cout << tm + 1 << " " << i + 1 << " m1: " << m1 << endl;
  if (m2 > tm + 1)
    return m2;

  return min(m1, m2);

}

int solve(int i, int n) {

  int range, hi = query(0, 0, n - 1, i, i), ans2;
  int ans1 = queryR(0, 0, n - 1, i, hi);
  ans2 = queryL(0, 0, n - 1, i, hi);
  range = ans1 - ans2 + 1;
    
  return range;
}

int main() {

  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", h + i);

  build(0, 0, n - 1);
  while (q--) {
    int id, i;
    scanf("%d%d", &id, &i);
    if (id == 1) {
      printf("%d\n", solve(i - 1, n));
    }
    else if (id == 2) {
      int x;
      scanf("%d", &x);
      update(0, 0, n - 1, i - 1, i - 1, x);
    }
    else {
      int j, x;
      scanf("%d%d", &j, &x);
      update(0, 0, n - 1, i - 1, j - 1, x);
    }
  }
  return 0;
}
