#include <iostream>
#include <set>

using namespace std;

const int N = 1e5 + 5;
int p[N], ran[N], cnt[N];
multiset <int> s;
set <int> r;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, ans = 1;
    scanf("%d", &n);
    s.clear();
    r.clear();
    for (int i = 0; i < n; ++i) {
      scanf("%d", p + i);
      ran[p[i] - 1] = i;
      cnt[i] = 1;
      s.insert(1);
      r.insert(i);
    }
    for (int i = 0; i < n; ++i) {
      int pos = ran[i], val;
      val = cnt[pos];
      auto it = s.end();
      it--;
      int mx = *it;
      if (mx > val) {
	ans = -1;
	break;
      }
      val--;
      s.erase(s.find(cnt[pos]));
      cnt[pos] = 0;
      r.erase(r.find(pos));
      auto i1 = r.upper_bound(pos);
      if (i1 != r.end()) {
	i1--;
	int v = *i1;
	s.erase(s.find(cnt[v]));
	cnt[v] += val;
	s.insert(cnt[v])
      }
      s.erase(s.find(cnt[j]));
      cnt[j] += val;
      s.insert(cnt[j]);
      s.erase(it);
    }
    if (ans == -1) {
      puts("No");
      continue;
    }
    puts("Yes");
  }
  return 0;
}
