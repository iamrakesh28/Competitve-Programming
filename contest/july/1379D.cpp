#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

int main() {
  int n, h, m, k;
  scanf("%d%d%d%d", &n, &h, &m, &k);
  vector <int> minu;
  for (int i = 0; i < n; ++i) {
    int hi, mi;
    scanf("%d%d", &hi, &mi);
    minu.push_back(mi);
  }
  set <int> cur;
  sort(minu.begin(), minu.end());
  ll r = 0, l;
  l = (r - k + m) % m;
  //l = (l + m) % m;
  for (int v : minu) {
    if (v >= l)
      cur.insert(v - m);
    else if (v <= r)
      cur.insert(v);
  }
  int ans = cur.size(), t = 0;
  if (cur.find(l - m) != cur.end())
    ans--;
  if (cur.find(r) != cur.end())
      ans--;
  //cout<<ans<<endl;
  set <pair <int, int>> interval;
  interval.insert({r, ans});
  for (int v : minu) {
    if (v <= r)
      continue;
    r = v;
    l = r - k;
    auto it = cur.begin();
    while (cur.size()) {
      if ((*it) < l)
	cur.erase(it);
      else
        break;
      it = cur.begin();
    }
    cur.insert(v);
    int temp = cur.size();
    if (cur.find(l) != cur.end())
      temp--;
    if (cur.find(r) != cur.end())
      temp--;
    interval.insert({r, temp});
  }

  
  ans = (int)1e9;
  for (auto it : interval) {
    if (it.first < m / 2)
      continue;
    auto it1 = interval.lower_bound({it.first - m / 2, -1});
    int temp = (*it1).second + it.second;
    if (temp < ans) {
      ans = temp;
      t = (*it1).first;
    }
  }
  r = t;
  l = (r - k + m) % m;
  vector <int> train;
  if (l > r) {
    for (int i = 0; i < minu.size(); ++i)
      if (minu[i] > l || minu[i] < r)
	train.push_back(i+1);
    r = r + m / 2;
    l = r - k;
    for (int i = 0; i < minu.size(); ++i)
      if (minu[i] > l && minu[i] < r)
	train.push_back(i+1);
  }
  else {
    for (int i = 0; i < minu.size(); ++i)
      if (minu[i] > l && minu[i] < r)
	train.push_back(i+1);
    r = r + m / 2;
    l = r - k;
    for (int i = 0; i < minu.size(); ++i)
      if (minu[i] > l && minu[i] < r)
	train.push_back(i+1);
  }
  printf("%d %d\n", ans, t);
  for (int v : train)
    printf("%d ", v);
  puts("");
  return 0;
}
