#include <iostream>
#include <set>
#include <list>

using namespace std;

const int N = 2e5;

int par[N], ht[N], tin[N], tout[N], cnt = 0;
set <pair <int, int>> node, st;
list <int> adj[N];

void dfs(int u, int p, int height) {
  ht[u] = height;
  tin[u] = cnt++;
  for (int v : adj[u])
    if (v != p)
      dfs(v, u, height + 1);
  tout[u] = cnt++;
}

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[v - 1].push_back(u - 1);
    adj[u - 1].push_back(v - 1);
    par[v - 1] = u - 1;
  }
  dfs(0, 0, 0);
  while (m--) {
    int k;
    bool ans = true;
    scanf("%d", &k);
    node.clear();
    st.clear();
    for (int i = 0; i < k; ++i) {
      int ki;
      scanf("%d", &ki);
      node.insert({ht[ki - 1], ki - 1});
    }
    /*
    auto last = node.end();
    last--;
    pair <int, int> lst = *last;
    node.erase(last);
    */
    for (auto it : node) {
      int p = par[it.second];
      st.insert({ht[p], p});
    }
    int ent = tin[0], ext = tout[0];
    for (auto it : st) {
      if (tin[it.second] >= ent && tout[it.second] <= ext) {
	ent = tin[it.second];
	ext = tout[it.second];
	continue;
      }
      ans = false;
      break;
    }
    if (ans)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
