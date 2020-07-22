#include <iostream>

using namespace std;

const int N = 55;
bool row[N], col[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i)
      row[i] = false;
    for (int i = 0; i < m; ++i)
      col[i] = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
	int d;
	scanf("%d", &d);
	if (d)
	  row[i] = col[j] = true;
      }
    }
    int r = 0, c = 0;
    for (int i = 0; i < n; ++i)
      if (row[i] == false)
	r++;
    for (int i = 0; i < m; ++i)
      if (col[i] == false)
	c++;
    r = min(r, c);
    if (r & 1) {
      puts("Ashish");
    }
    else
      puts("Vivek");
  }
  return 0;
}
