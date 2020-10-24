#include <iostream>
#include <list>

using namespace std;
const int N = 2e5 + 5;
list <int> adj[N];
int dist[N], dp[N][2];

void dfs(int u, int p) {
  dp[u][0] = dp[u][1] = 0;
  int l = 0, r = 0;
  for (int v : adj[u]) {
    if (v == p)
      continue;
    dist[v] = dist[u] + 1;
    dfs(v, u);
    if (dp[v][0] + 1 > l) {
      int temp = l;
      l = dp[v][0] + 1;
      r = temp;
    }
    else if (dp[v][0] + 1 > r) {
      r = dp[v][0] + 1;
    }
    dp[u][0] = max(dp[u][0], dp[v][0] + 1);
  }
  dp[u][1] = l + r;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, a, b, da, db;
    scanf("%d%d%d%d%d", &n, &a, &b, &da, &db);
    for (int i = 0; i < n; ++i)
      adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      adj[v].push_back(u);
      adj[u].push_back(v);
    }
    if (2 * da >= db) {
      puts("Alice");
      continue;
    }
    a--, b--;
    dist[b] = 0;
    dfs(b, b);
    if (dist[a] <= da) {
      puts("Alice");
      continue;
    }
    int diam = 0;
    for (int i = 0; i < n; ++i)
      diam = max(diam, dp[i][1]);
    //cout << diam << endl;
    bool poss = false;
    for (int i = 0; i < n; ++i) {
      if (dist[i] > 2 * da)
	poss = true;
    }
    if (poss) {
      puts("Bob");
      continue;
    }
    if (diam > 2 * da)
      puts("Bob");
    else
      puts("Alice");
      
  }
  return 0;
}
