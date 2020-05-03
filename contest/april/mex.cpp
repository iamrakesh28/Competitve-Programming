#include <iostream>
#include <set>

typedef long long ll;
using namespace std;

const int prime = 998244353;
multiset <int> s;

ll power(ll n, ll a) {
  ll r = 1;
  while (n) {
    if (n & 1)
      r = r * a % prime;
    a = a * a % prime;
    n >>= 1;
  }
  return r;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, cnt = 0;
    ll ans = 0, mul = 1;
    scanf("%d", &n);
    s.clear();
    for (int i = 0; i < n; ++i) {
      int val;
      scanf("%d", &val);
      s.insert(val);
    }
    for (int i = 1; i <= n; ++i) {
      auto it = s.begin();
      int val = *it;
      ll temp;
      if (val > i) {
	temp = power(n - cnt, 2);
	temp = temp * mul % prime;
	temp = temp * i % prime;
	ans = (ans + temp) % prime;
	break;
      }
      val = s.count(i);
      cnt += val;
      while (s.count(i) > 0) {
	it = s.begin();
	s.erase(it);
      }
      temp = power(n - cnt, 2);
      temp = temp * mul % prime;
      temp = temp * i % prime;
      ans = (ans + temp) % prime;
      temp = power(val, 2);
      temp = (temp - 1 + prime) % prime;
      mul = temp * mul % prime;
      //cout<<ans<<endl;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
