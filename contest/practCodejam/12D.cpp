#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int inf = 1e9;

class BIT {
public:
  int n;
  vector <int> bit;
  BIT (int n) {
    this->n = n;
    bit.assign(n, inf);
  }

  int query(int x) {
    int res = inf;
    //cout<<x<<" ";
    for (; x >= 0; x = (x & (x + 1)) - 1)
      res = min(res, bit[x]);
    //cout<<res<<endl;
    return res;
  }
  
  void update(int x, int val) {
    for (int i = x; i < n; i = i | (i + 1))
      bit[i] = min(bit[i], val);
  }
};

struct Query {
  int b, i, r;
};

bool compare(Query &a, Query &b) {
  if (a.b != b.b)
    return a.b > b.b;
  if (a.i != b.i)
    return a.i > b.i;
  return a.r > b.r;
}

map <int, int> mp;
set <int> st;
vector <Query> query;

int main() {
  int n, uniq;
  scanf("%d", &n);
  query.resize(n);
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    query[i].b = a;
    st.insert(a);
  }
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    query[i].i = a;
    st.insert(a);
  }
  for (int i = 0; i < n; ++i) {
    int a;
    scanf("%d", &a);
    query[i].r = a;
    st.insert(a);
  }
  uniq = st.size();
  BIT fenw(uniq);
  for (int x : st)
    mp.insert({x, --uniq});
  sort(query.begin(), query.end(), compare);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int ii = mp.at(query[i].i), ri = mp.at(query[i].r);
    //cout<<query[i].b<<" "<<query[i].i<<" "<<query[i].r<<endl;
    //cout<<ii<<" "<<ri<<endl;
    int minm = fenw.query(ii - 1);
    //cout<<minm<<endl;
    if (minm < ri)
      ans++;
    fenw.update(ii, ri);
  }
  printf("%d\n", ans);
  return 0;
}
