#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5 + 5, K = 26;

struct Vertex {
  int next[K];
  bool leaf = false;
  Vertex() {
    fill(next, next + K, -1);
  }
};

vector <Vertex> trie;
int dp[N][2];

void insert(string const& s) {
  int v = 0;
  for (char c : s) {
    int ch = c - 'a';
    if (trie[v].next[ch] == -1) {
      trie[v].next[ch] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].next[ch];
  }
  trie[v].leaf = true;
}

void dfs(int u) {
  dp[u][0] = false;
  if (trie[u].leaf)
    dp[u][1] = true;
  else
    dp[u][1] = false;
  for (int v : trie[u].next) {
    if (v != -1) {
      dfs(v);
      dp[u][0] = dp[u][0] || (!dp[v][0]);
      dp[u][1] = dp[u][1] || (!dp[v][1]);
    }
  }
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin>>n>>k;
  trie.clear();
  trie.emplace_back();
  for (int i = 0; i < n; ++i) {
    string s;
    cin>>s;
    insert(s);
  }
  dfs(0);
  k--;
  if (dp[0][0]) {
    if (dp[0][1] == false) {
      if (k & 1)
	puts("Second");
      else
	puts("First");
    }
    else
      puts("First");
  }
  else
    puts("Second");
  return 0;
}
