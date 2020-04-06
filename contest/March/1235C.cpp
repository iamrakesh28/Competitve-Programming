#include <iostream>
#include <list>

using namespace std;

const int N = 1e5 + 5;
int deg[N], edge[N];
list <pair<int, int>> adj[N];
bool mark[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back({v, i});
    adj[v].push_back({u, i});
    deg[u]++;
    deg[v]++;
    mark[i] = false;
  }
  int found = -1;
  for (int i = 0; i < n; ++i) {
    if (deg[i] >= 3)
      found = i;
  }
  if (found != -1) {
    int i = 0;
    for (auto it : adj[found]) {
      int ed = it.second;
      mark[ed] = true;
      edge[ed] = i++;
    }
    for (int j = 0; j < n - 1; ++j)
      if (mark[j] == false)
	edge[j] = i++;
    for (int j = 0; j < n - 1; ++j)
      printf("%d\n", edge[j]);
  }
  else
    for (int i = 0; i < n - 1; ++i)
      printf("%d\n", i);
  return 0;
}
