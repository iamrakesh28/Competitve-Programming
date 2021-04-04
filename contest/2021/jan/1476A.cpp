#include <iostream>

using namespace std;

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);

    int x = n / k;
    if (n % k)
      x++;

    long long sum = (long long)x * k;

    if (sum % n == 0)
      printf("%lld\n", sum / n);
    else
      printf("%lld\n", sum / n + 1);
  }
  
  return 0;
}
