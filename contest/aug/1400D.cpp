#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 3e3 + 5;
int arr[N];
set <int> dist;
vector <int> start, endw, a[N], d;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    dist.clear();
    d.clear();
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      scanf("%d", arr + i);
      a[arr[i] - 1].push_back(i);
      dist.insert(arr[i] - 1);
    }
    for (int v : dist)
      d.push_back(v);
    for (int i = 0; i < d.size(); ++i)
      for (int j = 0; j < d.size(); ++j) {
	int l = d[i], r = d[j];
	start.clear();
	endw.clear();
	for (int ai : a[l])
	  for (int aj : a[r]) {
	    if (aj <= ai)
	      continue;
	    start.push_back(ai);
	    endw.push_back(aj);
	  }
	ll temp = 0;
	for (int x : endw) {
	  auto it = lower_bound(start.begin(), start.end(), x + 1);
	  ll val = start.end() - it;
	  temp = temp + val;
	}
	ans = ans + temp;
      }
    printf("%lld\n", ans);
    for (int i = 0; i < n; ++i)
      a[arr[i] - 1].clear();
  }
  return 0;
}
