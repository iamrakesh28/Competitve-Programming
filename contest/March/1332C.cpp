#include <iostream>

using namespace std;

const int N = 2e5 + 5, inf = 1e9;
char s[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k, ans = 0, mid;
    scanf("%d%d%s", &n, &k, s);
    mid = k / 2;
    for (int i = 0; i < mid; ++i) {
      int cnt = inf;
      for (int j = 0; j < 26; ++j) {
	char c = j + 'a';
	int temp = 0;
	for (int r = i; r < n; r += k)
	  if (s[r] != c)
	    temp++;
	for (int r = k - i - 1; r < n; r += k)
	  if (s[r] != c)
	    temp++;
	cnt = min(cnt, temp);
      }
      ans += cnt;
    }
    if (k & 1) {
      int cnt = inf;
      for (int j = 0; j < 26; ++j) {
	char c = j + 'a';
	int temp = 0;
	for (int r = mid; r < n; r += k)
	  if (s[r] != c)
	    temp++;
	cnt = min(cnt, temp);
      }
      ans += cnt;
    }
    printf("%d\n", ans);
  }
  return 0;
}
