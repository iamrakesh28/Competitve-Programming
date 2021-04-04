#include <iostream>
#include <list>
#include <set>

using namespace std;

typedef long long LL;
const int N = 3e4 + 5;
const LL INF = 1e15;

list <pair<LL, int>> adj[N];
bool visit[N], emply[N];
LL dist[N];

int convert(int x, int y, int n) { return x * n + y; }

LL spanning(int s, int n) {

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n; ++j) {
      int u = convert(i, j, n);
      visit[u] = false;
      dist[u] = INF;
    }
  }

  set <pair <LL, int>> st;
  st.insert({0, s});
  visit[s] = true;
  dist[s] = 0;

  LL sum = 0;

  while (st.size()) {
    auto it = *st.begin();
    int u = it.second;
    LL w = it.first;
    visit[u] = true;
    st.erase(st.begin());

    if (emply[u])
      sum += w;
    
    for (auto v : adj[u]) {
      if (visit[v.second])
        continue;

      LL new_wt = v.first;
      if (emply[u] == false)
        new_wt += w;

      if (dist[v.second] == INF) {
        dist[v.second] = new_wt;
        st.insert({new_wt, v.second});
      }
      else if (dist[v.second] > new_wt) {
        st.erase(st.find({dist[v.second], v.second}));
        dist[v.second] = new_wt;
        st.insert({new_wt, v.second});
      }
    }
    
  }
  
  return sum;
}

int main() {

  int n, m;
  scanf("%d%d", &n, &m);

  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      int ai;
      scanf("%d", &ai);

      int u = convert(i, j, n), v = convert(i, j + 1, n);
      adj[u].push_back({ai, v});
      adj[v].push_back({ai, u});
      
    }
  }

  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      int bi;
      scanf("%d", &bi);

      int u = convert(i, j, n), v = convert(i + 1, j, n);
      adj[u].push_back({bi, v});
      adj[v].push_back({bi, u});
      
    }
  }

  int start;
  bool done = false;
  for (int i = 0; i < m; ++i) {
    int r, c;
    scanf("%d%d", &r, &c);
    r--, c--;
    int u = convert(r, c, n);
    emply[u] = true;

    if (done == false) {
      start = u;
      done = true;
    }
  }

  LL ans = spanning(start, n);
  printf("%lld\n", ans);
  
  return 0;
}
