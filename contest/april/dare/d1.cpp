#include <iostream>
#include <set>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
pair <int, int> point[N];
set <pair <int, int>> X, Y;

int help(int x, int y) {
  int val, id;
  auto it = X.lower_bound({x, -1});
  if (it == X.end()) {
    it--;
    val = abs((*it).first - x);
    id = (*it).second;
  }
  else {
    val = abs((*it).first - x);
    id = (*it).second;
    if (it != X.begin()) {
      it--;
      int temp = abs((*it).first - x);
      if (temp < val) {
	val = temp;
	id = (*it).second;
      }
    }
  }

  int v1, i1;
  it = Y.lower_bound({y, -1});
  if (it == Y.end()) {
    it--;
    v1 = abs((*it).first - y);
    i1 = (*it).second;
  }
  else {
    v1 = abs((*it).first - y);
    i1 = (*it).second;
    if (it != Y.begin()) {
      it--;
      int temp = abs((*it).first - y);
      if (temp < v1) {
	  v1 = temp;
	  i1 = (*it).second;
      }
    }
  }
  if (v1 < val)
    return i1;
  return id;
}

ll span(int n) {
  set <pair <int, pair <int, int>>> s;
  s.insert({0, {0, 0}});
  X.erase(X.find({point[0].first, 0}));
  Y.erase(Y.find({point[0].second, 0}));
  ll ans = 0;
  int edge = 0;
  while (edge < n - 1) {
    auto it = s.begin();
    int val = (*it).first, id1 = (*it).second.first, id2 = (*it).second.second;
    s.erase(it);
    ans += val;
    int x = point[id1].first, y = point[id1].second;
    int id = id1;
    id1 = help(x, y);
    X.erase(X.find({point[id1].first, id1}));
    Y.erase(Y.find({point[id1].second, id1}));
    val = min(abs(point[id1].first - x), abs(point[id1].second - y));
    s.insert({val, {id, id1}});
    edge++;
    cout<<edge<<endl;
    if (id2 == 0)
      continue;
    if (X.size() == 0)
      break;
    x = point[id2].first, y = point[id2].second;
    id = id2;
    id2 = help(x, y);
    X.erase(X.find({point[id2].first, id2}));
    Y.erase(Y.find({point[id2].second, id2}));
    val = min(abs(point[id2].first - x), abs(point[id2].second - y));
    s.insert({val, {id, id2}});
  }
  auto it = s.begin();
  edge = (*it).first;
  ans += edge;
  return ans;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    point[i] = {a, b};
    X.insert({a, i});
    Y.insert({b, i});
  }
  printf("%lld\n", span(n));
  return 0;
}
