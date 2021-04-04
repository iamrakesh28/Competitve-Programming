#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int mod[N];

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; ++i)
      mod[i] = 0;
    
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);

      mod[ai % m]++;
    }

    int ans = 0;
    if (mod[0] > 0)
      ans++;

    int len = m >> 1;
    for (int i = 1; i <= len; ++i) {
      int inv = m - i;
      int temp;

      if (mod[i] == 0 && mod[inv] == 0)
        continue;
      
      if (inv == i) {
        ans++;
        continue;
      }
      
      if (mod[i] == mod[inv]) {
        ans++;
      }
      else {
        temp = mod[i] + mod[inv] - 2 * min(mod[i], mod[inv]) - 1;
        ans++;
        ans += temp;
      }
    }
    
    printf("%d\n", ans);
  }
  
  return 0;
}
