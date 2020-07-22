#include <iostream>
#include <cassert>

typedef long long ll;

using namespace std;

const int N = 42;

void Swap(ll x, ll y, ll &ans, ll temp, ll &z, int n, ll l) {
  ll prod = (temp & x) * (temp & y), val;
  if (prod > ans) {
    ans = prod;
    for (int i = n; i >= 0; i--) {
      if ((1LL << i) & temp) {
	ll val = temp ^ (1LL << i);
	if (val < l)
	  continue;
	prod = (val & x) * (val & y);
	if (prod < ans)
	  continue;
	temp = val;
      }
    }
    z = temp;
  }
  else if (prod == ans) {
    for (int i = n; i >= 0; i--) {
      if ((1LL << i) & temp) {
	ll val = temp ^ (1LL << i);
	if (val < l)
	  continue;
	prod = (val & x) * (val & y);
	if (prod < ans)
	  continue;
	temp = val;
      }
    }
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
    for (int i = N; i >= 0; i--) {
      temp = 1LL << i;
      if (temp & r) {
	temp = temp - 1;
	temp = temp | cur;
	if (temp >= l)
	  Swap(x, y, ans, temp, z, i - 1, l);
	cur = cur | (1LL << i);
      }
    }
    Swap(x, y, ans, cur, z, -1, l);
    printf("%lld\n", z);
  }
  return 0;
}
