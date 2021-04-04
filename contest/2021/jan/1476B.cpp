#include <iostream>

using namespace std;

typedef long long LL;

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    LL ans = 0, b;
    for (int i = 0; i < n; ++i) {
      int pi;
      scanf("%d", &pi);
      if (i == 0) {
        b = pi;
        continue;
      }

      LL sum = (LL)pi * 100;
      if (sum % k == 0)
        sum = sum / k;
      else
        sum = sum / k + 1;

      ans = max(ans, max((LL)0, sum - b));
      b += pi;
    }

    printf("%lld\n", ans);
  }
  
  return 0;
}
