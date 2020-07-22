#include <iostream>

using namespace std;


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x = 0, y = 0;
    scanf("%d", &n);
    for (int i = 0; i < 4 * n - 1; ++i) {
      int xi, yi;
      scanf("%d%d", &xi, &yi);
      x = xi ^ x;
      y = yi ^ y;
    }

    printf("%d %d\n", x, y);
  }
  return 0;
}
