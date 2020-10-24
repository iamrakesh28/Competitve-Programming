#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int a, b, ans = 0;
    scanf("%d%d", &a, &b);
    for (int i = 30; i >= 0; i--) {
      int bita = 0, bitb = 0;
      if ((1 << i) & a)
	bita = 1;
      if ((1 << i) & b)
	bitb = 1;
      int bit = bita ^ bitb;
      if (bit)
	ans = ans | (1 << i);
    }
    printf("%d\n", ans);
  }
  return 0;
}
