#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, k, c, ans = 0;
    scanf("%d%d%d", &n, &m, &k);
    c = n / k;
    if (m > c) {
      int rem = k - 1;
      ans = c;
      m = m - c;
      if (m % rem)
	ans = ans - m / rem - 1;
      else
	ans = ans - m / rem;
    }
    else
      ans = m;
    printf("%d\n", ans);
  }
  return 0;
}
