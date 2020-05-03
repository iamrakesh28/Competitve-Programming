#include <iostream>
#include <set>

typedef long long ll;
using namespace std;

set <int> s;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    ll n, k, start;
    s.clear();
    scanf("%lld%lld", &n, &k);
    start = ((k << 1) % n) + 1;
    start = start % n;
    for (int i = 0; i < n; ++i)
      s.insert(i);
    while (s.size() > 1) {
      s.erase(s.find(start));
      if (s.size() == 1)
	break;
      auto it = s.upper_bound(start);
      if (it == s.end()) {
	it = s.begin();
	it++;
	start = *it;
      }
      else {
	it++;
	if (it == s.end())
	  it = s.begin();
	start = *it;
      }
    }
    start = *s.begin();
    printf("%lld\n", start + 1);
  }
  return 0;
}
