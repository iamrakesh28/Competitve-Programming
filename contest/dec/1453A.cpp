#include <iostream>
#include <cstring>

using namespace std;

bool bott[105];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    memset(bott, false, sizeof bott);
        
    for (int i = 0; i < n; ++i) {
      int id;
      scanf("%d", &id);
      bott[id - 1] = true;
    }

    for (int i = 0; i < m; ++i) {
      int id;
      scanf("%d", &id);
      if (bott[id - 1])
        ans++;
    }
    printf("%d\n", ans);
  }
  return 0;
}
