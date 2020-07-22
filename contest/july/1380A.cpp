#include <iostream>

using namespace std;

int p[1005];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", p + i);
    bool poss = false;
    for (int i = 1; i < n - 1; ++i) {
      if (p[i - 1] < p[i] && p[i] > p[i + 1]) {
	printf("YES\n%d %d %d\n", i, i + 1, i + 2);
	poss = true;
	break;
      }
    }
    if (poss == false)
      puts("NO");
  }
  return 0;
}
