#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", a + i);
  sort(a, a + n);
  int half = n / 2;
  ll ans = 0, temp = 0;
  for (int i = 0; i < n; ++i) {
    if (i < half)
      temp += a[i];
    else
      ans += a[i];
  }
  ans = ans * ans + temp * temp;
  printf("%lld\n", ans);
  return 0;
}
