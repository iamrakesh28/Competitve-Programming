#include <iostream>

typedef long long ll;
using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, c, d;
    ll ans;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a <= b) {
      printf("%d\n", b);
      continue;
    }
    ans = b;
    if (c <= d) {
      puts("-1");
      continue;
    }
    int eff = c - d, rem = a - b, cnt;
    cnt = rem / eff;
    if (cnt * eff != rem)
      cnt++;
    ans = ans + (ll)cnt * c;
    printf("%lld\n", ans);
  }
  return 0;
}
