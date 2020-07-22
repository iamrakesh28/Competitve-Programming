#include <iostream>
#include <cassert>

typedef long long ll;

using namespace std;

const int N = 42;

void Swap(ll x, ll y, ll &ans, ll temp, ll &z) {
  ll prod = (temp & x) * (temp & y);
  if (prod > ans) {
    ans = prod;
    z = temp;
  }
  else if (prod == ans) {
    z = min(z, temp);
  }
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll x, y, l, r, ans = -1, temp, cur = 0, z = 0, a, b;
    scanf("%lld%lld%lld%lld", &x, &y, &l, &r);
    if (x == 0 || y == 0) {
      printf("%lld\n", l);
      continue;
    }
    for (int i = l; i <= r; i++) {
      Swap(x, y, ans, i, z);
    }
    printf("%lld\n", z);
  }
  return 0;
}
