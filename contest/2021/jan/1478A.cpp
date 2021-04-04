#include <iostream>

using namespace std;

int a[105];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }

    int ans = 1, cnt = 1;
    for (int i = 1; i < n; ++i) {
      if (a[i] != a[i - 1]) {
        ans = max(ans, cnt);
        cnt = 1;
      }
      else
        cnt++;
    }
    ans = max(ans, cnt);
    printf("%d\n", ans);
  }
  
  return 0;
}
