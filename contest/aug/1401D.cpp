#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

typedef long long ll;
const int N = 1e5 + 5, prime = 1e9 + 7;
list <int> adj[N];
vector <ll> edge;
int pi[N], cnt[N], n;

void reset(int n) {
  for (int i = 0; i < n; ++i)
    adj[i].clear();
  edge.clear();
  return;
}

void dfs(int u, int p) {
  cnt[u] = 1;
  ll val = 0;
  for (int v : adj[u]) {
    if (v != p) {
      dfs(v, u);
      cnt[u] += cnt[v];
      val = cnt[v];
      val = val * (n - cnt[v]);
      edge.push_back(val);
    }
  }
  return;
}

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int m;
    scanf("%d", &n);
    reset(n);
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i)
      scanf("%d", pi + i);
    int len = m;
    while (len < n - 1)
      pi[len++] = 1;
    sort(pi, pi + len);
    dfs(0, 0);
    //for (int i : edge)
    //  cout << i << endl;
    sort(edge.begin(), edge.end());
    ll ans = 0;
    for (int i = 0; i < n - 2; ++i) {
      ll temp = pi[i];
      temp = (temp * edge[i]) % prime;
      ans = (ans + temp) % prime;
      //cout << edge[] << 
    }
    ll temp = 1;
    for (int i = n - 2; i < len; ++i)
      temp = (temp * pi[i]) % prime;
    temp = (temp * edge[n - 2]) % prime;
    ans = (ans + temp) % prime;
    printf("%lld\n", ans);
  }
  return 0;
}
