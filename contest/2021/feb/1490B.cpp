#include <iostream>

using namespace std;

const int N = 3e4 + 5;
int a[N], c[3];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    c[0] = c[1] = c[2] = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", a + i);

      int rem = a[i] % 3;
      c[rem]++;
    }

    int exp = n / 3;
    int ans = 0, rem = 0, mx = -1, id;

    for (int i = 0; i < 3; ++i) {
      if (c[i] > mx) {
        mx = c[i];
        id = i;
      }
    }

    rem = mx - exp;
    ans = rem;
    
    int next = (id + 1) % 3;

    c[next] += rem;
    
    if (c[next] > exp) {
      rem = c[next] - exp;
      ans += rem;
    }
    else {
      next = (next + 1) % 3;
      rem = c[next] - exp;
      ans = ans + 2 * rem;
    }

    printf("%d\n", ans);
  }
  
  return 0;
}
