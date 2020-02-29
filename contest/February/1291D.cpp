#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 5;
char s[N];
int sum[26][N];

int main() {

  int q;
  scanf("%s%d", s, &q);
  int n = strlen(s);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 26; ++j)
      sum[j][i + 1] = sum[j][i];
    sum[s[i] - 'a'][i + 1]++;
  }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    l--, r--;
    if (s[l] != s[r]) {
      puts("Yes");
      continue;
    }
    int cnt = 0, pos = -1;
    for (int i = 0; i < 26; ++i) {
      if (i == s[l] - 'a')
	continue;
      cnt += sum[i][r + 1] - sum[i][l];
    }
    if (cnt >= 2)
      pos = 1;
    if (r == l)
      pos = 1;
    if (pos == 1)
      puts("Yes");
    else
      puts("No");
  }
  return 0;
}
