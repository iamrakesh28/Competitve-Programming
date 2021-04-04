#include <iostream>

using namespace std;

char s[105];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d%s", &n, &k, s);

    if (2 * k + 1 > n) {
      puts("NO");
      continue;
    }

    int cnt = 0;
    int mid = n >> 1;
    for (int i = 0; i < mid; ++i) {
      if (s[i] != s[n - i - 1]) {
        break;
      }
      cnt++;
    }

    if (cnt >= k)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
