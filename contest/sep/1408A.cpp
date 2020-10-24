#include <iostream>

using namespace std;

const int N = 105;
int a[N], b[N], c[N], p[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i <n; ++i)
      scanf("%d", a + i);
    for (int i = 0; i <n; ++i)
      scanf("%d", b + i);
    for (int i = 0; i <n; ++i)
      scanf("%d", c + i);
    for (int i = 0; i < n - 1; ++i) {
      if (i) {
	if (p[i - 1] == a[i])
	  p[i] = b[i];
	else
	  p[i] = a[i];
      }
      else
	p[i] = a[i];
    }
    int val;
    if (p[n - 2] == a[n - 1]) {
      if (p[0] == a[n - 1])
	val = b[n - 1];
      else if (p[0] == b[n - 1])
	val = c[n - 1];
      else
	val = b[n - 1];
    }
    else if (p[n - 2] == b[n - 1]) {
      if (p[0] == a[n - 1])
	val = c[n - 1];
      else if (p[0] == b[n - 1])
	val = a[n - 1];
      else
	val = a[n - 1];
    }
    else {
      if (p[0] == a[n - 1])
	val = b[n - 1];
      else if (p[0] == b[n - 1])
	val = a[n - 1];
      else
	val = a[n - 1];
    }
    p[n - 1] = val;
    for (int i = 0; i < n; ++i)
      printf("%d ", p[i]);
    puts("");
  }
  return 0;
}
