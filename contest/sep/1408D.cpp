#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

typedef long long ll;

const int inf = 1e9;
vector <pair<int, int>> rob, lg;
set <int> lx;
map <int, int> light;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    int ai, bi;
    scanf("%d%d", &ai, &bi);
    rob.push_back({ai, bi});
  }
  for (int i = 0; i < m; ++i) {
    int ci, di;
    scanf("%d%d", &ci, &di);
    lg.push_back({ci, di});
    /*lx.insert(ci);
    if (light.find(ci) == light.end())
      light[ci] = di;
    else
      light[ci] = max(di, light[ci]);
    */
  }
  sort(lg.begin(), lg.end());
  int mx = -1;
  for (int i = m - 1; i >= 0; --i) {
    if (lg[i].second > mx) {
      int ci = lg[i].first, di = lg[i].second;
      lx.insert(ci);
      if (light.find(ci) == light.end())
	light[ci] = di;
      else
	light[ci] = max(di, light[ci]);
      mx = max(mx, di);
    }
  }
  int ans = inf, cur = 0;
  for (int i = 0; i <= max(n, m) + 2; ++i) {
    int temp = 0;
    for (int j = 0; j < n; ++j) {
      auto it = lx.lower_bound(rob[j].first);
      if (it == lx.end())
	continue;
      int ci = *it;
      int di = light[ci];
      if (di < rob[j].second)
	continue;
      temp = max(temp, di - rob[j].second + 1);
    }
    ans = min(ans, temp + cur);
    //cout << ans << endl;
    int dt = inf;
    for (int j = 0; j < n; ++j) {
      auto it = lx.lower_bound(rob[j].first);
      if (it == lx.end())
	continue;
      int ci = *it;
      int di = light[ci];
      if (di < rob[j].second)
	continue;
      dt = min(dt, ci - rob[j].first + 1);
    }
    if (dt >= inf)
      break;
    for (int j = 0; j < n; ++j)
      rob[j].first += dt;
    cur += dt;
    //cout << cur << endl;
  }
  printf("%d\n", ans);
  return 0;
}
