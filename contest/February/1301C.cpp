#include <iostream>

using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long n, m, even, ans = 0, len;
    scanf("%lld%lld", &n, &m);
    if (m == 0) {
      puts("0");
      continue;
    }
    len = n - m;
    even = len / 2;
    len = len - even;
    ans = m * (m + 1);
    ans = ans >> 1;
    ans = ans + m * len;
    ans = ans + even * (n - even);

    printf("%lld\n", ans);
  }
}
