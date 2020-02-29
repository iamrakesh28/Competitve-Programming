#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e3 + 5;
char s[N];
int x[N], y[N], size[4];

double euclid(double x1, double y1, double x2, double y2) {
  double temp = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  return sqrt(temp);
}

double solve(int m, int diff, int arr[]) {
  double temp = 1e14, t;
  for (int i = 0; i < m; ++i) {
    t = abs(diff - arr[i]);
    t = 2 * t;
    temp = min(temp, t);
  }
  return temp;
}
// LRDU

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, m, w, h;
    double ans = 1e14, temp;
    scanf("%d%d%d%d%s", &n, &m, &w, &h, s);
    for (int i = 0; i < m; ++i)
      scanf("%d%d", x + i, y + i);
    for (int i = 0; i < m - 1; ++i)
      for (int j = i + 1; j < m; ++j) {
	temp = euclid(x[i], y[i], x[j], y[j]);
	ans = min(ans, temp);
      }
    memset(size, 0, sizeof size);
    reverse(s, s + n);
    for (int i = 0; i < n; ++i) {
      char ch = s[i];
      int diff;
      if (ch == 'L') {
	if (size[0] == 2)
	  continue;
	size[0]++;
	if (size[0] & 1)
	  diff = 0;
	else
	  diff = w;
	ans = min(ans, solve(m, diff, x));
	continue;
      }
      if (ch == 'R') {
	if (size[1] == 2)
	  continue;
	size[1]++;
	if (size[1] & 1)
	  diff = w;
	else
	  diff = 0;
	ans = min(ans, solve(m, diff, x));
	continue;
      }
      if (ch == 'U') {
	if (size[2] == 2)
	  continue;
	size[2]++;
	if (size[2] & 1)
	  diff = h;
	else
	  diff = 0;
	ans = min(ans, solve(m, diff, y));
	continue;
      }
      if (size[3] == 2)
	continue;
      size[3]++;
      if (size[3] & 1)
	diff = 0;
      else
	diff = h;
      ans = min(ans, solve(m, diff, y));
      
    }
    printf("%0.15lf\n", ans);
    //cout<<ans<<endl;
  }
  return 0;
}
