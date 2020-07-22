#include <iostream>
#include <set>
#include <cstring>
#include <vector>
#include <list>

using namespace std;

const int N = 5e5 + 5;
list <int> adj[N];
vector <int> inv[N];
int blog[N];

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[b - 1].push_back(a - 1);
    adj[a - 1].push_back(b - 1);
  }
  for (int i = 0; i < n; ++i) {
    int ti;
    scanf("%d", &ti);
    inv[ti - 1].push_back(i);
  }
  memset(blog, -1, sizeof blog);
  bool poss = true;
  for (int i = 0; i < n; ++i) {
    for (int v : inv[i]) {
      set <int> cnt;
      for (int u : adj[v])
	if (blog[u] != -1)
	  cnt.insert(blog[u]);
      if (cnt.size() >= i + 1) {
	poss = false;
	break;
      }
      if (cnt.size() < i) {
	poss = false;
	break;
      }
      blog[v] = i;
      if (i == 0)
	continue;
      auto it = cnt.end();
      it--;
      if ((*it) >= i) {
	poss = false;
	break;
      }
    }
    if (poss == false)
      break;
  }
  if (poss == false) {
    puts("-1");
    return 0;
  }
  vector <int> ans;
  for (int i = 0; i < n; ++i)
    for (int v : inv[i])
      ans.push_back(v + 1);
  for (int v : ans)
    printf("%d ", v);
  puts("");
  return 0;
}
