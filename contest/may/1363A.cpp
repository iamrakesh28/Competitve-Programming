#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d%d", &n, &x);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
      int val;
      scanf("%d", &val);
      if (val & 1)
	cnt++;
    }
    if (cnt == 0) {
      puts("No");
      continue;
    }
    int val = n - cnt;
    if (val == 0) {
      if (x & 1) {
	puts("Yes");
	continue;
      }
      puts("No");
      continue;
    }
    if (x & 1) {
      if (cnt >= x) {
	puts("Yes");
	continue;
      }
      if ((cnt % 2) == 0)
	cnt--;
      if (cnt + val >= x)
	puts("Yes");
      else
	puts("No");
    }
    else {
      if (cnt % 2 == 0)
	cnt--;
      if (cnt + val >= x)
	puts("Yes");
      else
	puts("No");
    }
  }
  return 0;
}
