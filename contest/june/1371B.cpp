#include <iostream>

typedef long long ll;
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll n, r;
    scanf("%lld%lld", &n, &r);
    ll ans = 0;
    /* for (int i = 0; i < r; ++i) {
      if (n <= i + 1) {
	continue;
      }
      ans = ans + i + 1;
      }*/
    if (n <= r)
      ans++;
    ll temp = min(n, r);
    if (n <= r)
      temp--;
    temp = temp * (temp + 1);
    temp = temp >> 1;
    ans = ans + temp;
    printf("%lld\n", ans);
  }
  return 0;
}
