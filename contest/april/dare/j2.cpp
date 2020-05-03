#include <iostream>

using namespace std;

const int N = 1e5 + 5;
char S[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, ans, rem;
    scanf("%d%d%s", &n, &k, S);
    rem = n % k;
    if (rem == 0) {
      printf("%d\n", n);
      continue;
    }
    ans = k - rem;
    ans = n - ans;
    for (int i = 0; i <= k; ++i) {
      int q = 3 * k - 2 * i;
      q = n - q;
      if (q >= 0) {
	q = q % k;
	q = k - q;
	q = n - q;
	ans = max(ans, q);
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
