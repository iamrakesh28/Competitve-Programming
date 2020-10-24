#include <iostream>

using namespace std;

typedef long long ll;
const int N = 1e6 + 5, prime = 1e9 + 7;
ll L[N], H[N];
ll aL, bL, cL, dL, aH, bH, cH, dH;

void compute(int k, int n) {
  ll li, hi;
  for (int i = k; i < n; ++i) {
    li = (aL * L[i - 2]) % dL;
    li = (li + (bL * L[i - 1]) % dL) % dL;
    li = (li + cL) % dL;
    li = li + 1;
    L[i] = li;

    hi = (aH * H[i - 2]) % dH;
    hi = (hi + (bH * H[i - 1]) % dH) % dH;
    hi = (hi + cH) % dH;
    hi = hi + 1;
    H[i] = hi;
  }
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, k, w;
    ll pi, ans;
    scanf("%d%d%d", &n, &k, &w);
    for (int j = 0; j < k; ++j)
      scanf("%lld", L + j);
    scanf("%lld%lld%lld%lld", &aL, &bL, &cL, &dL);
    for (int j = 0; j < k; ++j)
      scanf("%lld", H + j);
    scanf("%lld%lld%lld%lld", &aH, &bH, &cH, &dH);
    compute(k, n);

    pi = ((w + H[0]) << 1) % prime;
    ans = pi;
    for (int j = 1; j < n; ++j) {
      ll temp;
      if (L[j] > L[j - 1] + w) {
	pi = (pi + ((w + H[j]) << 1)) % prime;
	ans = (ans * pi) % prime;
      }
      else {
	temp = (L[j] - L[j - 1]) << 1;
	ll hi = 0;
	for (int r = 0; r <= w + 5; ++r) {
	  if (j - r - 1 < 0)
	    break;
	  if (L[j - r - 1] + w < L[j])
	    break;
	  hi = max(hi, H[j - r - 1]);
	}
	if (hi < H[j])
	  temp = (temp + ((H[j] - hi) << 1)) % prime;
	pi = (pi + temp) % prime;
	ans = (ans * pi) % prime;
      }
    }
    printf("Case #%d: %lld\n", i + 1, ans);
  }
  return 0;
}
