#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int wk[N];

int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i)
      continue;
    result -= result / i;
    while (n % i == 0)
      n /= i;
  }
  if (n > 1)
    result -= result / n;
  return result;
}

long long power(long long a, long long long m) {
  long long r =
}

int solve() {
}

int main() {
  int n, m, q;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i)
    scanf("%d", wk + i);
  scanf("%d", &q);
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
  }
  return 0;
}
