#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 2e5, inf = 1e9;
map <pair <int, int>, int> comp;
vector <int> bit;

struct Query {
  int x, y, z, w;
} query[N];

bool compare(Query &a, Query &b) {
  return a.x < b.x;
}

int minm(int x, int y) {
  int ret = inf;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
      if (comp.find({i, j}) == comp.end()) {
	comp[{i, j}] = bit.size();
	bit.push_back(inf);
	continue;
      }
      int ind = comp.at({i, j});
      ret = min(ret, bit[ind]);
    }
  return ret;
}

void update(int x, int y, int val) {
  for (int i = x; i < N; i = i | (i + 1))
    for (int j = y; j < N; j = j | (j + 1)) {
      if (comp.find({i, j}) == comp.end()) {
	comp[{i, j}] = bit.size();
	bit.push_back(val);
	continue;
      }
      int ind = comp.at({i, j});
      bit[ind] = min(val, bit[ind]);
    }
}

int main () {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x, y, z, w;
    scanf("%d%d%d%d", &x, &y, &z, &w);
    query[i] = {x, y, z, w};
  }
  sort(query, query + n, compare);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    int y, z, w;
    y = query[i].y - 1;
    z = query[i].z - 1;
    w = query[i].w - 1;
    int mn = minm(y - 1, z - 1);
    //if (i == 8)
    //cout << mn << " "<< y <<" " << z << " " << w <<endl;
    if (mn < w) {
      //cout<<i<<" ";
      ans++;
    }
    update(y, z, w);
  }
  //cout<<endl;
  printf("%d\n", n - ans);
  /*
  ans = 0;
  for (int i = 0; i < n; ++i) {
    bool f = false;
    for (int j = 0; j < n; ++j) {
      if (query[i].x > query[j].x && query[i].y > query[j].y &&
	  query[i].z > query[j].z && query[i].w > query[j].w) {
	if (i == 8)
	  cout<<query[j].x<<endl;
	f = true;
      }
    }
    if (f) {
      //cout<<i<<" ";
      ans++;
    }
  }
  //cout<<endl;
  printf("%d\n", n - ans);
  */
  return 0;
}
