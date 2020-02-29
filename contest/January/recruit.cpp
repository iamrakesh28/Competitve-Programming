#include <iostream>

using namespace std;

int main() {
  int n, m, c;
  long long sum1 = 0, sum2 = 0;
  scanf("%d%d%d", &n, &m, &c);
  for (int i = 0; i < n; ++i) {
    int x, y, p, yx;
    scanf("%d%d%d", &x, &y, &p);
    yx = m * x + c;
    if (yx > y)
      sum2 = sum2 + p;
    else
      sum1 = sum1 + p;
  }
  printf("%ld\n", max(sum1, sum2));
  return 0;
}
