#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
ll a[N];
int w[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    for (int i = 0; i < k; ++i)
      scanf("%d", w + i);
    ll ans = 0;
    sort(a, a + n);
    sort(w, w + k);
    reverse(w, w + k);
    int l, r;
    l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
      if (w[i] != 1)
	break;
      ans = ans + 2 * a[r];
      r--;
    }
    for (int i = 0; i < k; ++i) {
      if (w[i] == 1) {
	break;
	ans = ans + 2 * a[l];
	l++;
      }
      else {
	ans = ans + a[l] + a[r];
	l = l + w[i] - 1;
	r--;
      }
    }
    printf("%lld\n", ans);
  }
  return 0;
}
