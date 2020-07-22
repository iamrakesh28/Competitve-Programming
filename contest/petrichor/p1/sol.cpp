#include <iostream>
#include <set>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5e5 + 5;
pair <int, pair<int, int>> line[N << 1];
set <int> points;
map <int, int> range;
struct Query {
  int m;
  vector <int> vec;
} query[N];

void calc(multiset <int> &curR, int l) {
  auto it = points.begin();
  while (points.size()) {
    if ((*it) >= l)
      break;
    if (curR.size()) {
      auto mx = curR.end();
      mx--;
      range[*it] = *mx;
    }
    points.erase(it);
    it = points.begin();
  }
  return;
}

void solve(int n) {
  multiset <int> curR;
  for (auto v : points)
    range[v] = -1;
  for (int i = 0; i < (n << 1) && points.size(); ++i) {
    auto l = line[i];
    if (l.second.first == 1) {
      calc(curR, l.first + 1);
      curR.erase(curR.find(l.first));
    }
    else {
      calc(curR, l.first);
      curR.insert(l.second.second);
    }
  }
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    line[2 * i] = {l, {-1, r}};
    line[2 * i + 1] = {r, {1, l}};
  }
  sort(line, line + 2 * n);
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int m;
    scanf("%d", &m);
    query[i].m = m;
    for (int j = 0; j < m; ++j) {
      int ai;
      scanf("%d", &ai);
      points.insert(ai);
      query[i].vec.push_back(ai);
    }
    sort(query[i].vec.begin(), query[i].vec.end());
  }
  solve(n);
  for (int i = 0; i < q; ++i) {
    int m = query[i].m;
    int ans,  maxR;
    for (int j = 0; j < m; ++j) {
      int ai = query[i].vec[j];
      if (j) {
	if (maxR < ai) { 
	  maxR = range[ai];
	  ans++;
	}
      }
      else {
	maxR = range[ai];
	ans = 1;
      }
      if (maxR == -1) {
	ans = -1;
	break;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
