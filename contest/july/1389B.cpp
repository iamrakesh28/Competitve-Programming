#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, z;
    scanf("%d%d%d", &n, &k, &z);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    ll ans = a[0], cur = a[0], val = 0;
    for (int i = 1; i <= k; ++i) {
      int rem = k - i;
      cur += a[i];
      val = max(val, (ll)a[i] + a[i - 1]);
      if (rem & 1) {
	rem = rem >> 1;
	if (rem <= z - 1)
	  ans = max(ans, cur + rem * val + a[i - 1]);
      }
      else {
	rem = rem >> 1;
	if (rem <= z)
	  ans = max(ans, cur + rem * val);
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
