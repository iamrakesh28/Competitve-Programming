#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int prefix[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n;
    scanf("%d", &n);
    prefix[0] = 0;
    for (int i = 0; i < n; ++i) {
      int num, cnt = 0;
      scanf("%d", &num);
      if ((num & 1) == 0)
	cnt++;
      prefix[i + 1] = prefix[i] + cnt;
    }
    int t;
    scanf("%d", &t);
    while (t--) {
      int l, r;
      scanf("%d%d", &l, &r);
      l--, r--;
      int sum = prefix[r + 1] - prefix[l];
      if (sum)
	puts("EVEN");
      else
	puts("ODD");
    }
  }
  return 0;
}
