#include <iostream>

using namespace std;

const int N = 20;
int x[2][N], y[2][N];

int right(int l1, int l2) {
  if (x[0][0] <= x[1][0]) {
    if (x[0][1] < x[1][1]) {
      if (l1 < l2)
	return (x[1][0] - x[0][0]);
      else
	return (x[1][1] - x[0][1]);
    }
    else
      return 0;
  }
  else {
    if (x[0][1] > x[1][1]) {
      if (l1 > l2)
	return (x[0][0] - x[1][0]);
      else
	return (x[0][1] - x[1][1]);
    }
    else
      return 0;
  }
}

int up(int b1, int b2) {
  if (y[0][3] < y[1][3]) {
    if (y[0][0] < y[1][0]) {
      if (b1 < b2)
	return (y[1][3] - y[0][3]);
      else
	return (y[1][0] - y[0][0]);
    }
    else
      return 0;
  }
  else {
    if (y[0][3] >= y[1][0]) {
      if (b1 > b2)
	return (y[0][3] - y[1][3]);
      else
	return (y[0][0] - y[1][0]);
    }
    else
      return 0;
  }
}

int main() {
  int n, m;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &m);
    for (int j = 0; j < m; ++j)
      scanf("%d%d", x[i] + j, y[i] + j);
  }
  int l1, l2, b1, b2;
  l1 = x[0][1] - x[0][0];
  l2 = x[1][1] - x[1][0];
  b1 = y[0][0] - y[0][3];
  b2 = y[1][0] - y[1][3];
  if (l1 < l2) {
    if (b1 > b2) {
      puts("-1");
      return 0;
    }
  }
  else {
    if (b1 < b2) {
      puts("-1");
      return 0;
    }
  }
  int ans = right(l1, l2);
  //cout<<ans<<endl;
  ans = ans + up(b1, b2);
  printf("%d\n", ans);
  return 0;
}
