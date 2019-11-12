#include <iostream>

using namespace std;

int main() {
  int n, k, minm = 2e9, maxm = -2e9, val, first, last;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &val);
    minm = min(minm, val);
    maxm = max(maxm, val);
    if (i == 0)
      first = val;
    if (i == n - 1)
      last = val;
  }
  if (k == 1)
    printf("%d\n", minm);
  else if (k == 2)
    printf("%d\n", max(first, last));
  else
    printf("%d\n", maxm);
  return 0;
}
