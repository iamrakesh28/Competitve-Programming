#include <iostream>
#include <set>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
ll A[N];
multiset <ll> s;

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    s.clear();
    int n, d, ans = 2;
    scanf("%d%d", &n, &d);
    for (int i = 0; i < n; ++i) {
      scanf("%lld", A + i);
      s.insert(A[i]);
    }
    printf("Case #%d: ", j + 1);
    int found = 0;
    for (auto it : s)
      if (s.count(it) >= d) {
	found = 1;
	ans = 0;
	break;
      }
    if (found) {
      printf("%d\n", ans);
      continue;
    }
    if (d == 2) {
      printf("%d\n", 1);
      continue;
    }
    for (auto it : s)
      if (s.count(it) >= 2) {
	auto f = s.upper_bound(it);
	if (f != s.end()) {
	  found = 1;
	  ans = 1;
	  break;
	}
      }
    if (found) {
      printf("%d\n", ans);
      continue;
    }
    for (auto it : s) {
      if (it % 2 == 0) {
	if (s.count(it / 2)) {
	  ans = 1;
	  break;
	}
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
