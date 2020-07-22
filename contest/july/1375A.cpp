#include <iostream>

using namespace std;

const int N = 100;
int a[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);
    for (int i = 1; i < n - 1; ++i) {
      int d1 = a[i] - a[i - 1];
      int d2 = a[i + 1] - a[i];
      if (d1 > 0 && d2 > 0) {
	if (a[i + 1] < 0) {
	  a[i] = -a[i];
	  continue;
	}
	if (a[i] >= 0) {
	  a[i + 1] = -a[i + 1];
	  continue;
	}
	a[i] = -a[i];
	a[i + 1] = -a[i + 1];
      }
      else if (d1 < 0 && d2 < 0) {
	if (a[i + 1] >= 0) {
	  a[i] = -a[i];
	  continue;
	}
	if (a[i] < 0) {
	  a[i + 1] = -a[i + 1];
	  continue;
	}
	a[i] = -a[i];
	a[i + 1] = -a[i + 1];
      }
    }
    for (int i = 0; i < n; ++i)
      printf("%d ", a[i]);
    puts("");
  }
  return 0;
}
