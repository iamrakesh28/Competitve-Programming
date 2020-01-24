#include <iostream>
#include <list>

using namespace std;

const int N = 2e3 + 5;
list <int> adj[N];
list <pair <int, int>> ans;
int c[N], a[N];

bool dfs(int u, int p, int cnt) {
  bool poss = true;
  for (auto it : adj[u]) {
    if (it != p) {
      if (dfs(it, u, ans.size()) == false)
	return false;
    }
  }

  if (c[u] > ans.size() - cnt)
    poss = false;
  else {
    bool ins = false;
    auto it = ans.begin();
    advance(it, cnt + c[u]);
    ans.insert(it, {c[u] + cnt + 1, u});
    it = ans.begin();
    //cout<<u+1<<" "<<c[u]<<" "<<ans.size()<<" "<<(*it).first<<endl;
    advance(it, c[u] + cnt + 1);
    while (it != ans.end()) {
      (*it).first = (*it).first + 1;
      it++;
    }
    //cout<<u+1<<": ";
    //for (auto it : ans)
    //cout<<it.first<<" "<<it.second<<", ";
    //puts("");
  }
  return poss;
}

int main() {

  int n, root;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int p;
    scanf("%d%d", &p, c + i);
    if (p) {
      adj[i].push_back(p - 1);
      adj[p - 1].push_back(i);
    }
    else
      root = i;
  }

  if (dfs(root, root, 0)) {
    puts("YES");
    for (auto it : ans)
      a[it.second] = it.first;
    for (int i = 0; i < n; ++i)
      printf("%d ", a[i]);
    puts("");
  }
  else
    puts("NO");
  return 0;
}
