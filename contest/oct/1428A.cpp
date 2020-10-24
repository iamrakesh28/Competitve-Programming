#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x1, y1, x2, y2, ans;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    ans = abs(x1 - x2) + abs(y1 - y2);
    if (x1 != x2 && y1 != y2)
      ans += 2;
    printf("%d\n", ans);
  }
  return 0;
}
