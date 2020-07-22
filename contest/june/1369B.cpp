#include <iostream>

using namespace std;

const int N = 1e5 + 5;
char S[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%s", &n, S);
    int f = n, l = n, rest = 0;
    for (int i = 0; i < n; ++i)
      if (S[i] == '1') {
	f = i;
	break;
      }
    for (int i = n - 1; i >= 0; --i)
      if (S[i] == '0') {
	l = n - i - 1;
	break;
      }
    for (int i = 0; i < f; ++i)
      putchar('0');
    if (n > f + l)
      putchar('0');
    for (int i = 0; i < l; ++i)
      putchar('1');
    puts("");
  }
  return 0;
}
