#include <iostream>
#include <list>
#include <set>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
list <int> adj[N];
bool visit[N];
int pi[N];
set <pair<int, int>> st[4];
multiset <int> s;
vector <int> parent[2];
vector <pair <int, int>> pind;

void bfs(vector <int> &p, int s, int n) {
  memset(visit, false, sizeof(bool) * n);
  queue <int> q;
  q.push(s);
  p[s] = s;
  visit[s] = true;
  while (q.size()) {
    int u = q.front();
    q.pop();
    for (int v : adj[u])
      if (visit[v] == false) {
	visit[v] = true;
	q.push(v);
	p[v] = u;
      }
  }
  return;
}

void solve(int a, int b, int c) {

  for (int i = 1; i < 4; ++i)
    st[i].clear();
  // a -> b
  int prev = parent[0][b], cur;
  if (prev != b)
    st[1].insert({min(b, prev), max(b, prev)});
  while (prev != a) {
    cur = parent[0][prev];
    st[1].insert({min(prev, cur), max(cur, prev)});
    prev = cur;
  }

  // a-> c
  prev = parent[0][c];
  if (prev != c)
    st[2].insert({min(c, prev), max(c, prev)});
  while (prev != a) {
    cur = parent[0][prev];
    st[2].insert({min(prev, cur), max(cur, prev)});
    prev = cur;
  }
  
  // b -> c
  prev = parent[1][c];
  if (prev != c)
    st[3].insert({min(c, prev), max(c, prev)});
  while (prev != b) {
    cur = parent[1][prev];
    st[3].insert({min(prev, cur), max(cur, prev)});
    prev = cur;
  }
  
  return;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, m, a, b, c;
    scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
    a--, b--, c--;
    for (int i = 0; i < 2; ++i)
      parent[i].resize(n);
    for (int i = 0; i < n; ++i)
      adj[i].clear();
    for (int i = 0; i < m; ++i)
      scanf("%d", pi + i);
    for (int i = 0; i < m; ++i) {
      int u, v;
      scanf("%d%d", &u, &v);
      u--, v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
    }
    bfs(parent[0], a, n);
    bfs(parent[1], b, n);
    solve(a, b, c);
    sort(pi, pi + m);
    long long ans;
    s.clear();
    pind.clear();
    if (a == b) {
      if (a == c)
	ans = 0;
      else
	ans = pi[st[2].size() - 1];
      printf("%lld\n", ans);
      continue;
    }
    if (a == c) {
      ans = pi[st[1].size() - 1] * 2;
      printf("%lld\n", ans);
      continue;
    }
    for (auto v : st[1])
      pind.push_back(v);
    for (auto v : st[3])
      pind.push_back(v);
    sort(pind.begin(), pind.end());
    int cnt = 1, i;
    for (i = 1; i < pind.size(); ++i) {
      if (pind[i] != pind[i - 1]) {
	s.insert(cnt);
	cnt = 1;
      }
      else
	cnt++;
    }
    s.insert(cnt);
    ans = 0, i = 0;
    while (s.size()) {
      auto it = s.end();
      it--;
      int v = *it;
      s.erase(it);
      ans += (long long)pi[i] * v;
      i++;
    }
    pind.clear();
    for (auto v : st[2])
      pind.push_back(v);
    for (auto v : st[3]) {
      pind.push_back(v);
      pind.push_back(v);
    }
    sort(pind.begin(), pind.end());
    cnt = 1, i;
    for (i = 1; i < pind.size(); ++i) {
      if (pind[i] != pind[i - 1]) {
	s.insert(cnt);
	cnt = 1;
      }
      else
	cnt++;
    }
    s.insert(cnt);
    i = 0;
    long long temp = 0;
    while (s.size()) {
      auto it = s.end();
      it--;
      int v = *it;
      s.erase(it);
      temp += (long long)pi[i] * v;
      i++;
    }
    ans = min(ans, temp);

    pind.clear();
    for (auto v : st[2]) {
      pind.push_back(v);
      pind.push_back(v);
    }
    for (auto v : st[3])
      pind.push_back(v);
    for (auto v : st[1])
      pind.push_back(v);
    sort(pind.begin(), pind.end());
    cnt = 1, i;
    for (i = 1; i < pind.size(); ++i) {
      if (pind[i] != pind[i - 1]) {
	s.insert(cnt);
	cnt = 1;
      }
      else
	cnt++;
    }
    s.insert(cnt);
    i = 0;
    temp = 0;
    while (s.size()) {
      auto it = s.end();
      it--;
      int v = *it;
      s.erase(it);
      temp += (long long)pi[i] * v;
      i++;
    }
    ans = min(ans, temp);

    pind.clear();
    for (auto v : st[1]) {
      pind.push_back(v);
      pind.push_back(v);
    }
    for (auto v : st[2])
      pind.push_back(v);
    sort(pind.begin(), pind.end());
    cnt = 1, i;
    for (i = 1; i < pind.size(); ++i) {
      if (pind[i] != pind[i - 1]) {
	s.insert(cnt);
	cnt = 1;
      }
      else
	cnt++;
    }
    s.insert(cnt);
    i = 0;
    temp = 0;
    while (s.size()) {
      auto it = s.end();
      it--;
      int v = *it;
      s.erase(it);
      temp += (long long)pi[i] * v;
      i++;
    }
    ans = min(ans, temp);
    printf("%lld\n", ans);
  }
  return 0;
}
