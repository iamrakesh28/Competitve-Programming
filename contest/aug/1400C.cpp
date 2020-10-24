#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e5 + 5;
char S[N], ans[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int x, n;
    scanf("%s%d", S, &x);
    n = strlen(S);
    bool poss = true;
    for (int i = 0; i < n; ++i)
      ans[i] = '1';
    for (int i = 0; i < n; ++i) {
      if (S[i] == '1')
	continue;
      if (i - x >= 0)
	ans[i - x] = '0';
      if (i + x < n)
	ans[i + x] = '0';
    }
    for (int i = 0; i < n; ++i) {
      if (S[i] == '0')
	continue;
      int l = i - x, r = i + x;
      if (l >= 0 && ans[l] == '1')
	continue;
      if (r < n && ans[r] == '1')
	continue;
      poss = false;
      break;
    }
    if (poss == false) {
      puts("-1");
      continue;
    }
    ans[n] = '\0';
    puts(ans);
  }
  return 0;
}
