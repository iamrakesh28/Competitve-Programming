#include <iostream>

using namespace std;

const int N = 1e6 + 5;
long long phi[N];

int totient(int n) {
  int result = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i)
      continue;
    while (n % i == 0)
      n /= i;
    result -= result / i;
  }
  if (n > 1)
    result -= result / n;
  return result;
}


/*
  |Fn|   = 1 + Summation phi(i) where 1 <= i <= n
  Neigbhours = 2 * |Fn| -  3

 */
int main() {
  
  phi[0] = 0;
  for (int i = 1; i < N; ++i) {
    phi[i] = totient(i);
    phi[i] += phi[i - 1];
  }
  int n;
  while (scanf("%d", &n) != EOF && n) {
    long long ans = phi[n] - 1;
    printf("%lld\n", ans);
  }
}
