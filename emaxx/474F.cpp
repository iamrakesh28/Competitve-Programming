#include <iostream>

#define mk make_pair

using namespace std;

const int N = 1e5;
int s[N];
pair <int, int> t[4 * N];

int gcd(int a, int b) {
  if (a == 0)
    return b;
  return gcd(b % a, a);
}

void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = {s[tl], 1};
  else {
    int tm = (tl + tr) >> 1;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm + 1, tr);
    if (t[2 * v + 1].first == t[2 * v + 2].first)
      t[v] = {t[2 * v + 1].first, t[2 * v + 1].second + t[2 * v + 2].second};
    else {
      int g = gcd(t[2 * v + 1].first, t[2 * v + 2].first);
      t[v] = {g, 0};
      if (g == t[2 * v + 1].first)
	t[v].second = t[2 * v + 1].second;
      else if (g == t[2 * v + 2].first)
	t[v].second = t[2 * v + 2].second;
    }
  }
}

pair <int, int> query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return mk(0, 0);
  if (l == tl && r == tr)
    return t[v];
  int tm = (tl + tr) >> 1, g;
  pair <int, int> p1, p2;
  p1 = query(2 * v + 1, tl, tm, l, min(r, tm));
  p2 = query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r);
  if (p1.first == p2.first)
    return mk(p1.first, p1.second + p2.second);
  g = gcd(p1.first, p2.first);
  if (g == p1.first)
    return mk(g, p1.second);
  if (g == p2.first)
    return mk(g, p2.second);
  return mk(g, 0);
}

int main() {

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", s + i);
  build(0, 0, n - 1);
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    int ans = query(0, 0, n - 1, l - 1, r - 1).second;
    //cout<<ans<<endl;
    ans = r - l + 1 - ans;
    printf("%d\n", ans);
  }
  return 0;
}
