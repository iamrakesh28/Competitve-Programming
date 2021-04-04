#include <iostream>
#include <list>
#include <queue>

using namespace std;

const int N = 205;
char s[N], color[N];
list <int> adj[N];
bool visit[N];

bool bipartite(int s, int n) {

  queue <int> q;
  q.push(s);

  visit[s] = true;
  color[s] = '0';

  while (q.size()) {
    int u = q.front();
    q.pop();

    for (int v : adj[u]) {
      if (visit[v]) {
        if (color[v] == color[u])
          return false;
      }
      else {
        visit[v] = true;
        color[v] = '1' - color[u] + '0';
        q.push(v);
      }
    }
  }
  
  return true;
}

int main() {

  int n;
  scanf("%d%s", &n, s);

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < i; ++j) {
      if (s[j] > s[i]) {
        adj[i].push_back(j);
        adj[j].push_back(i);
        // cout << j + 1 << " " << i + 1 << endl;
      }
    }
  }

  for (int i = 0; i < n; ++i)
    visit[i] = false;
  
  bool sol = true;
  for (int i = 0; i < n; ++i) {
    if (visit[i] == false) {
      bool bip = bipartite(i, n);
      if (bip == false) {
        sol = false;
        break;
      }
    }
  }

  if (sol) {
    for (int i = 0; i < n; ++i) {
      if (visit[i] == false) {
        color[i] = '0';
      }
    }
    color[n] = '\0';
  }
  
  if (sol == false) {
    puts("NO");
  }
  else {
    puts("YES");
    puts(color);
  }
  return 0;
}
