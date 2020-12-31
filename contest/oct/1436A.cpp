#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      sum += ai;
    }
    if (sum == m)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
