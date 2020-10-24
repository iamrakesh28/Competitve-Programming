#include <iostream>

typedef long long ll;
using namespace std;
const int N = 1e6 + 5;
int aS, bS, cS, dS;
int aX, bX, cX, dX;
int aY, bY, cY, dY;
ll S[N], X[N], Y[N];

void compute(int n, int k) {
  for (int i = k; i < n; ++i) {
    ll si = (aS * S[i - 2]) % dS;
    si = (si + ((bS * S[i - 1]) % dS)) % dS;
    si = (si + cS) % dS;
    S[i] = si;

    ll xi = (aX * X[i - 2]) % dX;
    xi = (xi + ((bX * X[i - 1]) % dX)) % dX;
    xi = (xi + cX) % dX;
    X[i] = xi;

    ll yi = (aY * Y[i - 2]) % dY;
    yi = (yi + ((bY * Y[i - 1]) % dY)) % dY;
    yi = (yi + cY) % dY;
    Y[i] = yi;
  }
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int h = 0; h < t; h++) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < k; ++i)
      scanf("%lld", S + i);
    scanf("%d%d%d%d", &aS, &bS, &cS, &dS);
    for (int i = 0; i < k; ++i)
      scanf("%lld", X + i);
    scanf("%d%d%d%d", &aX, &bX, &cX, &dX);
    for (int i = 0; i < k; ++i)
      scanf("%lld", Y + i);
    scanf("%d%d%d%d", &aY, &bY, &cY, &dY);
    ll mn = 0, mx = 0, sum = 0, pos = 0, neg = 0;
    compute(n, k);
    for (int i = 0; i < n; ++i) {
      mn = mn + X[i];
      mx = mx + Y[i];
      sum = sum + S[i];
      if (S[i] < X[i])
	neg = neg + X[i] - S[i];
      else if(S[i] > X[i] + Y[i])
	pos = pos + S[i] - X[i] - Y[i];
    }
    mx = mx + mn;
    if (sum >= mn && sum <= mx) {
      ll ans = max(pos, neg);
      printf("Case #%d: %lld\n", h + 1, ans);
    }
    else {
      printf("Case #%d: -1\n", h + 1);
    }
  }
  return 0;
}

