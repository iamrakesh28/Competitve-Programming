#include <iostream>
#include <cmath>
#include <set>

typedef long long ll;

using namespace std;

const int prime = 1e9 + 7, N = 1e6;
set <ll> power;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    ll n, ans, sq, cb;
    scanf("%lld", &n);
    ans = n % prime;
    sq = sqrt(n);
    cb = cbrt(n);
    power.clear();
    for (ll x = 2; x * x  <= n; ++x) {
      ll temp = x * x, t1;
      for (; temp <= n; temp *= x) {
	if (power.find(temp) != power.end())
	  continue;
	t1 = n / temp;
	ans = ans + t1 * temp;
	ans = ans % prime;
	power.insert(temp);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
