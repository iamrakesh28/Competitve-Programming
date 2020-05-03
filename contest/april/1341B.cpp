#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, c, d, mn, mx, sn, sx;
    scanf("%d%d%d%d%d", &n, &a, &b, &c, &d);
    mn = (a - b) * n;
    mx = (a + b) * n;
    sn = c - d;
    sx = c + d;
    if (sx < mn) {
      puts("No");
      continue;
    }
    if (sn > mx) {
      puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}
