#include <iostream>
#include <vector>

using namespace std;
using LL = long long;

const int N = 701;
vector <LL> dp[N], adj[N];
int comp_size[N];

void dfs(int u, int p = -1) {

  comp_size[u] = 1;
  for (int v : adj[u]) {

    if (v != p) {
      dfs(v, u);
      comp_size[u] += comp_size[v];
    }
  }

  int n = adj[u].size(), size = comp_size[u];
  dp[u].resize(size + 1);

  vector <vector <LL>> temp(size + 1, vector <LL> (n + 1));

  for (int i = 0; i <= size; ++i) {
    for (int j = 0; j <= n; ++j) {
      if (j == 0) {
        temp[i][j] = (i <= 1 ? 1 : 0);
        continue;
      }

      int v = adj[u][j - 1];
      if (v == p) {
        temp[i][j] = temp[i][j - 1];
        continue;
      }

      int max_size = comp_size[v];
      temp[i][j] = 0;

      for (int k = 0; k <= max_size; ++k) {
        if (i < k)
          break;
        temp[i][j] = max(temp[i][j], dp[v][k] * temp[i - k][j - 1]);
      }
    }
  }

  LL val = 0;

  // cout << u + 1 << "=====\n";
  for (int i = 1; i <= size; ++i) {
    dp[u][i] = temp[i][n];
    // cout << i << " " << dp[u][i] << "\n";
    val = max(val, i * temp[i][n]);
  }

  dp[u][0] = val;
  // cout << val << "======\n";
  
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

  dfs(0);

  printf("%lld\n", dp[0][0]);
  
  return 0;
}
