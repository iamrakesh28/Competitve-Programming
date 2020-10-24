#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    if (n < 3 || n == 4) {
      puts("-1");
      continue;
    }
    int rem = n % 3;
    if (rem == 0) {
      printf("%d 0 0\n", n / 3);
    }
    else if (rem == 2) {
      n -= 5;
      printf("%d 1 0\n", n / 3);
    }
    else {
      n -= 7;
      printf("%d 0 1\n", n / 3);
    }
  }
  return 0;
}
