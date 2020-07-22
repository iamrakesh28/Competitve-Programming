#include <iostream>
#include <queue>
#include <list>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 5;
list <int> adj[N];
vector <int> s1, s2;
int par[N], col[N], vert1, vert2;

bool bfs(int s) {
  queue <int> q;
  q.push(s);
  bool poss = true;
  col[s] = 0;
  par[s] = s;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u]) {
      if (col[v] == -1) {
	col[v] = 1 - col[u];
	par[v] = u;
	q.push(v);
      }
      else if (col[u] == col[v]) {
	vert1 = u;
	vert2 = v;
	poss = false;
	break;
      }
    }
  }
  return poss;
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < n; ++i)
    col[i] = -1;
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  bool poss = bfs(0);
  if (poss) {
    puts("1");
    int c1 = 0, c2 = 0;
    for (int i = 0; i < n; ++i)
      if (col[i])
	c2++;
      else
	c1++;
    int cnt = k / 2;
    if (k & 1)
      cnt++;
    if (c1 >= c2) {
      for (int i = 0; i < n && cnt; ++i) {
	if (col[i] == 0) {
	  printf("%d ", i + 1);
	  cnt--;
	}
      }
      puts("");
    }
    else {
      for (int i = 0; i < n && cnt; ++i) {
	if (col[i]) {
	  printf("%d ", i + 1);
	  cnt--;
	}
      }
      puts("");
    }
  }
  else {
    vector <int> cycle, cyc1, cyc2;
    int v = vert1;
    while (v != 0) {
      cyc1.push_back(v);
      v = par[v];
    }
    cyc1.push_back(0);
    v = vert2;
    while (v != 0) {
      cyc2.push_back(v);
      v = par[v];
    }
    cyc2.push_back(0);
    int i;
    reverse(cyc1.begin(), cyc1.end());
    reverse(cyc2.begin(), cyc2.end());
    for (int j = 1; j < cyc1.size(); ++j) {
      if (cyc1[j] != cyc2[j]) {
	i = j - 1;
	break;
      }
    }
    for (int j = i; j < cyc1.size(); ++j)
      cycle.push_back(cyc1[j]);
    for (int j = i + 1; j < cyc2.size(); ++j)
      cycle.push_back(cyc2[j]);
    if (cycle.size() <= k) {
      puts("2");
      printf("%d\n", cycle.size());
      for (int v : cycle)
	printf("%d ", v + 1);
      puts("");
    }
    else {
      int cnt = k / 2;
      if (k & 1)
	cnt++;
      puts("1");
      for (int i = 0; i < cycle.size() && cnt; i += 2) {
	printf("%d ", cycle[i] + 1);
	cnt--;
      }
      puts("");
    }
  }
  return 0;
}
