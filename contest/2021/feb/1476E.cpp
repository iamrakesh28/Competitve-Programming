#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

map <string, int> patterns;
vector <vector <int>> adj;
stack <int> order;
bool cycle = false;
vector <int> visit;

void dfs(int u) {

  visit[u] = 1;
  if (cycle)
    return;

  for (int v : adj[u]) {
    if (visit[v] == 0)
      dfs(v);
    else if (visit[v] == 1)
      cycle = true;
  }

  visit[u] = 2;
  order.push(u);
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n, m, k;
  cin >> n >> m >> k;

  visit.resize(n);
  adj.resize(n);

  for (int i = 0; i < n; ++i) {
    string pattern;
    cin >> pattern;
    patterns.insert({pattern, i});
    visit[i] = 0;
  }

  bool poss = true;
  for (int i = 0; i < m; ++i) {
    string str;
    int mt;
    cin >> str >> mt;
    mt--;

    bool found = false;
    for (int j = 0; j < (1 << k); ++j) {
      string pattern = str;
      for (int bit = 0; bit < k; ++bit) {
        if (j & (1 << bit))
          pattern[bit] = '_';
      }

      auto patt_iter = patterns.find(pattern);
      if (patt_iter == patterns.end())
        continue;

      if (mt != patt_iter -> second) {
        adj[mt].push_back(patt_iter -> second);
        // cout << mt + 1 << " " << patt_iter -> second + 1 << "\n";
      }
      else
        found = true;
    }
    
    if (found == false) {
      poss = false;
      break;
    }
  }

  if (poss == false) {
    cout << "NO\n";
    return 0;
  }

  for (int i = 0; i < n; ++i) {
    if (visit[i] == 0)
      dfs(i);
  }

  if (cycle) {
    cout << "NO\n";
    return 0;
  }

  cout << "YES\n";

  while (order.size()) {
    cout << order.top() + 1 << " ";
    order.pop();
  }
  
  return 0;
}
