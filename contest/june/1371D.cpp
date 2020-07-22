#include <iostream>

using namespace std;

const int N = 305;
int mat[N][N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
	mat[i][j] = 0;

    for (int i = 0; i < n && k > 0; ++i) {
      int r, c;
      r = 0;
      c = i;
      while (r < n && c < n && k > 0) {
	mat[r][c] = 1;
	k--;
	if (k) {
	  mat[n - r - 1][n - c - 1] = 1;
	  k--;
	}
	r++, c++;
      }
      if (i == 0)
	continue;
      r = i;
      c = 0;
      while (r < n && c < n && k > 0) {
	mat[r][c] = 1;
	k--;
	if (k) {
	  mat[n - r - 1][n - c - 1] = 1;
	  k--;
	}
	r++, c++;
      }
    }

    long long ans, rmin = 100000000, cmin = 100000000, rmax = -1, cmax = -1;
    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int j = 0; j < n; ++j)
	sum += mat[i][j];
      rmin = min(rmin, sum);
      rmax = max(rmax, sum);
    }

    for (int i = 0; i < n; ++i) {
      long long sum = 0;
      for (int j = 0; j < n; ++j)
	sum += mat[j][i];
      cmin = min(cmin, sum);
      cmax = max(cmax, sum);
    }
    rmax = rmax - rmin;
    cmax = cmax - cmin;
    ans = rmax * rmax + cmax * cmax;
    printf("%lld\n", ans);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j)
	printf("%d", mat[i][j]);
      puts("");
    }
  }
  return 0;
}
