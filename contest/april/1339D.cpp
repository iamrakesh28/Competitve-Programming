#include <iostream>
#include <list>

using namespace std;

const int N = 1e5 + 5;
list <int> adj[N];
int deg[N], maxm[N], minm[N], f = 1;

bool dfs1(int u, int p) {
  int ans = 0, ch = 0;
  bool child = true;
  for (int v : adj[u]) {
    if (v != p) {
      child = false;
      if (dfs1(v, u))
	ch++;
      else {
	ans += maxm[v];
	ans++;
      }
    }
  }
  if (ch)
    ans++;
  maxm[u] = ans;
  return child;
}

void dfs2(int u, int p) {
  minm[u] = 0;
  int a = 0, b = 0;
  for (int v : adj[u]) {
    if (v != p) {
      dfs2(v, u);
      if (minm[v])
	a++;
      else
	b++;
    }
  }
  if (a && b)
    f = 3;
  else {
    if (b)
      minm[u] = 1;
  }
  return;
}

int main() {
  int n, root;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--, b--;
    adj[a].push_back(b);
    adj[b].push_back(a);
    deg[a]++, deg[b]++;
    if (deg[a] > 1)
      root = a;
    else if (deg[b] > 1)
      root = b;
  }
  bool ret = dfs1(root, root);
  dfs2(root, root);
  printf("%d %d\n", f, maxm[root]);
  return 0;
}
