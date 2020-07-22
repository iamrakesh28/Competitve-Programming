#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
const int N = 1e4 + 5, x = 0x7fffffff, K = 15;
const ll inf = -1e18;
int node[N];
ll dp[N][K], arr[N][K];
vector <int> adj[N];

void dfs(int u, int p, int k) {
  vector <int> sep;
  for (int v : adj[u])
    if (v != p) {
      dfs(v, u, k);
      sep.push_back(v);
    }
  int n = sep.size();
  for (int i = 0; i <= k; ++i)
    for (int j = 0; j <= n; ++j) {
      if (j == 0) {
	if (i == 0)
	  arr[i][j] = 0;
	else
	  arr[i][j] = inf;
	continue;
      }
      arr[i][j] = inf;
      for (int r = 0; r <= i; ++r)
	arr[i][j] = max(arr[i][j], dp[sep[j - 1]][r] + arr[i - r][j - 1]);
    }
  for (int i = 0; i <= k; ++i) {
    int v = node[u];
    if (i & 1)
      v = v ^ x;
    if (n)
      dp[u][i] = v + arr[i][n];
    else
      dp[u][i] = v;
  }
  sep.clear();
}

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i)
    scanf("%d", node + i);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  dfs(0, 0, k);
  ll ans = dp[0][k];
  //for (int i = 1; i <= k; ++i)
  //ans = max(ans, dp[0][i]);
  //cout<<dp[0][1]<<endl;
  printf("%lld\n", ans);
  return 0;
}
