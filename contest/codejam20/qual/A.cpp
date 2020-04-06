#include <iostream>
#include <cstring>

using namespace std;

const int N = 100;
int row[N][N], col[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, ent, tr = 0, rc = 0, cc = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      memset(row[i], 0, sizeof row[i]);
      memset(col[i], 0, sizeof col[i]);
    }
    for (int r = 0; r < n; ++r) {
      for (int c = 0; c < n; ++c) {
	scanf("%d", &ent);
	row[r][ent - 1]++;
	col[c][ent - 1]++;
	if (r == c)
	  tr += ent;
      }
    }
    for (int r = 0; r < n; ++r) {
      bool flag = false;
      for (int j = 0; j < n; ++j)
	if (row[r][j] > 1)
	  flag = true;
      if (flag)
	rc++;
    }
    for (int c = 0; c < n; ++c) {
      bool flag = false;
      for (int j = 0; j < n; ++j)
	if (col[c][j] > 1)
	  flag = true;
      if (flag)
	cc++;
    }
    printf("Case #%d: %d %d %d\n", i + 1, tr, rc, cc);
  }
  return 0;
}
