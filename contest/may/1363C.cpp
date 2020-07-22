#include <iostream>
#include <cstring>
#include <list>

using namespace std;

list <int> adj[1005];
int def[1005], xo;

int dfs(int u, int p, int x) {
  int sum = 1, val = 0;
  for (int v : adj[u]) {
    if (v == p)
      continue;
    val = dfs(v, u, x);
    sum += val;
    if (u == x)
      xo = xo ^ val; 
  }
  return sum;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, x;
    scanf("%d%d", &n, &x);
    x--;
    xo = 0;
    for (int i = 0; i < n; ++i) {
      adj[i].clear();
      //def[i] = 0;
    }
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
      //def[u]++, def[v]++;
    }
    int val = dfs(x, x, x);
    if (xo) {
      puts("Ayush");
    }
    else
      puts("Ashish");
  }
  return 0;
}
