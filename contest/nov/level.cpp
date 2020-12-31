#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n, k, s;
    scanf("%d%d%d", &n, &k, &s);
    int restart = n + 1, cont = k - s + n - s + 1;
    printf("Case #%d: %d\n", q + 1, min(restart, cont) + k - 1);
  }
  return 0;
}
