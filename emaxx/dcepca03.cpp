#include <iostream>

using namespace std;


int totient(int n) {
  int result = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i)
      continue;
    result -= result / i;
    while (n % i == 0)
      n = n / i;
  }
  if (n > 1)
    result -= result / n;
  return result;
}

int main() {
  int n;
  while (scanf("%d", &n) != EOF && n)
    printf("%d\n", totient(n));
  return 0;
}
