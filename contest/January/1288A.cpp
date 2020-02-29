#include <iostream>

using namespace std;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    long long n, d, f;
    cin>>n>>d;
    if (n >= d) {
      puts("YES");
      continue;
    }
    bool ans = false;
    for (long long i = 0; i <= n; ++i) {
      f = d / (i + 1);
      if (f * (i + 1) < d)
	f++;
      f = f + i;
      if (f <= n) {
	ans = true;
	break;
      }
    }
    if (ans)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
