#include <iostream>

typedef long long ll;
using namespace std;

const int N = 1e2 + 5;
ll bit[N][N][N];
int n;

void update(int x, int y, int z, int delta) {
  for (int i = x; i <= n; i = i | (i + 1))
    for (int j = y; j <= n; j = j | (j + 1))
      for (int k = z; k <= n; k = k | (k + 1))
	bit[i][j][k] += delta;
}

ll getsum(int x, int y, int z) {
  ll ret = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
      for (int k = z; k >= 0; k = (k & (k + 1)) - 1)
	ret += bit[i][j][k];
  return ret;
}

int main() {
  int q;
  scanf("%d%d", &n, &q);
  while (q--) {
    int t, x, y, z;
    scanf("%d%d%d%d", &t, &x, &y, &z);
    if (t == 1) {
      int val;
      scanf("%d", &val);
      update(x, y, z, val);
    }
    else {
      int X, Y, Z;
      scanf("%d%d%d", &X, &Y, &Z);
      ll ans = getsum(X, Y, Z) - getsum(X, Y, z - 1) - getsum(X, y - 1, Z) - getsum(x - 1, Y, Z);
      ans = ans + getsum(X, y - 1, z - 1) + getsum(x - 1, Y, z - 1) + getsum(x - 1, y - 1, Z)
	- getsum(x - 1, y - 1, z - 1);
      ans = getsum(n, n, n) - ans;
      printf("%lld\n", ans);
    }
  }
}
