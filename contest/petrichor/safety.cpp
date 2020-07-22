#include <iostream>
#include <queue>
#include <list>
#include <cstring>
#include <vector>

using namespace std;

typedef long long ll;

const int N = 205;
const ll inf = 1e18;
int d[N], p[N], s[N];
ll cap[N << 1][N << 1];
list <int> adj[N << 1];

ll bfs(int s, int t, vector <int>& parent) {
  fill(parent.begin(), parent.end(), -1);
  parent[s] = -2;
  queue <pair <int, ll>> q;
  q.push({s, inf});
  while (!q.empty()) {
    int cur = q.front().first;
    ll flow = q.front().second;
    q.pop();

    for (int next : adj[cur]) {
      if (parent[next] == -1 && cap[cur][next]) {
	parent[next] = cur;
	ll new_flow = min(flow, cap[cur][next]);
	if (next == t)
	  return new_flow;
	q.push({next, new_flow});
      }
    }
  }
  return 0;
}

ll maxflow(int s, int t, int n) {
  ll flow = 0;
  vector <int> parent(n);
  ll new_flow;
  while (new_flow = bfs(s, t, parent)) {
    flow += new_flow;
    int cur = t;
    while (cur != s) {
      int prev = parent[cur];
      cap[prev][cur] -= new_flow;
      cap[cur][prev] += new_flow;
      cur = prev;
    }
  }
  return flow;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, vert;
    ll sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", d + i);
    for (int i = 0; i < n; ++i)
      scanf("%d", p + i);
    int S;
    scanf("%d", &S);
    memset(s, 0, sizeof(int) * n);
    for (int i = 0; i < S; ++i) {
      int si;
      scanf("%d", &si);
      s[si] = 1;
    }
    int m1, m2, m3, g, h;
    scanf("%d", &m1);
    for (int i = 0; i < m1; ++i) {
      int u, v, c;
      scanf("%d%d%d", &u, &v, &c);
      cap[u + n][v] += c;
    }
    scanf("%d%d", &m2, &g);
    for (int i = 0; i < m2; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      cap[u + n][v] += g;
    }
    scanf("%d%d", &m3, &h);
    for (int i = 0; i < m3; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      cap[u + n][v] += h;
    }
    int src = (n << 1), sink = (n << 1) + 1;
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i]) {
	ans += d[i];
	cap[i][sink] = inf;
      }
      else {
	cap[src][i] = d[i];
	sum += d[i];
      }
    }
    int tot = sink + 1;
    for (int i = 0; i < n; ++i)
      cap[i][i + n] = p[i];
    for (int i = 0 ; i < tot; ++i)
      for (int j = 0; j < tot; ++j)
	if (cap[i][j]) {
	  adj[i].push_back(j);
	  adj[j].push_back(i);
	}
    ll solve = maxflow(src, sink, tot);
    if (solve == sum)
      puts("All Safe");
    else
      printf("%lld\n", solve + ans);
    for (int i = 0; i < tot; ++i)
      adj[i].clear();
    for (int i = 0; i < tot; ++i)
      for (int j = 0; j < tot; ++j)
	cap[i][j] = 0;
  }
  return 0;
}
