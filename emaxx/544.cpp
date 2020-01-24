#include <iostream>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

const int N = 2e4;
pair <int, pair <int, int>> edge[N];
map <string, int> mp;
int parent[205], size[205];
list <pair<int, int>> adj[205];

int dfs(int u, int par, int dest) {
  for (auto it : adj[u]) {
    if (it.second != par) {
      if (it.second == dest)
	return it.first;
      int v = dfs(it.second, u, dest);
      if (v != -1)
	return min(v, it.first);
    }
  }
  return -1;
}

int find(int u) {
  if (u == parent[u])
    return u;
  parent[u] = find(parent[u]);
  return parent[u];
}

void join(int u, int v, int w) {
  int u1 = find(u);
  int v1 = find(v);
  if (u1 == v1)
    return;
  adj[u].push_back({w, v});
  adj[v].push_back({w, u});
  if (size[u1] > size[v1]) {
    parent[v1] = u1;
    size[u1] += size[v1];
  }
  else {
    parent[u1] = v1;
    size[v1] += size[u1];
  }
}

int main() {

  int n, r, cnt, scn = 0;
  while (scanf("%d%d", &n, &r) != EOF && (n || r)) {
    mp.clear();
    cnt = 0;
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
      size[i] = 1;
      adj[i].clear();
    }
    for (int i = 0; i < r; ++i) {
      string a, b;
      int w;
      //scanf("%s%s%d", &a, &b, &w);
      cin>>a>>b>>w;
      int u, v;
      if (mp.find(a) != mp.end())
	u = mp.at(a);
      else
	mp[a] = cnt++, u = cnt - 1;
      if (mp.find(b) != mp.end())
	v = mp.at(b);
      else
	mp[b] = cnt++, v = cnt - 1;
      edge[i] = {w, {u, v}};
    }
    sort(edge, edge + r);
    int s, t;
    string a, b;
    //scanf("%s%s", &a, &b);
    cin>>a>>b;
    s = mp.at(a);
    t = mp.at(b);
    for (int i = r - 1; i >= 0; i--) {
      int u = edge[i].second.first;
      int v = edge[i].second.second;
      join(u, v, edge[i].first);
    }
    int ans = dfs(s, s, t);
    printf("Scenario #%d\n%d tons\n\n", ++scn, ans);
  }
  return 0;
}
