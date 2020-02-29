#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;
char s[N];
set <int> st[26];

int main() {
	
  char ch;
  int j = 0;
  while ((ch = getchar()) != '\n') {
    s[j++] = ch;
    st[ch - 'a'].insert(j - 1);
  }
  //cout<<s<<endl;
  int q;
  scanf("%d", &q);
  while (q--) {
    int i, l, r, cnt;
    char c;
    scanf("%d%d", &i, &l);
    if (i == 1) {
      scanf(" %c", &c);
      l--;
      st[s[l] - 'a'].erase(l);
      s[l] = c;
      st[c - 'a'].insert(l);
    }
    else {
      scanf("%d", &r);
      cnt = 0; 
      l--, r--;
      for (int i = 0; i < 26; ++i) {
	auto it = st[i].lower_bound(l);
	if (it == st[i].end())
	  continue;
	auto it2 = ++it;
	if (it2 == st[i].end())
	  continue;
	if (*it2 <= r)
	  cnt++;
      }
      printf("%d\n", cnt);
    }
  }
  return 0;
}
