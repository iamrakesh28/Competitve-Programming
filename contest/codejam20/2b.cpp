#include <iostream>
#include <set>
#include <list>

using namespace std;

const int N = 105;
list <pair <int, int>> adj[N];
int ans[N * 10], C[N];
bool visit[N];

void solve(int n) {
  memset(visit, false, sizeof(bool) * n);
  int tm = 1, cnt = 1;
  set <pair<int, pair <int, int>>> s1, s2;
  visit[0] = true;
  for (auto it : adj[u]) {
      int v = it.first;
      if (visit[v] == false) {
	int xi = C[v];
	if (xi < 0)
	  s1.insert({-xi, {v, it.second}});
	else
	  s2.insert({xi, {v, it.second}});
	visit[v] = true;
      }
  }
  
  while (s1.size() || s2.size()) {
    int u;
    if (s1.size()) {
      it = s1.begin();
      int xi = (*it).first, edge = (*it).second.second;
      if (xi == cnt) {
	tm++;
	cnt++;
	ans[edge] = tm;
	u = (*it).second.first;
	s1.erase(it);
      }
      else {
	it = s2.begin();
	int xi = (*it).first, edge = (*it).second.second;
	u = (*it).second.first;
	s2.erase(it);
	ans[edge] = xi;
	tm = xi;
	cnt++;
      }
    }
    else {
      	auto it = s2.begin();
	int xi = (*it).first, edge = (*it).second.second;
	u = (*it).second.first;
	s2.erase(it);
	ans[edge] = xi;
	tm = xi;
	cnt++;
    }
    for (auto it : adj[u]) {
      int v = it.first;
      if (visit[v] == false) {
	int xi = C[v];
	if (xi < 0)
	  s1.insert({-xi, {v, it.second}});
	else
	  s2.insert({xi, {v, it.second}});
	visit[v] = true;
      }
    }
  }
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    int c, d;
    scanf("%d%d", &c, &d);
    for (int i = 0; i < c - 1; ++i)
      scanf("%d", C + i);
    for (int i = 0; i < c; ++i)
      adj[i].clear();
    for (int i = 0; i < d; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u - 1].push_back({v - 1, i});
      adj[v - 1].push_back({u - 1, i});
      ans[i] = -1;
    }
  }
  return 0;
}
