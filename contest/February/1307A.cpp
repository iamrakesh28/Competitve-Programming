#include <iostream>

using namespace std;

int a[105];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, d, ans;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    ans = a[0];
    for (int i = 1; i < n; ++i) {
      if (d <= 0)
	break;
      if (a[i]) {
	int mv = d / i;
	mv = min(a[i], mv);
	d = d - mv * i;
	ans = ans + mv;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
