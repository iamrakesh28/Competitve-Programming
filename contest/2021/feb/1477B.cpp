#include <iostream>

using namespace std;

const int N = 2e5 + 5;
char s[N], f[N], lazy[N << 2];
int tree[N << 2];
bool marked[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr) {
    tree[v] = f[tl] - '0';
    marked[v] = false;
    return;
  }

  int tm = (tl + tr) >> 1;
  build(2 * v + 1, tl, tm);
  build(2 * v + 2, tm + 1, tr);

  tree[v] = tree[2 * v + 1] + tree[2 * v + 2];
  marked[v] = false;

  return;
}

void push(int v) {

  if (marked[v]) {
    marked[2 * v + 1] = marked[2 * v + 2] = true;
    marked[v] = false;

    int nodes[] = {2 * v + 1, 2 * v + 2};
    char val = lazy[v];

    for (int node : nodes) {
      if (val == '0')
        tree[v] = 0;
      else
        tree[v] = r - l + 1;
    }
  }
}

void update(int v, int tl, int tr, int l, int r, char val) {
  if (l > r)
    return;

  if (tl == l && tr == r) {
    lazy[v] = val;
    marked[v] = true;
    if (val == '0')
      tree[v] = 0;
    else
      tree[v] = r - l + 1;
    return;
  }

  push(v, val);
  int tm = (tl + tr) >> 1;
  update(2 * v + 1, tl, tm, l, min(tm, r), val);
  update(2 * v + 2, tm + 1, tr, max(l, tm + 1), r, val);

  return;
}
