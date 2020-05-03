#include <iostream>
#include <vector>
#include <set>

typedef long long ll;

using namespace std;

struct Dancer {
  int n;
  pair <int, int> D[4];
};

const int N = 1e5;
int r, c, dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
vector <int> mat[N], value[N];
vector <Dancer> dancer[N];
set <int> row[N], col[N];
set <pair <int, pair <int, int>>> avg;
set <pair <int, int>> mod;

bool valid(int i, int j) {
  if (i >= 0 && j >= 0 && i < r && j < c)
    return true;
  return false;
}

void dir(int i, int j) {
  int cnt = 0;
  struct Dancer d;
  for (int m = 0; m < 4; ++m) {
    if (valid(i + dx[m], j + dy[m])) {
      cnt++;
      d.D[m] = {i + dx[m], j + dy[m]};
    }
    else
      d.D[m] = {-1, -1};
  }
  d.n = cnt;
  dancer[i].push_back(d);
}

void Avg(int i, int j) {
  int cnt = dancer[i][j].n;
  int sum = 0;
  for (int m = 0; m < 4; ++m) {
    int x = dancer[i][j].D[m].first,  y;
    y = dancer[i][j].D[m].second;
    if (x == -1)
      continue;
    sum += mat[x][y];
  }
  int diff = cnt * mat[i][j] - sum;
  avg.insert({diff, {i, j}});
  value[i].push_back(diff);
  return;
}

void update(int x, int y) {

  int cnt = 0, sum = 0;
  for (int m = 0; m < 4; ++m) {
    int i = dancer[x][y].D[m].first,  j;
    j = dancer[x][y].D[m].second;
    if (i == -1)
      continue;
    sum += mat[i][j];
    cnt++;
  }
  dancer[x][y].n = cnt;
  int diff = cnt * mat[x][y] - sum;
  int val = value[x][y];
  avg.erase(avg.find({val, {x, y}}));
  avg.insert({diff, {x, y}});
  value[x][y] = diff;
  return ;
}

void Up(int x, int y) {
  
  col[y].insert(x);
  auto v = col[y].find(x);
  auto b = col[y].begin();
  auto e = col[y].end();
  auto u = col[y].upper_bound(x);
  if (u == e) {
    if (v != b) {
      v--;
      dancer[*v][y].D[1] = {-1, -1};
      update(*v, y);
    }
  }
  else {
    if (v != b) {
      v--;
      dancer[*u][y].D[0] = {*v, y};
      update(*u, y);
      dancer[*v][y].D[1] = {*u, y};
      update(*v, y);
    }
    else {
      dancer[*u][y].D[0] = {-1, -1};
      update(*u, y);
    }
  }
  col[y].erase(col[y].find(x));
  
}

void Le(int x, int y) {
  
  row[x].insert(y);
  auto v = row[x].find(y);
  auto b = row[x].begin();
  auto e = row[x].end();
  auto u = row[x].upper_bound(y);
  if (u == e) {
    if (v != b) {
      v--;
      dancer[x][*v].D[3] = {-1, -1};
      update(x, *v);
    }
  }
  else {
    if (v != b) {
      v--;
      dancer[x][*u].D[2] = {x, *v};
      update(x, *u);
      dancer[x][*v].D[3] = {x, *u};
      update(x, *v);
    }
    else {
      dancer[x][*u].D[2] = {-1, -1};
      update(x, *u);
    }
  }
  row[x].erase(row[x].find(y));
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    scanf("%d%d", &r, &c);
    avg.clear();
    for (int i = 0; i < r; ++i) {
      row[i].clear();
      dancer[i].clear();
      mat[i].clear();
      value[i].clear();
    }
    for (int i = 0; i < c; ++i)
      col[i].clear();
    
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
	int s;
	scanf("%d", &s);
	mat[i].push_back(s);
	row[i].insert(j);
	col[j].insert(i);
	dir(i, j);
	//Avg(i, j);
      }
    }
    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
	Avg(i, j);
 
    ll ans = 0;
    int i;
    for (i = 1; ; ++i) {
      auto it = avg.begin();
      if (it == avg.end())
	break;
      int diff = (*it).first;
      if (diff >= 0)
	break;
      mod.clear();
      while (diff < 0) {
	int x = (*it).second.first;
	int y = (*it).second.second;
	mod.insert({x, y});
	row[x].erase(row[x].find(y));
	col[y].erase(col[y].find(x));
	avg.erase(it);
	it = avg.begin();
	if (it == avg.end())
	  break;
	diff = (*it).first;
      }
      for (auto pos : mod) {
	int x = pos.first, y = pos.second;
	Up(x, y);
	Le(x, y);
	ans += (ll)i * mat[x][y];
      }
    }
    while (avg.size()){
      auto it = avg.begin();
      int x = (*it).second.first;
      int y = (*it).second.second;
      ans += (ll)i * mat[x][y];
      avg.erase(it);
    }
    printf("Case #%d: %lld\n", q + 1, ans);
  }
  return 0;
}
