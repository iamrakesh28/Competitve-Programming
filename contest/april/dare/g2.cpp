#include <iostream>
#include <cstring>

typedef long long ll;
using namespace std;

const int prime = 1e9 + 7;
char S[55];

ll power(ll n, ll a) {
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
  ll n, ans, l, temp, mod = power(prime - 2, 2);
  scanf("%lld%s", &n, S);
  l = strlen(S);
  if (n < l) {
    puts("0");
    return 0;
  }
  ans = power(n - l, 26);
  ans = ans * ((n - l + 1) % prime) % prime;
  ll val;
  if (n >= 2 * l) {
    ll len = n - 2 * l + 1;
    len = len % prime;
    val = power(n - 2 * l, 26);
    val = val * len % prime;
    val = val * (len + 1) % prime;
    val = val * mod % prime;
    ans = (ans - val + prime) % prime;
  }
  for (int j = 1; j < l; ++j) {
    int cmp = 1, com = l + j;
    if (com > n)
      break;
    for (int i = j; i < l; ++i)
      if (S[i - j] != S[j]) {
	  cmp = 0;
	  break;
	}
    if (cmp) {
      ll len = n - com + 1;
      len = len % prime;
      val = power(n - com, 26);
      val = val * len % prime;
      ans = (ans - val + prime) % prime;
    }
  }
  printf("%lld\n", ans);
  return 0;
}
