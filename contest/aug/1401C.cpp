#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5, inf = 1e9 + 10;
bool poss[N];
int ai[N];
vector <int> sw;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, mn = inf;
    scanf("%d", &n);
    sw.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", ai + i);
      mn = min(mn, ai[i]);
      poss[i] = false;
    }
    bool ans = true;
    for (int i = 0; i < n; ++i) {
      if (ai[i] % mn == 0) {
	sw.push_back(ai[i]);
	poss[i] = true;
      }
    }
    sort(sw.begin(), sw.end());
    int ind = 0;
    for (int i = 0; i < n; ++i) {
      if (poss[i] == false)
	continue;
      ai[i] = sw[ind++];
    }
    for (int i = 1; i < n; ++i)
      if (ai[i - 1] > ai[i]) {
	ans = false;
	break;
      }
    if (ans)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
