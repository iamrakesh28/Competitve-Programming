#include <iostream>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
const ll inf = 1e18;

int a[N];

int main() {
  int t;
  scanf("%d", &t);
  
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    ll ans, temp = 0;
    for (int i = 1; i < n; ++i)
      temp += abs(a[i] - a[i - 1]);
    ans = temp;

    for (int i = 0; i < n; ++i) {
      ll adj;
      if (i == 0) {
        ans = min(ans, temp - abs(a[i + 1] - a[i]));
        continue;
      }
      if (i == n - 1) {
        ans = min(ans, temp - abs(a[i - 1] - a[i]));
        continue;
      }
      adj = abs(a[i + 1] - a[i]) + abs(a[i - 1] - a[i]);
      ans = min(ans, temp - adj + abs(a[i - 1] - a[i + 1]));
    }
    
    printf("%lld\n", ans);
  }
  return 0;
}
