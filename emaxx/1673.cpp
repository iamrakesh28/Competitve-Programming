#include <iostream>

using namespace std;

long long inverse(long long k) {
  long long result = 1;
  for (long long i = 2; i * i <= k; ++i) {
    if (k % i)
      continue;
    if (k % (i - 1))
      continue;
    result *= i;
    k = k / (i - 1);
    while (k % i == 0) {
      k = k / i;
      result *= i;
    }
  }
  if (k > 1) {
  }
  return result;
}

int main() {
  long long k;
  scanf("%lld", &k);
  return 0;
}
