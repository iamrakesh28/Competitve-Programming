#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x1, x2, y1, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    ll ans = 0, mid = min(x2 - x1, y2 - y1), tim;
    ll d1 = x2 - x1, d2 = y2 - y1;
    tim = abs(d1 - d2) + 1;
    ans = mid * tim;
    //cout<<mid<<" "<<tim<<":";
    if (mid > 1)
      d1 = mid * (mid - 1) - 2;
    else
      d1 = 0;
    ans = ans + d1;
    printf("%lld\n", ans + 1);
  }
  return 0;
}
