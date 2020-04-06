#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

struct Vertex {
  int next[2];
  Vertex() {
    fill(next, next + 2, -1);
  }
};

vector <Vertex> trie;

void insert(int num) {
  int v = 0;
  for (int j = 31; j >= 0; j--) {
    int bit = ((1 << j) & num) ? 1 : 0;
    if (trie[v].next[bit] == -1) {
      trie[v].next[bit] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].next[bit];
  }
}

int dfs(int u, int num, int j) {
  if (j < 0)
    return 0;
  int bit = ((1 << j) & num) ? 1 : 0, ans;
  if (trie[u].next[1 - bit] != -1) {
    ans = 1 << j;
    ans = ans | dfs(trie[u].next[1 - bit], num, j - 1);
  }
  else
    ans = dfs(trie[u].next[bit], num, j - 1);
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, xo = 0, ans = 0;
    scanf("%d", &n);
    trie.clear();
    trie.emplace_back();
    insert(0);
    for (int i = 0; i < n; ++i) {
      int num;
      scanf("%d", &num);
      xo ^= num;
      insert(xo);
      ans = max(ans, dfs(0, xo, 31));
    }
    printf("%d\n", ans);
  }
  return 0;
}
