#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int N = 1e5 + 5;

list <pair <int, int>> adj[N];
pair <int, int> edge[N << 1];
bool nvisit[N], evisit[N << 1];
int a, b;
vector <int> one, two;

bool dfs(int u) {
  nvisit[u] = true;
  bool ret = false;
  for (auto it : adj[u]) {
    if (nvisit[it.first] == false) {
      evisit[it.second] = true;
      ret = ret || dfs(it.first);
    }
    else if (evisit[it.second] == false) {
      ret = true;
      a = it.second;
    }
  }
  return ret;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      nvisit[i] = false;
      adj[i].clear();
    }
    one.clear();
    two.clear();
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      edge[i] = {u, v};
      adj[u].push_back({v, i});
      adj[v].push_back({u, i});
    }
    for (int i = 0; i < n; ++i) {
      if (nvisit[i] == false) {
	bool ret = dfs(i);
	if (ret)
	  two.push_back(a);
	else
	  one.push_back(i);
      }
    }
    for (int i = 0; i < m; ++i)
      evisit[i] = false;
    int ans = 0;
    vector <pair <int, int>> ed;
    for (int i = 1; i < one.size(); ++i)
      ed.push_back({one[i - 1], one[i]});
    if (one.size())
      ans = 2 * one.size() - 2;
    for (int i = 1; i < two.size(); ++i) {
      evisit[two[i]] = true;
      int u = two[i], v = two[i - 1];
      ed.push_back({edge[v].first, edge[u].second});
    }
    if (two.size()) {
      evisit[two[0]] = true;
      int u = two[0], v = two[two.size() - 1];
      ed.push_back({edge[v].first, edge[u].second});
    }
    if (one.size() && two.size()) {
      ed.push_back({one[0], edge[two[0]].first});
      ans += 2;
    }
    for (int i = 0; i < m; ++i)
      if (evisit[i] == false)
	ed.push_back(edge[i]);
    printf("%d %d\n", ans, ed.size());
    for (auto it : ed)
      printf("%d %d\n", it.first + 1, it.second + 1);
  }
  return 0;
}
