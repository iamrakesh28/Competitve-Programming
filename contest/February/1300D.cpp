#include <iostream>

using namespace std;

int main() {
  int n;
  int poss = 1;
  long long d, a, b, a1, b1;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    if (i >= 2) {
      long long temp = (x - a) * (x - a) + (y - b) * (y - b);
      if (temp != d)
	poss = -1;
      a = x, b = y;
    }
    else if (i == 1) {
            d = (x - a) * (x - a) + (y - b) * (y - b);
	    a = x, b = y;
    }
    else {
      a = x, b = y;
      a1 = a, b1 = b;
    }
  }
  long long temp = (a - a1) * (a - a1) + (b - b1) * (b - b1);
  if (temp != d)
    poss = -1;
  if (n & 1)
    puts("NO");
  else {
    if (poss == -1)
      puts("NO");
    else
      puts("YES");
  }
}
