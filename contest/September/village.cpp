#include <iostream>
#include <list>

using namespace std;

const int N = 1e5 + 5;
int b[N];
long long dp[N][3], suff[N], pref[N];
list <int> adj[N];

void dfs(int u, int p) {

  dp[u][0] = 0;
  dp[u][1] = -1e12;
  dp[u][2] = b[u];
  int i = 0;
  pref[0] = 0;
  for (int v : adj[u])
    if (v != p)
       dfs(v, u);

  i = adj[u].size() - 1;
  suff[i] = 0;
  for (auto it = adj[u].rbegin(); it != adj[u].rend(); ++it) {
    int v = *it;
    if (v != p && i > 0) {
       suff[i - 1] = suff[i] + max(dp[v][0], max(dp[v][1], dp[v][2]));
    }
    else if (i > 0)
      suff[i - 1] = suff[i];
    i--;
  }
  long long val = -1e12;
  i = 0;
  for (int v : adj[u]) {
    if (v != p) {
      dp[u][0] += max(dp[v][1], dp[v][0]);
      dp[u][2] += max(max(dp[v][1], dp[v][2]), dp[v][0] + b[v]);
      val = max(val,  suff[i] + pref[i] + dp[v][2]);
	  pref[i + 1] = pref[i] + max(dp[v][0], max(dp[v][1], dp[v][2]));
    }
	else
		pref[i + 1] = pref[i];
    i++;
  }
  if (adj[u].size() > 1)
    dp[u][1] = val + b[u];

  //cout<<u+1<<" "<<dp[u][0]<<" "<<dp[u][1]<<" "<<dp[u][2]<<endl;
  return;
}

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int v;
    scanf("%d", &v);
    for (int j = 0; j < v; ++j)
      scanf("%d", b + j);
    for (int j = 0; j < v - 1; ++j) {
      int u, v;
      scanf("%d%d", &u, &v);
      adj[u - 1].push_back(v - 1);
      adj[v - 1].push_back(u - 1);
    }
    dfs(0, 0);
    printf("Case #%d: %lld\n", i + 1, max(dp[0][0], max(dp[0][1], dp[0][2])));
    for (int j = 0; j < v; ++j)
      adj[j].clear();
  }
  return 0;
}
