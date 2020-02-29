#include <iostream>

using namespace std;

char s[3005];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d%s", &n, s);
    int i = n - 1;
    bool f = false;
    while (i >= 0) {
      if ((s[i] - '0') & 1) {
	f = true;
	break;
      }
      s[i] = '\0';
      n--;
      i--;
    }
    if (f == false) {
      puts("-1");
      continue;
    }
    int even = 0, odd = -1;
    for (i = 0; i < n; ++i) {
      even = even + (s[i] - '0');
      even = even % 2;
      if (i == n - 1)
	continue;
      if ((s[i] - '0') & 1)
	odd = i;
    }
    if (even == 0) {
      for (i = 0; i < n; ++i)
	putchar(s[i]);
      puts("");
      continue;
    }
    if (odd == -1) {
      puts("-1");
      continue;
    }
    if (n == 1) {
      puts("-1");
      continue;
    }
    for (i = 0; i < n; ++i)
      if (i != odd)
	putchar(s[i]);
    puts("");
  }
  return 0;
}
