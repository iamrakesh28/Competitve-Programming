#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int K = 26;

struct Vertex {
  int next[K];
  int cnt = 0;
  bool leaf = false;
  Vertex() {
    fill(next, next + K, -1);
  }
};

vector <Vertex> trie;
int ans;

void add_string(string const& s) {
  int v = 0;
  trie[v].cnt++;
  for (char ch : s) {
    int c = ch - 'A';
    if (trie[v].next[c] == -1) {
      trie[v].next[c] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].next[c];
    trie[v].cnt++;
  }
  trie[v].leaf = true;
}

int dfs(int u) {

  int tot = trie[u].cnt;
  for (int v : trie[u].next)
    if (v != -1)
      tot -= dfs(v);
  if (u && tot >= 2)
    ans += 2, tot -= 2;
  return trie[u].cnt - tot;
}

int main() {
  
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q;
  cin>>q;
  for (int i = 0; i < q; ++i) {
    int n;
    cin>>n;
    trie.clear();
    trie.emplace_back();
    for (int j = 0; j < n; ++j) {
      string s;
      cin>>s;
      reverse(s.begin(), s.end());
      add_string(s);
    }
    ans = 0;
    int dump = dfs(0);
    cout<<"Case #"<<i + 1<<": "<<ans<<"\n";
  }
  return 0;
}
