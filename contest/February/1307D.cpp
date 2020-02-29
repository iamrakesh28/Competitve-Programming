#include <iostream>
#include <list>
#include <cstring>
#include <queue>

using namespace std;

const int N = 2e5 + 5;

int a[N], dist[N], level[N], dist2[N], pt[N];
bool visit[N];
list <int> adj[N];

void bfs(int n) {
  queue <int> s;
  dist[0] = 0;
  s.push(0);
  memset(visit, false, sizeof(bool) * n);
  visit[0] = true;
  while (s.size()) {
    int u = s.front();
    s.pop();
    for (int v : adj[u])
      if (visit[v] == false) {
	visit[v] = true;
	dist[v] = dist[u] + 1;
	s.push(v);
      }
  }
  return ;
}

int bfs2(int n) {
  int pos = -1;
  queue <int> s;
  dist2[n - 1] = 0;
  s.push(n - 1);
  memset(visit, false, sizeof(bool) * n);
  visit[n - 1] = true;
  while (s.size()) {
    int u = s.front();
    s.pop();
    for (int v : adj[u]) {
      if (visit[v] == false) {
	visit[v] = true;
	dist2[v] = dist2[u] + 1;
	s.push(v);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i]) {
      level[dist[i]]++;
      if (level[dist[i]] >= 2)
	pos = 1;
      pt[dist[i]] = i;
    }
  }
  return pos;
}

int main() {
  int n, m, k;
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 0; i < k; ++i) {
    int c;
    scanf("%d", c);
    a[c - 1] = 1;
  }
  for (int i = 0; i < m; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    u--, v--;
    adj[v].push_back(u);
    adj[u].push_back(v);
  }
  bfs(n);
  int ans = dist[n - 1];
  int pos = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0)
      continue;
    for (int v : adj[i])
      if (a[v])
	pos = 1;
  }
  if (pos == 1) {
    printf("%d\n", ans);
    return 0;
  }
  int ts = bfs2(n);
  if (ts == 1) {
    printf("%d\n", ans);
    return 0;
  }
  int prev = -1;
  for (int i = 0; i < n - 1; ++i) {
    if (level[i]) {
      if (prev == -1) {
	prev = pt[i];
	continue;
      }
      int temp = dist[prev] + dist2[pt[i]] + 1;
      ans = max(ans, temp);
      prev = pt[i];
    }
  }
  printf("%d\n", ans);
  return 0;
}
