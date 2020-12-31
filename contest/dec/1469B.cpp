#include <iostream>

using namespace std;

const int N = 105;

int r[N], b[N], pr[N], pb[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, m, ans = 0;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i) {
      scanf("%d", r + i);
      if (i)
        pr[i] = pr[i - 1] + r[i];
      else
        pr[i] = r[i];
    }
    
    scanf("%d", &m);

    for (int i = 0; i < m; ++i) {
      scanf("%d", b + i);
      if (i)
        pb[i] = pb[i - 1] + b[i];
      else
        pb[i] = b[i];
    }

    int temp;

    for (int i = 0; i < n; ++i) {
      temp = pr[i];
      ans = max(temp, ans);
      for (int j = 0; j < m; ++j) {
        temp = pr[i] + pb[j];
        ans = max(temp, ans);
      }
    }

    // not needed (I think)
    for (int i = 0; i < m; ++i) {
      temp = pb[i];
      ans = max(temp, ans);
      for (int j = 0; j < n; ++j) {
        temp = pb[i] + pr[j];
        ans = max(temp, ans);
      }
    }

    printf("%d\n", ans);
  }
  
  return 0;
}
