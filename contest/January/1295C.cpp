#include <iostream>
#include <set>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
char s[N], t[N];
set <int> alph[26];

int main() {

  int q;
  scanf("%d", &q);
  while (q--) {
    int lenS, lenT, poss = 1;
    scanf("%s%s", s, t);
    lenS = strlen(s);
    lenT = strlen(t);
    for (int i = 0; i < 26; ++i)
      alph[i].clear();
    for (int i = 0; i < lenS; ++i)
      alph[s[i] - 'a'].insert(i);
    for (int i = 0; i < lenT; ++i) {
      if (alph[t[i] - 'a'].size() == 0) {
	poss = -1;
	break;
      }
    }
    if (poss == -1) {
      puts("-1");
      continue;
    }
    int ans = 0, i = 0, pos = 0;
    while (i < lenT) {
      auto it = alph[t[i] - 'a'].lower_bound(pos);
      if (it == alph[t[i] - 'a'].end()) {
	pos = *alph[t[i] - 'a'].begin();
	pos++;
	ans++;
	i++;
	continue;
      }
      pos = *it;
      pos++;
      //prev++;
      i++;
    }
    ans++;
    printf("%d\n", ans);
  }
  return 0;
}
