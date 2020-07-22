#include <iostream>

typedef long long ll;

using namespace std;

const int N = 40;

void Swap(ll &x, ll &y, ll &ans, ll &temp, ll &z) {
  ll prod = (temp & x) * (temp & y);
  if (prod > ans) {
    ans = prod;
    z = temp;
  }
  else if (prod == ans)
    z = min(z, temp);
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll x, y, l, r, ans = -1, temp, cur = 0, z = 0;
    scanf("%lld%lld%lld%lld", &x, &y, &l, &r);
    for (int i = N; i >= 0; i--) {
      if ((1LL << i) & r) {
	temp = 1LL << i;
	temp = temp - 1;
	temp = temp | cur;
	if (temp >= l)
	  Swap(x, y, ans, temp, z);
	cur = cur | (1LL << i);
      }
    }
    printf("%lld\n", z);
  }
  return 0;
}
