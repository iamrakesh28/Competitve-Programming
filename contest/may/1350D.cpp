#include <iostream>
#include <set>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
int cnt[N], a[N];
set <pair <int, int>> s;

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, c = 0, ans = -1;
    scanf("%d%d", &n, &k);
    memset(cnt, 0, sizeof(int) * n);
    s.clear();
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      a[i] = ai;
      if (ai < k)
	cnt[i]++;
      else if (ai == k)
	c = 1;
    }
    if (c == 0) {
      puts("no");
      continue;
    }
    if (n == 1) {
      puts("yes");
      continue;
    }
    for (int i = 1; i < n; ++i)
      cnt[i] += cnt[i - 1];
    int sum = 0, eq = 0;
    for (int i = 0; i < n; ++i) {
      if (a[i] != k)
	sum++;
      else
	eq++;
      int val = sum - eq;
      if (i)
	s.insert({val, -i});
    }
    auto it = *s.begin();
    if (it.first < 0) {
      puts("yes");
      continue;
    }
    else if (it.first == 0) {
      int id = -it.second;
      int find = cnt[id];
      if (2 * find != id + 1) {
	puts("yes");
	continue;
      }
    }
    eq = 0, sum = 0;
    for (int i = 0; i < n - 2; ++i) {
      if (a[i] != k)
	sum++;
      else
	eq++;
      while (s.size()) {
	auto it = s.begin();
	int id = (*it).second;
	id = -id;
	if (id > i + 1)
	  break;
	s.erase(it);
      }
      auto it = *s.begin();
      int s1 = it.first, id = -it.second;
      s1 = s1 - sum;
      s1 = s1 + eq;
      if (s1 < 0) {
	ans = 1;
	break;
      }
      else if (s1 == 0) {
	int temp = id;
	id = id - i;
	int val = cnt[temp] - cnt[i];
	if (2 * val != id) {
	  ans = 1;
	  break;
	}
      }
    }
    if (ans == 1) {
      puts("yes");
      continue;
    }
  }
  return 0;
}
