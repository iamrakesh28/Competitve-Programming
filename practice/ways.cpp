#include <iostream>

using namespace std;

typedef long long ll;
const int N = 2e6 + 5, prime = 1e9 + 7;
ll fact[N];

void init(int n) {
  fact[0] = 1;
  for (int i = 1; i < n; ++i)
    fact[i] = fact[i - 1] * i % prime;
  return;
}

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

int main() {
  int t;
  scanf("%d", &t);
  init(N);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    ll ans = fact[n + k + 1], den = fact[n - 1];
    den = den * fact[k + 2] % prime;
    ans = ans * inverse(den, prime - 2) % prime;
    ans = (ans + ans - n + prime) % prime;
    printf("%lld\n", ans);
  }
  return 0;
}
