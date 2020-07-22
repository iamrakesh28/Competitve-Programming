#include <iostream>
#include <cstring>

using namespace std;

int s[1050], test[1050];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, pos = -1, ans;
    scanf("%d", &n);
    memset(s, 0, sizeof s);
    for (int i = 0; i < n; ++i) {
      int d;
      scanf("%d", &d);
      s[d] = 1;
    }
    for (int i = 1; i < 1024; ++i) {
      memset(test, 0, sizeof test);
      for (int j = 0; j < 1024; ++j)
	if (s[j])
	  test[j ^ i] = 1;
      int cnt = 1;
      for (int j = 0; j < 1024; ++j) {
	if (s[j] != test[j]) {
	  cnt = 0;
	  break;
	}
      }
      if (cnt) {
	ans = i;
	pos = 1;
	break;
      }
    }
    if (pos == -1) {
      puts("-1");
      continue;
    }
    printf("%d\n", ans);
  }
  return 0;
}
