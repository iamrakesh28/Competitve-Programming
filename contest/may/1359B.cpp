#include <iostream>

using namespace std;

char mat[105][1005];

int cost(int len, int x, int y) {
  int ans = 0;
  if (len & 1) {
    int eq = 2 * x;
    len = len / 2;
    ans = min(eq, y) * len + x;
  }
  else {
    int eq = 2 * x;
    len = len / 2;
    ans = min(eq, y) * len;
  }
  return ans;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, x, y;
    scanf("%d%d%d%d", &n, &m, &x, &y);
    for (int i = 0; i < n; ++i)
      scanf("%s", mat[i]);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      int prev = 0;
      for (int j = 0; j < m; ++j) {
	if (mat[i][j] == '*') {
	  ans = ans + cost(prev, x, y);
	  prev = 0;
	}
	else
	  prev++;
      }
      ans = ans + cost(prev, x, y);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
