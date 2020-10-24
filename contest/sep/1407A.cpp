#include <iostream>

using namespace std;

const int N = 1e3 + 5;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, one = 0, zero = 0, ans;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      if (a)
	one++;
      else
	zero++;
    }
    int val;
    if (one > zero) {
      ans = one;
      if (one & 1)
	ans--;
      val = 1;
    }
    else if (zero > one){
      ans = zero;
      if (zero & 1)
	ans--;
      val = 0;
    }
    else {
      ans = one;
      val = 0;
    }
    printf("%d\n", ans);
    for (int i = 0; i < ans; ++i)
      printf("%d ", val);
    puts("");
  }
  return 0;
}
