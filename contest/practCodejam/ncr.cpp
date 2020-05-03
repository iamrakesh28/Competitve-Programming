#include <iostream>

typedef long long ll;
using namespace std;

const int mod = 142857;

int phi(int n) {
  int result = n;
  for (int i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      while (n % i == 0)
	n /= i;
      result -= result / i;
    }
  }
  if (n > 1)
    result -= result / n;
  return result;
}

int factmod(int n, int k) {
  int res = 1;
  // n ... k + 1
  if (n - k <= mod) {
    for (int i = k + 1; i <= n; ++i) {
      int p = i % mod;
      res = (ll)res * i % mod;
    }
  }
  else {
    for (int i = k + 1 % mod; i < mod; ++i)
      res = (ll)res * i % mod;
    while (n > k) {
      for (int i = 2; i <= n % mod; ++i)
	res = (ll)res * i % mod;
      int np = n / mod;
      if (np <= k)
	break;
      res = ((ll)res * ((n / mod) % 2 ? mod - 1 : 1)) % mod;
      n = np;
    }
  }
  return res % mod;
}

ll power(int a, int n) {
  ll r = 1;
  while (n) {
    if (n & 1)
      r = r * a % mod;
    a = (ll)a * a % mod;
    n >>= 1;
  }
  return r;
}

int main() {
  int t, tot = phi(mod);
  scanf("%d", &t);
  while (t--) {
    int n, r;
    scanf("%d%d", &n, &r);
    int num = factmod(n, n - r), den = factmod(r, 1);
    cout<<num<<" "<<den<<" ";
    den = power(den, tot - 1);
    cout<<den<<endl;
    int ans = (ll)num * den % mod;
    printf("%d\n", ans);
  }
  return 0;
}
