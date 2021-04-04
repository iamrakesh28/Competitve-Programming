#include <iostream>

using namespace std;

int a[55];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
      int mx = max(a[i], a[i + 1]);
      int mn = min(a[i], a[i + 1]);
      if (mx <= 2 * mn)
        continue;

      int val = mn, cnt = 0;
      while (2 * val < mx) {
        val = val << 1;
        cnt ++;
      }

      ans += cnt;
    }

    printf("%d\n", ans);
  }
  
  return 0;
}
