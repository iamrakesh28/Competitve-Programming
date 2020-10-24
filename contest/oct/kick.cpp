#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
typedef long long ll;
int suff[N];
char s[N], kick[] = "KICK", start[] = "START";

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n;
    scanf("%s", s);
    n = strlen(s);
    ll ans = 0;
    memset(suff, 0, sizeof(int) * n);
    for (int i = n - 5; i >= 0; i--) {
      bool same = true;
      for (int j = i; j < i + 5; ++j)
	if (s[j] != start[j - i]) {
	  same = false;
	  break;
	}
      suff[i] = suff[i + 1];
      if (same)
	suff[i]++;
    }

    for (int i = 3; i < n; i++) {
      bool same = true;
      for (int j = i - 3; j <= i; ++j)
	if (s[j] != kick[j - i + 3]) {
	  same = false;
	  break;
	}
      if (same)
	ans += suff[i];
    }
    printf("Case #%d: %lld\n", q + 1, ans);
  }
  return 0;
}
