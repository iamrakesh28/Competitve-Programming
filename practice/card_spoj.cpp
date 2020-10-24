#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;
const int N = 1e4 + 5, prime = 1e9 + 7;
int a[N];
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
  for (int i = 0; i < t; ++i) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int j = 0; j < n; ++j)
      scanf("%d", a + j);
    sort(a, a + n);
    ll ans = 0;
    for (int j = k - 1; j < n; ++j) {
      ll val = inverse(fact[j - k + 1], prime - 2) * inverse(fact[k - 1], prime - 2) % prime;
      val = val * fact[j] % prime;
      val = val * a[j] % prime;
      ans = (ans + val) % prime;
    }
    printf("Case #%d: %lld\n", i + 1, ans);
  }
  return 0;
}
