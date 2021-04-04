#include <iostream>
#include <queue>
#include <list>
#include <cassert>

using namespace std;

const int N = 9e6 + 5;
list <int> adj[N];
bool visit[N];

int convert(int x, int y, int n) { return x * n + y; }

int bfs(int s) {

  queue <pair <int, int>> q;
  q.push({0, s});
  visit[s] = true;
  
  int zero = 1, one = 0;
  while (q.size()) {
    auto u = q.front();
    q.pop();

    for (int v : adj[u.second]) {
      
      if (visit[v]) {
        //assert(u.first != );
        continue;
      }
      visit[v] = true;
      q.push({1 - u.first, v});
      if (u.first == 1)
        zero++;
      else
        one++;
    }
  }
  
  return max(zero, one);
}

int main() {

  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < m; ++i) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    x1--, x2--, y1--, y2--;
    int u = convert(x1, y1, n), v = convert(x2, y2, n);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  for (int i = 0; i < n; ++i)
    for (int j = 0; j < n; ++j) {
      int u = convert(i, j, n);
      visit[u] = false;
    }
  
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      int u = convert(i, j, n);
      if (visit[u] == false)
        ans += bfs(u);
    }
  }
  
  printf("%d\n", ans);
  return 0;
}
