#include <iostream>

using namespace std;

const int N = 17;
int a[1 << N];
pair <int, int> t[2 * (1 << N)];

void build(int v, int tl, int tr) {
  if (tl == tr)
    t[v] = {a[tl], 0};
  else {
    int tm = (tl + tr) / 2;
    build(2 * v + 1, tl, tm);
    build(2 * v + 2, tm + 1, tr);
    if (t[2 * v + 1].second)
      t[v] = {t[2 * v + 1].first ^ t[2 * v + 2].first, 0};
    else
      t[v] = {t[2 * v + 1].first | t[2 * v + 2].first, 1};
  }
}

void update(int v, int tl, int tr, int pos, int val) {
  if (tl == tr)
    t[v].first = val;
  else {
    int tm = (tl + tr) >> 1;
    if (pos <= tm)
      update(2 * v + 1, tl, tm, pos, val);
    else
      update(2 * v + 2, tm + 1, tr, pos, val);
    if (t[v].second)
      t[v].first = t[2 * v + 1].first | t[2 * v + 2].first;
    else
      t[v].first = t[2 * v + 1].first ^ t[2 * v + 2].first;
  }
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < (1 << n); ++i)
    scanf("%d", a + i);
  build(0, 0, (1 << n) - 1);
  //cout<<t[0].first<<endl;
  while (m--) {
    int p, b;
    scanf("%d%d", &p, &b);
    update(0, 0, (1 << n) - 1, p - 1, b);
    int ans = t[0].first;
    printf("%d\n", ans);
  }
  return 0;
}
