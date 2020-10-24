#include <iostream>

using namespace std;

const int N = 2e5 + 5;
char s[N];

int main() {
  int n;
  scanf("%d%s", &n, s);
  int l, r;
  long long ans = 0;
  if (n & 1) {
    l = n / 2;
    l--;
    r = n - l - 1;
  }
  else {
    l = n / 2 - 1;
    r = l + 1;
  }

  while (r < n) {
    if (s[l] != s[r]) {
      if (l == r - 1)
	ans++;
      else {
	if (s[l + 1] == s[r] || s[l] == s[r - 1])
	  ans += (r - l);
	else
	  ans += 2 * (r - l);
      }
    }
    l--, r++;
  }
  printf("%lld\n", ans);
  return 0;
}
