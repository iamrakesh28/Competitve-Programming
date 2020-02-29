#include <iostream>

using namespace std;

const int N = 1e3 + 5;
int d[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, div = 0, ind, g = -1;
    long long p;
    scanf("%d%lld", &n, &p);
    for (int i = 0; i < n; ++i) {
      scanf("%d", d + i);
      if (p % d[i] == 0)
	div++;
      else
	ind = i;
      if (i && d[i] % d[i - 1])
	g = i;
    }
    if (div < n) {
      printf("YES ");
      int ci = p / d[ind] + 1;
      for (int i = 0; i < n; ++i)
	if (i != ind)
	  printf("0 ");
        else
	  printf("%d ", ci);
      puts("");
    }
    else {
      if (g == -1) {
	puts("NO");
	continue;
      }
      int f = p / d[g] - 1, dist;
      dist = d[g] / d[g - 1] + 1;
      printf("YES ");
      for (int i = 0; i < n; ++i)
	if (i == g)
	  printf("%d ", f);
        else if (i == g - 1)
	  printf("%d ", dist);
	else
	  printf("0 ");
      puts("");
    }
  }
  return 0;
}
