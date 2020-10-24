#include <iostream>
#include <cstring>

using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
char s[N];

ll pref[N], suff[N];

int main() {
  int n, a, b;
  scanf("%s%d%d", s, &a, &b);
  n = strlen(s);
  for (int i = 0; i < n; ++i) {
    if (i) {
      int val = s[i] - '0';
      pref[i] = (10 * pref[i - 1] + val) % a;
    }
    else
      pref[i] = (s[i] - '0') % a;
  }
  ll ten = 10;
  for (int i = n - 1; i >= 0; --i) {
    if (i < n - 1) {
      int val = s[i] - '0';
      suff[i] = (ten * val + suff[i + 1]) % b;
      ten = 10 * ten % b;
    }
    else
      suff[i] = (s[i] - '0') % b;
  }
  int ind = -1;
  for (int i = 1; i < n; ++i) {
    if (s[i] == '0')
      continue;
    if (pref[i - 1] == 0 && suff[i] == 0) {
      ind = i;
      break;
    }
    //cout << pref[i] << " " << i + 1 << " " << suff[i] << endl;
  }
  if (ind == -1) {
    puts("NO");
    return 0;
  }
  puts("YES");
  for (int i = 0; i < ind; ++i)
    putchar(s[i]);
  puts("");
  for (int i = ind; i < n; ++i)
    putchar(s[i]);
  puts("");
  return 0;
}
