#include <iostream>

using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int k;
    bool even = false, num = false;
    scanf("%d", &k);
    for (int i = 0; i < k; ++i) {
      long long val;
      scanf("%lld", &val);
      if ((val & 1) == 0)
	even = true;
      if (val > 3)
	num = true;
    }
    if ((k & 1) == 0) {
      puts("0");
      continue;
    }
    if (even) {
      puts("1");
      continue;
    }
    if (num)
      puts("2");
    else
      puts("-1");
  }
}
