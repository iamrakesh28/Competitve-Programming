#include <iostream>
#include <vector>

using namespace std;

vector <int> primes;

void factorize(int n) {
  for (int i = 2; i * i <= n; ++i) {
    if (n % i)
      continue;
    primes.push_back(i);
    while (n % i == 0)
      n = n / i;
  }
  if (n > 1)
    primes.push_back(n);
}
/*
  10 => 2, 5

 */
int inverse(int i, int n, int num) {
  if (num == 1)
    return 1;
  if (i == n)
    return -1;
  int p = primes[i] - 1;
  int inv1 = inverse(i + 1, n, num), inv2 = -1;
  if (num % p == 0) {
    int temp = num / p, result = p + 1;
    p++;
    while (temp % p == 0) {
      temp /= p;
      result *= p;
    }
    inv2 = result * inverse(i + 1, n, temp);
  }
  if (inv1 >= 0 && inv2 >= 0)
    return min(inv1, inv2);
  if (inv1 < 0)
    return inv2;
  return inv1;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    primes.clear();
    factorize(n);
    int ans = inverse(0, primes.size(), n);
    printf("%d\n", ans);
  }
  return 0;
}
