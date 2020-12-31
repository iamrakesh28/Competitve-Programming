#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 1;
char s[N], t[N];

int main() {

  scanf("%s%s", s, t);

  int si, sj, n = strlen(s);
  si = sj = -1;

  for (int i = 0; i < n; ++i) {
    if (s[i] != t[i]) {
      si = i;
      break;
    }
  }

  for (int i = n - 1; i >= 0; i--) {
    if (s[i] != t[i]) {
      sj = i;
      break;
    }
  }
  if (si == -1) {
    puts("YES");
    return 0;
  }

  bool poss = true;
  // cout << si << " " << sj << endl;
  for (int i = si; i <= sj; ++i) {
    if (s[i] != t[si + sj - i]) {
      poss = false;
      break;
    }
  }
  
  if (poss)
    puts("YES");
  else
    puts("NO");
  return 0;
}
