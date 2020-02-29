#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
char s[N];
int color[26];
pair <int, int> alph[26], line[52];

int main() {

  int n, cnt = 0;
  char ch;
  scanf("%d", &n);
  ch = getchar();
  for (int i = 0; i < 26; ++i)
    alph[i] = {1e6, -1};
  for (int i = 0; i < n; ++i) {
    ch = getchar();
    s[i] = ch;
    alph[ch - 'a'].first = min(alph[ch - 'a'].first, i);
    alph[ch - 'a'].second = max(alph[ch - 'a'].second, i);
  }
  for (int i = 0; i < 26; ++i) {
    if (alph[i].second == -1)
      continue;
    line[cnt++] = {alph[i].first, -1};
    line[cnt++] = {alph[i].second, 1};
  }

  int ans = 1, cur = 0;
  sort(line, line + cnt);
  for (int i = 0; i < cnt; ++i) {
    int r;
    r = line[i].second;
    //cout<<cur<<" "<<line[i].first<<endl;
    if (r == 1)
      cur--;
    else
      cur++;
    ans = max(ans, cur);
  }
  
  printf("%d\n", ans);
  /*
  for (int i = 0; i < n; ++i)
    printf("%d ", color[s[i] - 'a']);
  */
  puts("");
  return 0;
}
