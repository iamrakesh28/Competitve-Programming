#include <iostream>

using namespace std;

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < k - 3; ++i)
      printf("1 ");

    if (k > 3)
      n = n - (k - 3);

    if (n & 1) {
      printf("%d %d %d\n", 1, (n - 1) / 2, (n - 1) / 2);
    }
    else {
      if (n % 4 == 0)
        printf("%d %d %d\n", n / 4, n / 4, n / 2);
      else
        printf("%d %d %d\n", 2, (n - 2) / 2, (n - 2) / 2);
    }
  }
  
  return 0;
}
