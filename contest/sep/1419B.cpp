#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const ll inf = 1e18 + 10;
vector <ll> size;

int main() {
  ll r = 2, val = 1;
  while (val < inf) {
    size.push_back(val);
    val = val + r;
    r = r << 1;
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    ll x;
    scanf("%lld", &x);
    int ans = 0;
    ll sum = 0;
    for (ll v : size) {
      ll val = v * (v + 1) / 2;
      sum += val;
      if (sum > x)
	break;
      ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
