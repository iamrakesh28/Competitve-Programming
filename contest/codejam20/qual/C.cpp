#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 1e3 + 5;
char s[N];
pair <int, pair <int, int>> act[N << 1];
set <int> sd;

// 0 -> C
// 1 -> J

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    int n, cnt = 0;
    bool poss = true;
    sd.clear();
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      int si, ei;
      scanf("%d%d", &si, &ei);
      act[2 * i] = {si, {1, i}};
      act[2 * i + 1] = {ei, {-1, i}};
    }
    sort(act, act + 2 * n);
    for (int i = 0; i < (n << 1); ++i) {
      int end = act[i].second.first;
      if (end == -1) {
	cnt--;
	int id = act[i].second.second;
	sd.erase(sd.find(id));
      }
      else {
	cnt++;
	int id = act[i].second.second;
	if (cnt == 1) {
	  s[id] = 'J';
	  sd.insert(id);
	  continue;
	}
	int ot = *sd.begin();
	if (s[ot] == 'J')
	  s[id] = 'C';
	else
	  s[id] = 'J';
	sd.insert(id);
      }
      if (cnt > 2) {
	poss = false;
	break;
      }
    }
    s[n] = '\0';
    printf("Case #%d: ", j + 1);
    if (poss)
      puts(s);
    else
      puts("IMPOSSIBLE");
  }
  return 0;
}
