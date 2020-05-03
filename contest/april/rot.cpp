#include <iostream>
#include <set>

using namespace std;

set <pair <int, int>> s;
set <int> val;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    s.clear();
    val.clear();
    int n, ans = 1, cnt = 0;
    scanf("%d", &n);
    ans = 1;
    for (int i = 0; i < n; ++i) {
      int a;
      scanf("%d", &a);
      val.insert(a);
      s.insert({a, i});
    }
    int id = -1;
    for (int v : val) {
      auto it = s.lower_bound({v, id});
      if (it == s.end()) {
	ans++;
	it = s.lower_bound({v, -1});
	id = (*it).second;
	continue;
      }
      int cur = (*it).second, num = (*it).first;
      if (num != v) {
	ans++;
	it = s.lower_bound({v, -1});
	id = (*it).second;
      }
      else
	id = cur;
    }
    printf("%d\n", ans);
  }
  return 0;
}
