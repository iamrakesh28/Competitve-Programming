#include <iostream>
#include <set>
#include <map>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
map <int, int> mp;
set <int> st;
int bit[N], d;
pair <int, int> point[N];

void update(int x, int delta) {
  for (; x < d; x = x | (x + 1))
    bit[x] += delta;
}

int sum(int x) {
  int ret = 0;
  for (; x >= 0; x = (x & (x + 1)) - 1)
    ret += bit[x];
  return ret;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    mp.clear();
    st.clear();
    memset(bit, 0, sizeof bit);
    for (int i = 0; i < n; ++i) {
      int x, y;
      scanf("%d%d", &x, &y);
      point[i] = {x, y};
      st.insert(y);
    }
    sort(point, point + n);
    d = 0;
    int i, c = 1;
    for (int x : st)
      mp.insert({x, d++});
    for (i = 1; i < n; ++i) {
      if (point[i] != point[i - 1]) {
	int temp, v, s;
	v = mp.at(point[i - 1].second);
	s = sum(v);
	temp = abs(n - 1 - 2 * s);
	if (temp >= k)
	  cnt = cnt + c;
	update(v, c);
	c = 1;
      }
      else
	c++;
    }
    int temp, v, s;
    v = mp.at(point[i - 1].second);
    s = sum(v);
    temp = abs(n - 1 - 2 * s);
    if (temp >= k)
      cnt += c;
    //update(v, c);
    printf("%d\n", cnt);
  }
  return 0;
}
