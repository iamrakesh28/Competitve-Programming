#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
ll a[N], b[N];

ll gcd(ll a, ll b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

int main() {
  int n, m, index;
  ll small = -1;

  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; ++i) {
    scanf("%lld", a + i);

    if (small == -1 || small > a[i]) {
      small = a[i];
      index = i;
    }
  }

  for (int i = 0; i < m; ++i)
    scanf("%lld", b + i);

  ll gc = 0;
  for (int i = 0; i < n; ++i) {
    if (index == i)
      continue;
    gc = gcd(gc, a[i] - small);
  }

  ll ans;
  for (int i = 0; i < m; ++i) {
    ans = gcd(gc, small + b[i]);
    printf("%lld ", ans);
  }
  puts("");
  return 0;
}
