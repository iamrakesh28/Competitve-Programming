#include <iostream>
#include <vector>
#include <set>

#define POS(x) (x + 100000 - 1)

using namespace std;

const int N = 1e5 + 5;
vector <int> road[3 * N];
multiset <int> st;
int D[N], A[N], B[N];

int main() {
  int q;
  scanf("%d", &q);
  for (int j = 0; j < q; ++j) {
    int s, cnt = 0;
    long long ans = 0;
    scanf("%d", &s);
    for (int i = 0; i < 3 * N; ++i)
      road[i].clear();
    st.clear();
    for (int i = 0; i < s; ++i) {
      int d, a, b;
      scanf("%d%d%d", &d, &a, &b);
      D[i] = d;
      A[i] = a;
      B[i] = b;
      road[POS(d + a)].push_back(i);
      road[POS(d - b)].push_back(i);
    }
    for (int i = 0; i < 3 * N; ++i) {
      if (road[i].size() == 0)
	continue;
      st.insert(road[i].size());
    }
    for (int i = 3 * N - 1; i >= 0; i--) {
      if (road[i].size() == 0)
	continue;
      st.erase(st.find(road[i].size()));
      for (int v : road[i]) {
	if (D[v] >= i - 100000 + 1)
	  continue;
	int pos = D[v] - B[v];
	st.erase(st.find(road[POS(pos)].size()));
	st.insert(road[POS(pos)].size() - 1);
      }
      if (st.size() == 0)
	break;
      auto it = st.end();
      it--;
      long long prod = (long long)road[i].size() + (*it);
      if (prod == ans)
	cnt++;
      else {
	ans = max(ans, prod);
	cnt = 1;
      }
      for (int v : road[i]) {
	if (D[v] >= i - 100000 + 1)
	  continue;
	int pos = D[v] - B[v];
	st.insert(road[POS(pos)].size());
      }
    }
    printf("Case #%d: %lld\n", j + 1, ans);
  }
  return 0;
}
