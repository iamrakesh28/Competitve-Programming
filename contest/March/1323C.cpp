#include <iostream>

using namespace std;

const int N = 1e6 + 5;
char s[N];

int main() {
  int n, open = 0, end = 0;
  scanf("%d%s", &n, s);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      open++;
    else
      end++;
  }
  if (open != end) {
    puts("-1");
    return 0;
  }
  int ans = 0, cur = 0, prev, neg = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(')
      cur++;
    else
      cur--;
    if (cur == 0 && neg) {
      ans += i - prev + 1;
      neg = 0;
    }
    if (cur < 0 && neg == 0) {
      neg = 1;
      prev = i;
    }
  }
  printf("%d\n", ans);
  return 0;
}
