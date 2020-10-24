#include <iostream>
#include <cstring>

using namespace std;

typedef long long ll;
const int N = 2e5 + 5, prime = 1e9 + 7;
char s[N];
ll fact[N << 1];

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
  init(N << 1);
  scanf("%s", s);
  int n = strlen(s), tot = 0, cur = 0, left = 0;
  for (int i = 0; i < n; ++i)
    if (s[i] == ')')
      tot++;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == ')') {
      cur++;
      continue;
    }
    int right = tot - cur;
    if (right == 0) {
      left++;
      continue;
    }
    ll temp = fact[left + right];
    temp = temp * inverse(fact[right - 1], prime - 2) % prime;
    temp = temp * inverse(fact[left + 1], prime - 2) % prime;
    left++;
    ans = (ans + temp) % prime;
  }
  printf("%lld\n", ans);
  return 0;
}
