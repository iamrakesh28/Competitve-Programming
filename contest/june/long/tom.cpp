#include <iostream>

using namespace std;

typedef long long ll;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    ll ts, ans = 0;
    scanf("%lld", &ts);
    if (ts & 1) {
      puts("0");
      continue;
    }
    int cnt = 0;
    ll mts = ts;
    while ((mts & 1) == 0) {
      mts >>= 1;
      cnt++;
    }
    for (int i = 0; i < cnt; ++i) {
      int one = i + 1;
      mts = ts >> one;
      if (ts & (1LL << i))
	mts++;
      ans += mts;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
