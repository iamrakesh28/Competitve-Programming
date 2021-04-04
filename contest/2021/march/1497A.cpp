#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 105;
int a[N], b[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);

    sort(a, a + n);
    int ind = n - 1, j = 1;

    b[0] = a[0];
    for (int i = 1; i < n; ++i) {
      if (a[i] == a[i - 1]) {
        b[ind--] = a[i];
      }
      else {
        b[j++] = a[i];
      }
    }

    for (int i = 0; i < n; ++i)
      printf("%d ", b[i]);
    puts("");
  }
  
  return 0;
}
