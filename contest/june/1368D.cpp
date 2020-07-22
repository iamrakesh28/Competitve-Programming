#include <iostream>

using namespace std;

const int N = 2e5 + 5;
typedef long long ll;
int a[N], pref[N], suff[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
  }
  for (int i = 0; i < n - 1; ++i) {
    int a1 = a[i], a2 = a[i + 1];
    a[i] = a1 & a2;
    a[i + 1] = a1 | a2;
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i)
    ans = ans + (ll)a[i] * a[i];
  printf("%lld\n", ans);
  return 0;
}
