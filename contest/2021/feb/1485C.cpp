#include <iostream>
#include <cmath>

using namespace std;

using LL = long long;

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int x, y;
    scanf("%d%d", &x, &y);

    LL ans = 0;
    int a = 1;
    while (a <= x) {

      int b = 1;
      LL prod = (LL)a * (a - 1);
      if (prod < x)
        break;
      
      for (; b <= y && b + 1 <= a; ++b) {
        if (a % (b + 1) == 0) {
          int div = a / (b + 1);
          if (div < b)
            ans++;
        }
      }
      a++;
    }

    printf("%lld\n", ans);
  }
  
  return 0;
}
