#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5, inf = 1e9 + 9;
map <int, pair <int, int>> mp;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, mn = inf;
    scanf("%d", &n);
    mp.clear();
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      if (mp.find(ai) == mp.end())
	mp.insert({ai, {1, 0}});
      else
	mp[ai] = {mp[ai].first + 1, 0};
      mn = min(mn, ai);
    }
    for (int i = 0; i < n; ++i) {
      int bi;
      scanf("%d", &bi);
      if (mp.find(bi) == mp.end())
	mp.insert({bi, {0, 1}});
      else
	mp[bi] = {mp[bi].first, mp[bi].second + 1};
      mn = min(mn, bi);
    }
    bool pos = true;
    vector <int> val;
    for (auto it : mp) {
      int cnt = it.second.first + it.second.second;
      if (cnt & 1) {
	pos = false;
	break;
      }
      //cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<endl;
      int diff = abs(it.second.first - it.second.second);
      diff >>= 1;
      while (diff) {
	val.push_back(it.first);
	diff--;
      }
    }
    if (pos == false) {
      puts("-1");
      continue;
    }

    ll ans = 0, sz = val.size() >> 1;
    sort(val.begin(), val.end());
    for (int i = 0; i < sz; ++i) {
      if (val[i] <= 2 * mn)
	ans = ans + val[i];
      else
	ans = ans + 2 * mn;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
