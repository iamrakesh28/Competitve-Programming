#include <iostream>
#include <vector>

using namespace std;

const int N = 1e5;

struct Vertex {
  int next[2];
  int cnt = 0;
  Vertex() {
    fill(next, next + 2, -1);
  }
};

vector <Vertex> trie;

void insert(int num) {
  int v = 0;
  trie[v].cnt++;
  for (int j = 31; j >= 0; j--) {
    int bit = ((1 << j) & num) ? 1 : 0;
    if (trie[v].next[bit] == -1) {
      trie[v].next[bit] = trie.size();
      trie.emplace_back();
    }
    v = trie[v].next[bit];
    trie[v].cnt++;
  }
}

int dfs(int u, int num, int k, int j) {
  if (j < 0)
    return 0;
  int bitn = ((1 << j) & num) ? 1 : 0;
  int bitk = ((1 << j) & k) ? 1 : 0, ans = 0;
  if (bitk == 0) {
    if (trie[u].next[bitn] != -1)
      ans = dfs(trie[u].next[bitn], num, k, j - 1);
  }
  else {
    int nxt = trie[u].next[bitn];
    if (nxt != -1)
      ans = trie[nxt].cnt;
    if (trie[u].next[1 - bitn] != -1)
      ans += dfs(trie[u].next[1 - bitn], num, k, j - 1);
  }
  return ans;
}

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, k, xo = 0;
    long long ans = 0;
    scanf("%d%d", &n, &k);
    trie.clear();
    trie.emplace_back();
    insert(0);
    for (int i = 0; i < n; ++i) {
      int num;
      scanf("%d", &num);
      xo ^= num;
      ans += dfs(0, xo, k, 31);
      insert(xo);
      //cout<<ans<<" "<<i+1<<endl;
    }
    printf("%lld\n", ans);
  }
  return 0;
}
