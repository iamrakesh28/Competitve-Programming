#include <iostream>

using namespace std;

const int N = 1e5;
int a[N];
double t[N << 2], add[N << 2], mul[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    mul[v] = 1;
  }
  else {
    int tm = tl + tr >> 1;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm + 1, tr);
    t[v] = t[2 * v + 1] + t[2 * v + 2];
    mul[v] = 1;
  }
}

void push(int v, int tl, int tr) {
  t[v * 2 + 1] *= mul[v];
  t[v * 2 + 2] *= mul[v];
  mul[v * 2 + 1] *= mul[v];
  mul[v * 2 + 2] *= mul[v];
  add[v * 2 + 1] *= mul[v];
  add[v * 2 + 2] *= mul[v];
  mul[v] = 1;
  int tm = (tl + tr) / 2;
  t[v * 2 + 1] += (double)(tm - tl + 1)*add[v];
  t[v * 2 + 2] += (double)(tr - tm)*add[v];
  add[v * 2 + 1] += add[v];
  add[v * 2 + 2] += add[v];
  add[v] = 0;

}

void update(int v, int tl, int tr, int l, int r, double val_add, double val_mul) {
  if (l > r)
    return;
  if (l == tl && r == tr) {
    t[v] = (r - l + 1) * val_add + val_mul * t[v];
    add[v] *= val_mul;
    add[v] += val_add;
    mul[v] *= val_mul;
    return;
  }
  push(v, tl, tr);
  int tm = tl + tr >> 1;
  update(2 * v + 1, tl, tm, l, min(tm, r), val_add, val_mul);
  update(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val_add, val_mul);
  t[v] = t[2 * v + 1] + t[2 * v + 2];
}

double query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  push(v, tl, tr);
  int tm = tl + tr >> 1;
  return query(2 * v + 1, tl, tm, l, min(r, tm))
    + query(2 * v + 2, tm + 1, tr, max(tm + 1, l), r);
}

int main() {
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  build(0, 0, n - 1);
  while (q--) {
    int t;
    scanf("%d", &t);
    if (t == 1) {
      int l1, r1, l2, r2;
      scanf("%d%d%d%d", &l1, &r1, &l2, &r2);
      double val1, val2, temp;
      val1 = query(0, 0, n - 1, l1 - 1, r1 - 1) / double(r1 - l1 + 1);
      val2 = query(0, 0, n - 1, l2 - 1, r2 - 1) / double(r2 - l2 + 1);
      //mp = val2;
      val2 = val2 / double(r1 - l1 + 1);
      val1 = val1 / double(r2 - l2 + 1);
      update(0, 0, n - 1, l1 - 1, r1 - 1, val2, double(r1 - l1) / double(r1 - l1 + 1));
      update(0, 0, n - 1, l2 - 1, r2 - 1, val1, double(r2 - l2) / double(r2 - l2 + 1));
    }
    else {
      int l, r;
      scanf("%d%d", &l, &r);
      printf("%lf\n", query(0, 0, n - 1, l - 1, r - 1));
    }
  }
  return 0;
}
