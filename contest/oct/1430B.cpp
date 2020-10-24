#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    sort(a, a + n);
    reverse(a, a + n);
    long long ans = a[0];
    for (int i = 1; i <= k; ++i)
      ans += a[i];
    printf("%lld\n", ans);
  }
  return 0;
}
