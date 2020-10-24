#include <iostream>
#include <cstring>

using namespace std;
const int N = 3e5 + 5;

char s[N];
bool mark[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, ans, l = 0, r = 0;
    scanf("%d%s", &n, s);
    memset(mark, false, sizeof(bool) * n);
    for (int i = 0; i < n; ++i) {
      if (s[i] == '<')
	l++;
      else if (s[i] == '>')
	r++;
      else {
	mark[i] = true;
	mark[(i + 1) % n] = true;
      }
    }
    if (l == 0 || r == 0) {
      printf("%d\n", n);
      continue;
    }
    ans = 0;
    for (int i = 0; i < n; ++i)
      if (mark[i])
	ans++;
    printf("%d\n", ans);
  }
  return 0;
}
