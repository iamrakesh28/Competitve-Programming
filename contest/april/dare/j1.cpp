#include <iostream>
#include <set>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
int a[N], b[N];
multiset <int> s, s1;

int main() {
  int n, m, x, y, z;
  ll sum = 0;
  scanf("%d%d%d%d%d", &n, &m, &x, &y, &z);
  for (int i = 0; i < x; ++i)
    scanf("%d", a + i);
  for (int i = 0; i < y; ++i)
    scanf("%d", b + i);
  sort(a, a + x);
  reverse(a, a + x);
  sort(b, b + y);
  reverse(b, b + y);
  for (int i = 0; i < n; ++i) {
    sum += a[i];
    s1.insert(a[i]);
  }
  for (int i = 0; i < m; ++i) {
    sum += b[i];
    s1.insert(b[i]);
  }
  for (int i = 0; i < z; ++i) {
    int val;
    scanf("%d", &val);
    s.insert(val);
  }
  while (s.size()) {
    auto it = s.end();
    it--;
    int v1 = *it;
    s.erase(it);
    it = s1.begin();
    int v2 = *it;
    if (v2 >= v1)
      break;
    s1.erase(it);
    s1.insert(v1);
    sum = sum - v2 + v1;
  }
  printf("%lld\n", sum);
  return 0;
}
