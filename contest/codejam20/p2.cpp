#include <iostream>
#include <list>
#include <vector>

using namespace std;

const int N = 25;
list <int> adj[N];
bool visit[N];
int dp[N];

void dfs(int u, int p) {
  visit[u] = true;
  int val = 0;
  for (int v : adj[u]) {
    if (visit[v] == false)
      dfs(v, u);
    if (v != p)
      val = max(val, dp[v]);
  }
  dp[u] = val + 1;
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) {
      adj[i].clear();
      visit[i] = false;
    }
    for (int i = 0; i < m; ++i) {
      int a, b;
      scanf("%d%d", &a, &b);
      a--, b--;
      adj[a].push_back(b);
    }
    for (int i = 0; i < n; ++i) {
      if (visit[i] == false)
	dfs(i, i);
      //cout<<i+1<<" "<<dp[i]<<endl;
      ans = max(ans, dp[i]);
    }
    printf("Case #%d: %d\n", q + 1, ans);
  }
  return 0;
}
