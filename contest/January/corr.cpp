#include <iostream>
#include <list>

using namespace std;

const int N = 1e6 + 5;
long long dp[N];
list <int> adj[N];

void dfs(int u, int p) {
  dp[u] = 0;
  long long sum = 0;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      sum = sum + max((long long)1, dp[v]);
    }
  }

  long long ans = 0;
  for (int v : adj[u]) {
    if (v != p) {
      if (dp[v] == 0)
	ans = max(ans, sum - 1);
      else
	ans = sum;	    
    }
  }
  dp[u] = ans;
  return;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0);
  long long ans = dp[0];
  printf("%lld\n", max((long long)1, ans));
  return 0;
}
