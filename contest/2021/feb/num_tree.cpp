#include <iostream>
#include <vector>
#include <cmath>
#include <list>
#include <algorithm>

using namespace std;
using LL = long long;

const int N = 1e5, MAX = 1e6 + 5;

vector <pair<int, int>> leaves[N];
int node_map[N], par[N], child_cnt[N];
list <int> adj[N], adj_comp[N];

int dfs(int u, int p) {

  int pchild = u, child;
  if (u) {
    if (child_cnt[u] == 1)
      pchild = par[u];
    else if (child_cnt[u] == 0) {
      node_map[u] = u;
      return u;
    }
  }

  for (int v : adj[u]) {
    if (v == p)
      continue;
    par[v] = pchild;
    child = dfs(v, u);
  }

  if (child_cnt[u] == 1) {
    node_map[u] = child;
    return child;
  }
  node_map[u] = u;
  
  return u;
}

void dfs_compress(int u, int p) {

  int size = child_cnt[u];
  if (size == 0) {
    leaves[u].push_back({1, 1});
    return;
  }
  
  vector <int> factors;

  for (int v : adj_comp[u]) {
    if (v == p)
      continue;
    dfs_compress(v, u);

    for (auto it : leaves[v]) {
      int fact = it.first;
      if ((LL)fact * size > MAX)
        continue;
      for (int cnt = 0; cnt < it.second; ++cnt)
        factors.push_back(fact * size);
    }
  }

  sort(factors.begin(), factors.end());
  int cnt = 1;
  for (int i = 1; i < factors.size(); ++i) {
    if (factors[i] != factors[i - 1]) {
      leaves[u].push_back({factors[i - 1], cnt});
      cnt = 1;
    }
    else
      cnt++;
  }
  if (factors.size())
    leaves[u].push_back({factors[factors.size() - 1], cnt});
  
  return;
}

int main() {

  int n;
  scanf("%d", &n);

  par[0] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    int pi;
    scanf("%d", &pi);
    par[i] = pi - 1;
    child_cnt[pi - 1]++;

    adj[i].push_back(pi - 1);
    adj[pi - 1].push_back(i);
  }

  int res = dfs(0, 0);
  node_map[0] = 0;
  for (int i = 1; i <= n - 1; ++i) {
    int pi = par[i];
    if (child_cnt[i] == 1)
      continue;

    adj_comp[i].push_back(pi);
    adj_comp[pi].push_back(i);
  }

  /*
  for (int i = 0; i < n; ++i) {
    cout << i + 1 << " " << child_cnt[i] << "------\n";
    for (int v : adj_comp[i])
      cout << v + 1 << " ";
    cout << endl;
  }
  */
  
  dfs_compress(0, 0);
  /*
  for (int v = 0; v < n; ++v) {
    cout << v + 1 << " " << node_map[v] + 1 << endl;
  }
  */
  
  int q;
  scanf("%d", &q);
  while (q--) {
    int v, w;
    scanf("%d%d", &v, &w);
    v = node_map[v - 1];

    int exec = 0, sq = sqrt(w);
    // cout << v + 1 << " " << leaves[v].size() << endl;
    if (leaves[v].size() <= sq) {
      for (auto div : leaves[v]) {
        if (w % div.first == 0) {
          int cnt = w / div.first;
          cnt = cnt * div.second;
          exec += cnt;
        }
      }
    }
    else {
      for (int i = 1; i * i <= w; ++i) {
        if (w % i == 0) {
          auto div = lower_bound(leaves[v].begin(), leaves[v].end(), make_pair(i, -1));
          if (div != leaves[v].end() && div -> first == i) {
            int cnt = w / i;
            cnt = cnt * (div -> second);
            exec += cnt;
          }

          if (i * i == w)
            continue;
          
          div = lower_bound(leaves[v].begin(), leaves[v].end(), make_pair(w / i, -1));
          if (div != leaves[v].end() && div -> first == w / i) {
            int cnt = i;
            cnt = cnt * (div -> second);
            exec += cnt;
          }
        }
      }
    }

    printf("%d\n", w - exec);
  }
  
  return 0;
}
