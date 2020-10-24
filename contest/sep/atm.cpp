#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
pair <int, int> order[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n, x;
    scanf("%d%d", &n, &x);
    for (int i = 0; i < n; ++i) {
      int times;
      scanf("%d", &times);
      if (times % x)
	times = times / x + 1;
      else
	times = times / x;
      order[i] = {times, i};
    }
    sort(order, order + n);
    printf("Case #%d:", q + 1);
    for (int i = 0; i < n; ++i)
      printf(" %d", order[i].second + 1);
    puts("");
  }
  return 0;
}
