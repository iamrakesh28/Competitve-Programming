#include <iostream>

typedef long long ll;
using namespace std;

const int prime = 1e9 + 7;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    ll ans;
    scanf("%d%d", &n, &k);
    if (n == 0) {
      ll num = k - 1;
      ans = num * (num + 1);
      ans = ans % prime;
      printf("%lld\n", ans);
      continue;
    }
    // 1st
    ans = (ll)(n - 1) * n;
    ans = ans % prime;
    if (k == 1) {
      ans += n;
      ans = ans % prime;
      printf("%lld\n", ans);
      continue;
    }
    k--;
    //ans += (n + n);
    ll val;
    if (k & 1) {
      int num = k / 2;
      val = (ll)n + num;
      val = val % prime;
      ans = (val + 1) * val;
      ans = ans % prime;
      ans += n;
      ans = ans % prime;
    }
    else {
      k -= 2;
      ll num = k / 2;
      val = (ll)n + num;
      val = val % prime;
      ans = (val + 1) * val;
      ans = ans % prime;
      ans += (num + n + 1);
      ans += (num + 1);
      ans = ans % prime;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
