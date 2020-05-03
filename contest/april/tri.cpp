#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e6 + 5;
vector <int> pos[N << 2], neg[N << 2], point[N];

void merge(vector <int> &a, vector <int> &b, vector <int> &c) {
  int i = 0, j = 0;
  while (i < a.size() && j < b.size()) {
    if (a[i] < b[j])
      c.push_back(a[i++]);
    else
      c.push_back(b[j++]);
  }
  while (i < a.size())
    c.push_back(a[i++]);
  while (j < b.size())
    c.push_back(b[j++]);
  return;
}

void build(int v, int tl, int tr) {
  if (tl == tr) {
    pos[v].clear();
    neg[v].clear();
    for (int y : point[tl]) {
      pos[v].push_back(tl + y);
      neg[v].push_back(tl - y);
    }
    sort(pos[v].begin(), pos[v].end());
    sort(neg[v].begin(), neg[v].end());
    return;
  }
  pos[v].clear();
  neg[v].clear();
  int tm = tl + tr >> 1;
  build(2 * v + 1, tl, tm);
  build(2 * v + 2, tm + 1, tr);
  merge(pos[2 * v + 1], pos[2 * v + 2], pos[v]);
  merge(neg[2 * v + 1], neg[2 * v + 2], neg[v]);
  return;
}

int query1(int v, int tl, int tr, int l, int r, int slope) {
  if (l > r)
    return 0;
  if (l == tl && r == tr) {
    auto it = lower_bound(neg[v].begin(), neg[v].end(), slope);
    return (neg[v].end() - it);
  }
  int tm = tl + tr >> 1;
  return query1(2 * v + 1, tl, tm, l, min(tm, r), slope) +
    query1(2 * v + 2, tm + 1, tr, max(tm + 1, l), r, slope);
}

int query2(int v, int tl, int tr, int l, int r, int slope) {
  if (l > r)
    return 0;
  if (l == tl && r == tr) {
    auto it = upper_bound(pos[v].begin(), pos[v].end(), slope);
    return (it - pos[v].begin());
  }
  int tm = tl + tr >> 1;
  return query2(2 * v + 1, tl, tm, l, min(tm, r), slope) +
    query2(2 * v + 2, tm + 1, tr, max(tm + 1, l), r, slope);
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int i = 0; i < N; ++i)
      point[i].clear();
    for (int i = 0; i < n; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      point[a].push_back(b);
    }
    build(0, 0, N - 1);
    for (int i = 0; i < q; ++i) {
      int l, r, mid, ans;
      scanf("%d%d", &l, &r);
      mid = l + r >> 1;
      ans = query1(0, 0, N - 1, l, mid, l);
      ans += query2(0, 0, N - 1, mid + 1, r, r);
      printf("%d ", ans);
    }
    puts("");
  }
  return 0;
}
