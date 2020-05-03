#include <iostream>
#include <cstring>
#include <set>
#include <vector>

typedef long long ll;
using namespace std;

const int N = 1e6 + 5;
char S[N], R[N];
vector <int> seg;
multiset <int> st;

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, len = 0, l, r;
    ll ans, temp, mx = 0;
    seg.clear();
    st.clear();
    scanf("%s%s", S, R);
    n = strlen(S);
    for (int i = 0; i < n; ++i) {
      if (S[i] != R[i]) {
	seg.push_back(len);
	len = 0;
      }
      else
	len++;
    }
    seg.push_back(len);
    if (seg.size() == 1) {
      puts("0");
      continue;
    }
    for (int i = 1; i < seg.size() - 1; ++i) {
      if (seg[i])
	st.insert(seg[i]);
    }
    l = seg[0];
    r = n - 1 - seg[seg.size() - 1];
    ans = r - l + 1;
    for (int i = 2; i <= n; ++i) {
      if (st.size() == 0)
	break;
      auto it = st.end();
      it--;
      mx = mx + (*it);
      st.erase(it);
      temp = (ll)i * (r - l + 1 - mx);
      ans = min(ans, temp);
    }
    printf("%lld\n", ans);
  }
  return 0;
}
