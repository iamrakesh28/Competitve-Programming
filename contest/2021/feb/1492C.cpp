#include <iostream>

using namespace std;

const int N = 2e5 + 5;
char s[N], t[N];
int pref[N], suff[N];

int main() {

  int n, m;
  scanf("%d%d", &n, &m);

  scanf("%s%s", s, t);

  for (int i = 0, j = 0; i < n && j < m; ++i) {
    if (s[i] == t[j]) {
      pref[j] = i;
      j++;
      continue;
    }
  }

  for (int i = n - 1, j = m - 1; i >= 0 && j >= 0; --i) {
    if (s[i] == t[j]) {
      suff[j] = i;
      j--;
      continue;
    }
  }

  int ans = 0;
  for (int i = 0; i < m - 1; ++i) {
    // cout << i + 1 << " " << pref[i] + 1 << " " << suff[i + 1] + 1 << endl;
    ans = max(ans, suff[i + 1] - pref[i]);
  }
  
  printf("%d\n", ans);
  
  return 0;
}
