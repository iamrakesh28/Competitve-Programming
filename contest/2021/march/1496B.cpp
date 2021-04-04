#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {

    int n, k;
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; ++i)
      scanf("%d", a + i);

    if (k == 0) {
      printf("%d\n", n);
      continue;
    }
    
    sort(a, a + n);
    int mex = n;
    for (int i = 0; i < n; ++i) {
      if (i != a[i]) {
        mex = i;
        break;
      }
    }
    
    int cnt = n;
    if (mex == n) {
      cnt += k;
    }
    else {
      int maxm = a[n - 1];
      int elem = mex + maxm;
      if (elem & 1)
        elem = elem / 2 + 1;
      else
        elem = elem / 2;

      cnt++;
      for (int i = 0; i < n; ++i) {
        if (a[i] == elem) {
          cnt--;
          break;
        }
      }
    }

    printf("%d\n", cnt);
  }
  
  return 0;
}
