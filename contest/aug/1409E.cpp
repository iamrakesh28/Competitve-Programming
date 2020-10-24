#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
multiset <int> st;
int xi[N], mx[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; ++i)
      scanf("%d", xi + i);
    int y;
    for (int i = 0; i < n; ++i)
      scanf("%d", &y);
    st.clear();
    sort(xi, xi + n);
    for (int i = 0; i < n; ++i) {
      st.insert(xi[i]);
      int first = *st.begin();
      while (first < xi[i] - k) {
	st.erase(st.begin());
	first = *st.begin();
      }
      mx[i] = st.size();
      if (i)
	mx[i] = max(mx[i], mx[i - 1]);
    }
    int ans = 0;
    st.clear();
    for (int i = n - 1; i >= 0; i--) {
      st.insert(xi[i]);
      auto it = st.end();
      it--;
      int last = *it;
      while (last > xi[i] + k) {
	st.erase(it);
	it = st.end();
	it--;
	last = *it;
      }
      if (i)
	ans = max(ans, (int)st.size() + mx[i - 1]);
      else
	ans = max(ans, (int)st.size());
    }
    printf("%d\n", ans);
  }
  return 0;
}
