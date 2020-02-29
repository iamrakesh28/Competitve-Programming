#include <iostream>
#include <algorithm>

using namespace std;
const int N = 1e5 + 5;
int a[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, x, pres = -1;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      if (a[i] == x)
	pres = 1;
    }
    sort(a, a + n);
    int ans = x / a[n - 1];
    if (ans >= 1) {
      if (x % a[n - 1])
	ans++;
      printf("%d\n", ans);
      continue;
    }
    if (pres == 1)
      puts("1");
    else
      puts("2");
  }
  return 0;
}
