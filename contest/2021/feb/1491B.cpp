#include <iostream>

using namespace std;

int a[105];

int path(int n) {
  int p = -1;
  int ai = a[0];
  for (int i = 1; i < n; ++i) {
    if (abs(ai - a[i]) >= 2) {
      return 0;
    }
    else {
      if (abs(ai - a[i]) == 1)
        p = 1;
    }

    ai = a[i];
  }
  
  return p;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, u, v;
    scanf("%d%d%d", &n, &u, &v);

    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);
    }

    int p = path(n);
    if (p == 0) {
      puts("0");
    }
    else if (p == 1) {
      printf("%d\n", min(u, v));
    }
    else {
      printf("%d\n", min(u, v) + v);
    }
  }
  return 0;
}
