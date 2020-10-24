#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, c;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      if (i == 0)
	a = ai;
      else if (i == 1)
	b = ai;
      else if (i == n - 1)
	c = ai;
    }
    if (a + b <= c) {
      printf("1 2 %d\n", n);
    }
    else
      puts("-1");
  }
  return 0;
}
