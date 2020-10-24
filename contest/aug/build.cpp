#include <iostream>

using namespace std;
const int N = 105;
int ans[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int h = 0; h < t; ++h) {
    int n, a, b, c, tot;
    scanf("%d%d%d%d", &n, &a, &b, &c);
    bool poss = false;
    tot = a + b - c;
    if (tot > n) {
      printf("Case #%d: IMPOSSIBLE\n", h + 1);
      continue;
    }
    for (int i = 1; i <= n; ++i) {
      int left, right;
      tot = n - a - b + c;
      left = a - c;
      right = b - c;
      if (left || right) {
      }
    }
    printf("Case #%d: ", h + 1);
    if (poss) {
      for (int i = 0; i < n; ++i)
	printf("%d ", ans[i]);
      puts("");
    }
    else
      puts("IMPOSSIBLE");
  }
  return 0;
}
