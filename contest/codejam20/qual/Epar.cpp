#include <iostream>
#include <cstring>

using namespace std;

const int N = 5;
int row[N], col[N], ans[N][N];

bool backtrack(int i, int n, int k) {
  int r = i / n, c;
  c = i % n;
  if (r == n) {
    int tr = 0;
    for (int j = 0; j < n; ++j)
      tr += ans[j][j];
    if (tr == k)
      return true;
    return false;
  }
  for (int m = 0; m < n; ++m) {
    if (row[r] & (1 << m))
      continue;
    if (col[c] & (1 << m))
      continue;
    int t1 = row[r], t2 = col[c];
    row[r] |= (1 << m);
    col[c] |= (1 << m);
    ans[r][c] = m + 1;
    if (backtrack(i + 1, n, k))
      return true;
    row[r] = t1;
    col[c] = t2;
  }

  return false;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n, k;
    scanf("%d%d", &n, &k);
    memset(row, 0, sizeof row);
    memset(col, 0, sizeof col);
    bool poss = backtrack(0, n, k);
    printf("Case #%d: ", q + 1);
    if (poss) {
      puts("POSSIBLE");
      for (int i = 0; i < n; ++i) {
	for (int j = 0; j < n; ++j)
	  printf("%d ", ans[i][j]);
	puts("");
      }
    }
    else
      puts("IMPOSSIBLE");
  }
  return 0;
}
