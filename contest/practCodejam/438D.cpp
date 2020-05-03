#include <iostream>

using namespace std;

typedef long long ll;

const int N = 1e5;
int a[N];
pair <int, pair <int, ll>> t[N << 2];

void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = {a[tl], {tl, a[tl]}};
  else {
    int tm = tl + tr >> 1;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm + 1, tr);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    t[v].second.second = t[2 * v + 1].second.second + t[2 * v + 2].second.second;
  }
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr)
    t[v].first = t[v].second.second = val;
  else {
    int tm = tl + tr >> 1;
    if (pos <= tm)
      update(2 * v + 1, tl, tm, pos, val);
    else
      update(2 * v + 2, tm + 1, tr, pos, val);
    t[v] = max(t[2 * v + 1], t[2 * v + 2]);
    t[v].second.second = t[2 * v + 1].second.second + t[2 * v + 2].second.second;
  }
}

pair <int, pair <int, ll>> query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return {-1, {0, 0}};
  if (l == tl && r == tr)
    return t[v];
  int tm = tl + tr >> 1;
  auto left = query(2 * v + 1, tl, tm, l, min(tm, r));
  auto right = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
  auto ret = max(left, right);
  ret.second.second = left.second.second + right.second.second;
  return ret;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  build(0, 0,  n - 1);
  while (m--) {
    int t, l, r, x;
    scanf("%d", &t);
    if (t == 1) {
      scanf("%d%d", &l, &r);
      auto it = query(0, 0, n - 1, l - 1, r - 1);
      printf("%lld\n", it.second.second);
    }
    else if (t == 2) {
      scanf("%d%d%d", &l, &r, &x);
      auto it = query(0, 0, n - 1, l - 1, r - 1);
      int mx = it.first, id = it.second.first;
      while (mx >= x) {
	//cout<<mx<<" "<<id+1<<endl;
	update(0, 0, n - 1, id, mx % x);
	it = query(0, 0, n - 1, l - 1, r - 1);
	mx = it.first, id = it.second.first;
      }
    }
    else {
      scanf("%d%d", &l, &x);
      update(0, 0, n - 1, l - 1, x);
    }
  }
  return 0;
}
