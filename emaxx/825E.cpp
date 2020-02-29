#include <iostream>
#include <list>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;

bool visit[N];
int size[N], perm[N];
list <int> adj[N];

void dfs1(int u) {
  visit[u] = true;
  size[u] = 1;
  for (int v : adj[u]) {
    if (visit[v] == false)
      dfs1(v);
    size[u] += size[v];
  }
  return;
}

int dfs2(int u) {
  visit[u] = true;
  int ans = 0;
  for (int v : adj[u]) {
    if (visit[v] == false)
      ans += dfs2(v);
    else
      ans += size[v];
  }
  return ans;
}

int main() {

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
  }
  for (int i = 0; i < n; ++i)
    dfs1(i);
  memset(visit, false, sizeof(bool) * n);
  int prev = 0;
  for (int i = 0; i < n; ++i) {
    if (visit[i] == false) {
      int ans = dfs2(i);
      ans = size[i] - ans;
      perm[i] = prev + ans;
      prev = perm[i];
    }
    else {
    }
  }
  return 0;
}
