#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  printf("%d\n", t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    printf("%d %d %d %d\n", n, m, 1, n);
    for (int i = 0; i < n; ++i) {
      int ci;
      scanf("%d", &ci);
      printf("%d %d\n", i, ci);
    }
  }
  return 0;
}
