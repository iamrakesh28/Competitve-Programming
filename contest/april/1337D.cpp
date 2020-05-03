#include <iostream>
#include <set>

typedef long long ll;
using namespace std;

const ll inf = 4e18;
set <int> r, g, b;

ll solve(int x, set <int>& s1, set <int>& s2) {
  int l, u;
  auto it = s1.lower_bound(x);
  if (it == s1.end()) {
    it--;
    l = *it;
  }
  else {
    l = *it;
    if (it == s1.begin() && l > x)
      return inf;
    if (l > x) {
      it--;
      l = *it;
    }
  }
  it = s2.lower_bound(x);
  if (it == s2.end())
    return inf;
  u = *it;
  ll ans = (ll)(x - l) * (x - l);
  ans += (ll)(x - u) * (x - u);
  ans += (ll)(l - u) * (l - u);
  return ans;
}


int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int nr, ng, nb;
    r.clear();
    g.clear();
    b.clear();
    scanf("%d%d%d", &nr, &ng, &nb);
    for (int i = 0; i < nr; ++i) {
      int c;
      scanf("%d", &c);
      r.insert(c);
    }
    for (int i = 0; i < ng; ++i) {
      int c;
      scanf("%d", &c);
      g.insert(c);
    }
    for (int i = 0; i < nb; ++i) {
      int c;
      scanf("%d", &c);
      b.insert(c);
    }

    ll ans = inf;
    for (int x : r) {
      ans = min(ans, solve(x, g, b));
      ans = min(ans, solve(x, b, g));
    }
    for (int x : g) {
      ans = min(ans, solve(x, r, b));
      ans = min(ans, solve(x, b, r));
    }
    for (int x : b) {
      ans = min(ans, solve(x, g, r));
      ans = min(ans, solve(x, r, g));
    }
    printf("%lld\n", ans);
  }
  return 0;
}
