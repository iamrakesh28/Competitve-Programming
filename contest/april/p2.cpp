#include <iostream>

typedef long long ll;
using namespace std;

const int N = 1e3 + 5;
ll x[N];

bool poss(ll d, ll start, int n) {
  for (int i = 0; i < n; ++i) {
    if (start == x[i])
      continue;
    if (start < x[i]) {
      start = x[i];
      continue;
    }
    ll q = start / x[i];
    if (start % x[i])
      q++;
    start = q * x[i];
  }
  if (start <= d)
    return true;
  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n;
    ll d, ans = 1;
    scanf("%d%lld", &n, &d);
    for (int j = 0; j < n; ++j)
      scanf("%lld", x + j);
    ll beg = 1, end = d, mid;
    while (beg <= end) {
      mid = beg + end >> 1;
      if (poss(d, mid, n)) {
	ans = mid;
	beg = mid + 1;
      }
      else
	end = mid - 1;
    }
    printf("Case #%d: %lld\n", i + 1, ans);
  }
  return 0;
}
