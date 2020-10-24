#include <iostream>

using namespace std;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, diff, ans = 0;
    scanf("%d%d", &n, &k);
    diff = n - k;
    if (diff >= 0) {
      if (diff & 1)
	ans = 1;
      else
	ans = 0;
    }
    else
      ans = k - n;
    printf("%d\n", ans);
  }
  return 0;
}
