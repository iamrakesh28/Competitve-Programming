#include <iostream>
#include <algorithm>

using namespace std;

int a[105];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, d;
    bool less = true;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
      if (a[i] > d)
        less = false;
    }

    sort(a, a + n);
    int sum = a[0] + a[1];
    if (sum <= d || less)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
