#include <iostream>
#include <set>

using namespace std;

const int N = 1e3 + 5;
set <int> A;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m, val;
    scanf("%d%d", &n, &m);
    bool poss = false;
    A.clear();
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      A.insert(ai);
    }
    for (int i = 0; i < m; ++i) {
      int bi;
      scanf("%d", &bi);
      if (A.find(bi) != A.end()) {
	poss = true;
	val = bi;
      }
    }
    if (poss == false) {
      puts("NO");
      continue;
    }
    printf("YES\n%d %d\n", 1, val);
  }
  return 0;
}
