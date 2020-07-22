#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int t[N];

int main() {
  int n, c, k;
  scanf("%d%d%d", &n, &c, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", t + i);
  sort(t, t + n);
  int tim = t[0], cap = 1, ans = 1;
  for (int i = 1; i < n; ++i) {
    if (t[i] - tim > k) {
      tim = t[i];
      ans++;
      cap = 0;
    }
    if (cap + 1 > c) {
      cap = 1;
      ans++;
      tim = t[i];
    }
    else
      cap++;
  }
  printf("%d\n", ans);
  return 0;
}
