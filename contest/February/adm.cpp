#include <iostream>
#include <cmath>

using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int l, r, temp;
    scanf("%d%d", &l, &r);
    temp = min(l, r);
    r = max(l, r);
    l = temp;
    int cnt = 0;
    for (int i = l; i <= r; ++i) {
      int sq = sqrt(i);
      if (sq * sq != i)
	cnt++;
    }
    printf("%d\n", cnt);
  }
  return 0;
}
