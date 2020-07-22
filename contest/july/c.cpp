#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 5e5 + 5, l = 21;

list <int> adj[N];
vector <int> A[N], B[N], C[N];
int dp[N][3], arr[N], a, b, up[N][l];
ll lcm;

int find(int v, int len) {
  int cur = 0, node = v;
  for (int i = l - 1; i >= 0; i--) {
    if (cur + (1 << i) > len)
      continue;
    cur = cur + (1 << i);
    node = up[node][i];
  }
  return node;
}

void dfs1(int v, int p, int ht) {
  up[v][0] = p;
  for (int i = 1; i < l; ++i)
    up[v][i] = up[up[v][i - 1]][i - 1];
  for (int u : adj[v])
    if (u != p)
      dfs1(u, v, ht + 1);
  if (ht >= a)
    A[find(v, a)].push_back(v);
  if (ht >= b)
    B[find(v, b)].push_back(v);
  if (ht >= lcm)
    C[find(v, lcm)].push_back(v);
  return;
}

void dfs(int v, int p) {
  dp[v][0] = dp[v][1] = dp[v][2] = 1;
  for (int u : adj[v])
    if (u != p)
      dfs(u, v);
  for (int u : A[v])
    dp[v][0] += dp[u][0];
  for (int u : B[v])
    dp[v][1] += dp[u][1];
  for (int u : C[v])
    dp[v][2] += dp[u][2];
}

int main() {
  int t;
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    int n;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 0; i < n; ++i) {
      A[i].clear();
      B[i].clear();
      adj[i].clear();
    }
    lcm = a;
    lcm = lcm * b;
    lcm = lcm / __gcd(a, b);
    for (int i = 0; i < n - 1; ++i) {
      scanf("%d", arr + i);
      adj[i + 1].push_back(arr[i] - 1);
      adj[arr[i] - 1].push_back(i + 1);
    }
    dfs1(0, 0, 0);
    dfs(0, 0);
    double ans = 0;
    double d = n;
    for (int i = 0; i < n; ++i) {
      double temp;// = dp[i][0] + dp[i][1] - dp[i][2] + 1;
      temp = dp[i][0] / d;
      temp = temp * ((d - dp[i][0]) / d);
      double temp2 = dp[i][1] / d;
      temp2 = temp2 * ((d - dp[i][1]) / d);
      //cout<<i+1<<" "<<dp[i][2]<<endl;
      double temp3 = (dp[i][1] + dp[i][0] - dp[i][2]) / (d * d);
      //temp3 = temp3 * dp[i][1] / d;
      //temp3 = temp3 * ((d - dp[i][1]) / d);
      //cout<<i+1<<" "<<dp[i][0]<<" "<<dp[i][1]<<endl;
      // temp = temp / n;
      temp3 = (d - (dp[i][1] + dp[i][0] - dp[i][2])) / d;
      ans = ans + 1 - temp3;//temp + temp2 + temp3;
    }
    printf("Case #%d: %lf\n", j + 1, ans);
  }
  return 0;
}
