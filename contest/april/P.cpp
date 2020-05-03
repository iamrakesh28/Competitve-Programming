#include <iostream>
#include <cmath>
#include <set>

typedef long long ll;

using namespace std;

const int prime = 1e9 + 7;
set <ll> power;

ll modInverse(ll a) {
  ll r = 1, n = prime - 2;
  while (n) {
    if (n & 1)
      r = r * a % prime;
    a = a * a % prime;
    n >>= 1;
  }
  return r;
}

int main() {
  int q;
  ll mod = modInverse(6);
  __int128 test;
  scanf("%d", &q);
  while (q--) {
    ll n, ans, sq, cb;
    scanf("%lld", &n);
    ans = n % prime;
    sq = sqrt(n);
    cb = cbrt(n);
    power.clear();
    for (ll x = 2; x * x * x <= n; ++x) {
      test = x * x * x;
      ll temp, t1;
      for (; test <= n; test *= x) {
	temp = test;
	if (power.find(temp) == power.end()) {
	  power.insert(temp);
	  sq = sqrt(temp);
	  if (sq * sq != temp) {
	    t1 = n / temp;
	    ans = ans + t1 * temp;
	    ans = ans % prime;
	  }
	}
      }
    }
    ll temp, b = cb, lg = ans;
    //cout<<cb<<": ";
    for (ll x = 2; x <= b; ++x) {
      temp = n / (x * x);
      temp = temp * x * x;
      ans = ans + temp;
      ans = ans % prime;
    }
    ll sum1, sum2, lb, ub, lbs, ubs, prev = b;
    for (ll x = b; x >= 1; --x) {
      lb = n / (x + 1);
      ub = n / x;
      lbs = sqrt(lb);
      if (lbs * lbs != lb)
	lbs++;
      if (lbs == 0)
	lbs++;
      ubs = sqrt(ub);
      //cout<<lbs<<" : "<<ubs<<endl;
      if (lbs > ubs)
	continue;
      sum2 = ubs * (ubs + 1) % prime;
      sum2 = sum2 * (2 * ubs + 1) % prime;
      sum2 = sum2 * mod % prime;
      sum1 = lbs * (lbs + 1) % prime;
      sum1 = sum1 * (2 * lbs + 1) % prime;
      sum1 = sum1 * mod % prime;
      
      if (prev != lbs)
	sum1 = sum1 - (lbs * lbs) % prime;
      sum2 -= sum1;
      sum2 = sum2 + prime % prime;
      sum2 = x * sum2 % prime;
      sum2 = (sum2 + prime) % prime;
      ans = (ans + sum2) % prime;
      prev = ubs;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
