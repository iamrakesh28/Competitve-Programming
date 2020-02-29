#include <iostream>
#include <list>
#include <cstring>

using namespace std;

const int N = 105;
int n, s[N], dp[N][N];
list <int> adj[N];

void dfs(int u, int p) {
  memset(dp[u], 0, sizeof dp[u]);
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      for (int i = 0; i < n; ++i)
	  dp[u][i + 1] += dp[v][i];
    }
  }
  if (s[u] == 1)
    dp[u][0]++;
  return;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      adj[i].clear();
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    for (int i = 0; i < n; ++i)
      scanf("%d", s + i);
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
      dfs(i, i);
      long long diff = 0;
      for (int v : adj[i]) {
	for (int j = 0; j < n; ++j) {
	  if (dp[v][j] < 3)
	    continue;
	  long long temp = dp[v][j];
	  temp = temp * (temp - 1) * (temp - 2);
	  diff = diff + temp;
	}
      }
      for (int v : adj[i]) {
	for (int j = 0; j < n; ++j) {
	  if (dp[v][j] < 2)
	    continue;
	  long long temp = dp[v][j];
	  temp = temp * (temp - 1) * (dp[i][j + 1] - temp);
	  diff = diff + temp * 3;
	}
      }
      for (int j = 1; j <= n; ++j) {
	if (dp[i][j] >= 3) {
	  //cout<<j<<" "<<dp[i][j]<<endl;
	  long long temp = dp[i][j];
	  ans = ans + temp * (temp - 1) * (temp - 2);
	}
	
      }
      ans = ans - diff;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
