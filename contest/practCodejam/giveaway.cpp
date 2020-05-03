#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

const int N = 5e5 + 5;
vector <vector <int>> b;
int x[N];

void update(int len, int i, int d) {
  int a = x[i];
  x[i] = d;
  i = i / len;
  auto it = lower_bound(b[i].begin(), b[i].end(), a);
  (*it) = d;
  sort(b[i].begin(), b[i].end());
  return;
}

int query(int l, int r, int c, int len) {
  int ans = 0, cl, cr;
  cl = l / len, cr = r / len;
  if (cl == cr) {
    for (int i = l; i <= r; ++i)
      if (x[i] >= c)
	ans++;
  }
  else {
    for (int i = l, end = (cl + 1) * len - 1; i <= end; ++i)
      if (x[i] >= c)
	ans++;
    for (int i = cl + 1; i <= cr - 1; ++i) {
      auto it = lower_bound(b[i].begin(), b[i].end(), c);
      ans = ans + (b[i].end() - it);
    }
    for (int i = cr * len; i <= r; ++i)
      if (x[i] >= c)
	ans++;
  }
  return ans;
}
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", x + i);
  scanf("%d", &q);
  int len = (int)sqrt(n + .0) + 1;
  b.resize(len);
  for (int i = 0; i < n; ++i)
    b[i / len].push_back(x[i]);
  for (int i = 0; i < len; ++i)
    sort(b[i].begin(), b[i].end());
  while (q--) {
    int o, a, d, c;
    scanf("%d%d%d", &o, &a, &d);
    if (o == 0) {
      scanf("%d", &c);
      int ans = query(a - 1, d - 1, c, len);
      printf("%d\n", ans);
    }
    else {
      a--;
      update(len, a, d);
    }
  }
  return 0;
}
