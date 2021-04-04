#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {

  int n, q;
  scanf("%d%d", &n, &q);

  int one = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", a + i);
    if (a[i] == 1)
      one++;
  }

  while (q--) {
    int t, kx;
    scanf("%d%d", &t, &kx);

    if (t == 1) {
      if (a[kx - 1] == 0) {
        a[kx - 1] = 1;
        one++;
      }
      else {
        a[kx - 1] = 0;
        one--;
      }
    }
    else {
      if (one >= kx)
        puts("1");
      else
        puts("0");
    }
  }
  return 0;
}
