#include <iostream>

using namespace std;

int solve(int i, int j, int **mat, int n, int m) {
  int cnt = 0;
  for (int len = 1; len <= n; ++len) {
    if (i - len + 1 >= 0 && i + len - 1 < n && j - len + 1 >= 0 && j + len - 1 < m) {
      if (mat[i - len + 1][j] == mat[i + len - 1][j] && mat[i][j - len + 1] == mat[i][j + len - 1])
	cnt++;
      else
	break;
    }
    else
      break;
  }
  return cnt;
}

int main() {

  int q, **mat;
  scanf("%d", &q);
  while (q--) {
    int n, m;
    scanf("%d%d", &n, &m);
    mat = new int* [n];
    for (int i = 0; i < n; ++i) {
      mat[i] = new int[m];
      for (int j = 0; j < m; ++j)
	scanf("%d", mat[i] + j);
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
	ans += solve(i, j, mat, n, m);
    printf("%lld\n", ans);
  }
  return 0;
}
