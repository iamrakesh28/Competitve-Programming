#include <iostream>

using namespace std;

typedef long long LL;
const int N = 1e5 + 5;
const LL inf = 1e17;

int c[N], a[N], b[N];
LL cycle[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
      scanf("%d", c + i);

    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);

    for (int i = 0; i < n; ++i)
      scanf("%d", b + i);

    LL ans = 0;
    cycle[0] = -inf;
    for (int i = 1; i < n; ++i) {

      if (a[i] == b[i]) {
        cycle[i] = c[i] - 1 + 2;
        ans = max(ans, cycle[i]);
        continue;
      }

      // new cycle
      cycle[i] = c[i] - 1 + (LL)abs(a[i] - b[i]) + 2;

      LL ai = min(a[i], b[i]);
      LL bi = max(a[i], b[i]);
      
      LL temp = c[i] - 1 + 2;
      temp = temp + ai - 1;
      temp = temp + c[i - 1] - bi;
      temp = temp - (c[i - 1] - 1);
      
      cycle[i] = max(cycle[i], cycle[i - 1] + temp);
      ans = max(ans, cycle[i]);
    }
   
    printf("%lld\n", ans);
  }
  
  return 0;
}
