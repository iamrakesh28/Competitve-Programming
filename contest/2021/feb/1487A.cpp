#include <iostream>
#include <algorithm>

using namespace std;

const int N = 105;
int a[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);

    sort(a, a + n);
    int next = -1;
    for (int i = 1; i < n; ++i) {
      if (a[i] > a[0]) {
        next = i;
        break;
      }
    }

    if (next == -1)
      puts("0");
    else
      printf("%d\n", n - next);
  }
  
  return 0;
}
