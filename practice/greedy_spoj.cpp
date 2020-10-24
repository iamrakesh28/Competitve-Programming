#include <iostream>

using namespace std;

typedef long long ll;
const int N = 505, prime = 1e9 + 7;
ll fact[N];
int fi[N];

ll inverse(ll a, int n) {
  ll r = 1;
  while (n) {
    if (n & 1)
      r = r * a % prime;
    a = a * a % prime;
    n >>= 1;
  }
  return r;
}

void init(int n) {
  fact[0] = 1;
  for (int i = 1; i < n; ++i)
    fact[i] = fact[i - 1] * i % prime;
  return;
}

int main() {
  int n;
  init(N);
  while (scanf("%d", &n) != EOF && n) {
    for (int i = 0; i < n; ++i)
      scanf("%d", fi + i);
    ll ans = 1;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
      int fj;
      scanf("%d", &fj);
      sum += fj - fi[i];
      ll x1 = inverse(fact[fj - fi[i]], prime - 2);
      ans = ans * x1 % prime;
    }
    ans = ans * fact[sum] % prime;
    printf("%lld\n", ans);
  }
  return 0;
}
