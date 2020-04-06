#include <iostream>

using namespace std;

int main() {
  int n, m, k, sx, sy;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < (k << 1); ++i)
    scanf("%d%d", &sx, &sy);
  printf("%d\n", 2 * n * m);
  int l = 1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (l)
	putchar('L');
      else
	putchar('R');
    }
    putchar('U');
    l = 1 - l;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m - 1; ++j) {
      if (l)
	putchar('L');
      else
	putchar('R');
    }
    putchar('D');
    l = 1 - l;
  }
  puts("");
  return 0;
}
