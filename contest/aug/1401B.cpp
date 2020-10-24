#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x1, y1, z1, x2, y2, z2;
    scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
    ll ans = 0;
    if (z1) {
      int mn = min(z1, y2);
      ans = 2 * mn;
      z1 = z1 - mn;
      y2 = y2 - mn;
    }
    if (z2) {
      z2 = z2 - min(z2, z1);
      z2 = z2 - min(z2, x1);
    }
    ll temp;
    temp = -2 * min(z2, y1);
    ans = ans + temp;
    printf("%lld\n", ans);
  }
  return 0;
}
