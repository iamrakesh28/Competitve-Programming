#include <iostream>
#include <set>
#include <algorithm>
#include <map>

typedef long long ll;
using namespace std;

const int N = 1e5;
ll t[N << 2];
map <int, int> mp;
set <int> st;
pair <int, pair <int, int>> ring[N];

void update(int v, int tl, int tr, int pos, ll val) {
  if (tl == tr) {
    t[v] = val;
    return;
  }
  int tm = tl + tr >> 1;
  if (pos <= tm)
    update(2 * v + 1, tl, tm, pos, val);
  else
    update(2 * v + 2, tm + 1, tr, pos, val);
  t[v] = max(t[2 * v + 1], t[2 * v + 2]);
  return;
}

ll query(int v, int tl, int tr, int l, int r) {
  if (l > r)
    return 0;
  if (l == tl && r == tr)
    return t[v];
  int tm = tl + tr >> 1;
  return max(query(2 * v + 1, tl, tm, l, min(tm, r)),
	     query(2 * v + 2, tm + 1, tr, max(l, tm + 1), r));
}

bool compare(pair <int, pair <int, int>> &a, pair <int, pair <int, int>> &b) {
  if (a.first == b.first)
    return a.second.first > b.second.first;
  return a.first > b.first;
}

int main() {

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b, h;
    scanf("%d%d%d", &a, &b, &h);
    ring[i] = {b, {a, h}};
    st.insert(a);
  }
  int cnt = 0;
  for (int x : st)
    mp.insert({x, cnt++});
  sort(ring, ring + n, compare);
  //reverse(ring, ring + n);
  for (int i = 0; i < n; ++i) {
    int b = ring[i].first, a = ring[i].second.first, h = ring[i].second.second, v;
    auto it = st.lower_bound(b);
    //cout<<a<<" "<<b<<endl;
    if (it == st.end())
      v = cnt - 1;
    else {
      if (it == st.begin()) {
	v = mp.at(a);
	update(0, 0, cnt - 1, v, h);
	continue;
      }
      else {;
	it--;
	v = mp.at(*it);
      }
    }
    //cout<<v<<" ";
    ll temp = query(0, 0, cnt - 1, 0, v);
    v = mp.at(a);
    ll gre = query(0, 0, cnt - 1, v, v);
    //cout<<v<<" "<<gre<<" "<<temp<<endl;
    if (gre < temp + h)
      update(0, 0, cnt - 1, v, temp + h);
  }
  ll ans = query(0, 0, cnt - 1, 0, cnt - 1);
  printf("%lld\n", ans);
  return 0;
}
