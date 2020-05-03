#include <iostream>

using namespace std;

// sorted in non-decreasing order is the key to this solution

const int N = 1e5;
int bit[N], a[N];

int getsum(int i) {
  if (i < 0)
    return 0;
  return bit[i];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, q;
    scanf("%d%d", &n, &q);
    for (int j = 0; j < n; ++j)
      scanf("%d", a + j);
    bit[0] = 1;
    for (int j = 1; j < n; ++j) {
      bit[j] = bit[j - 1];
      if (a[j] != a[j - 1])
	bit[j]++;
    }
    printf("Case %d:\n", i + 1);
    while (q--) {
      int l, r;
      scanf("%d%d", &l, &r);
      l--, r--;
      int ans = getsum(r) - getsum(l - 1);
      if (l) {
	if (a[l - 1] == a[l])
	  ans++;
      }
      printf("%d\n", ans);
    }
  }
  return 0;
}
