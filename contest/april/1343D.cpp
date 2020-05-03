#include <iostream>

using namespace std;

const int N = 2e5 + 5, inf = 1e9;

int a[N], bit[N << 2];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    for (int i = 0; i <= 2 * k; ++i)
      bit[i] = 0;
    for (int i = 0; i < n / 2; ++i) {
      int sum = a[i] + a[n - i - 1], mn, mx;
      if (a[i] < a[n - i - 1]) {
	mx = a[n - i - 1] + k;
	mn = a[i] + 1;
      }
      else {
	mx = a[i] + k;
	mn = a[n - i - 1] + 1;
      }
      bit[sum - 1] -= 1;
      bit[mn - 1] += 1;
      bit[sum] += 1;
      bit[mx] -= 1;
      bit[mx] += 2;
      bit[0] += 2;
      bit[mn - 1] -= 2;
    }
    for (int i = 1; i <= 2 * k; ++i)
      bit[i] += bit[i - 1];
    int ans = inf;
    for (int i = 1; i < 2 * k; ++i)
      ans = min(ans, bit[i]);
    printf("%d\n", ans);
  }
  return 0;
}
