#include <iostream>

using namespace std;

typedef long long ll;
const int N = 2e5 + 5;
int a[N];
ll odd[N], even[N];

int main() {
  int n;
  scanf("%d", &n);
  even[0] = odd[0] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    odd[i + 1] = odd[i];
    even[i + 1] = even[i];
    if (i & 1)
      odd[i + 1] = odd[i + 1] + a[i];
    else
      even[i + 1] = even[i + 1] + a[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (i & 1) {
      ll temp = even[i];
      ll par = odd[n] - odd[i];
      temp = temp + par;
      ans = max(ans, temp);
    }
    else {
      ll temp = odd[i];
      ll par = even[n] - even[i];
      temp = temp + par;
      ans = max(ans, temp);
    }
  }
  printf("%lld\n", ans);
  return 0;
}
