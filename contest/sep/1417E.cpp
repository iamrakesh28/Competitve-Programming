#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

const int N = 4e6 + 100;
vector <int> g[N];
int trie[N][2], id;
ll sum[31][2];

void add(int ai, int pos) {
  int v = 0;
  for (int i = 30; i >= 0; i--) {
    int bit = ai & (1 << i);
    if (bit)
      bit = 1;
    if (trie[v][bit] == 0) {
      trie[v][bit] = ++id;
      //cout << bit << " " << ai << "++\n";
    }
    v = trie[v][bit];
    g[v].push_back(pos);
    //cout << v << " " << ai << endl;
  }
}

void go(int v, int k = 30) {
  int l = trie[v][0], r = trie[v][1];
  if (l)
    go(l, k - 1);
  if (r)
    go(r, k - 1);
  if (!l && !r)
    return;
  int next = 0;
  ll inv = 0;
  for (int x : g[l]) {
    while (next < g[r].size() && g[r][next] < x)
      next++;
    inv += next;
  }
  sum[k][0] += inv;
  next = 0, inv = 0;
  // can be done using the above loop only
  // currently, as ai can be equal to aj
  // i don't know how to do it
  for (int x : g[r]) {
    while (next < g[l].size() && g[l][next] < x)
      next++;
    inv += next;
  }
  sum[k][1] += inv;
}

int main() {

  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int ai;
    cin >> ai;
    add(ai, i);
  }
  go(0);
  int x = 0;
  ll inv = 0;
  for (int i = 30; i >= 0; i--) {
    //cout << sum[i][0] << " " << sum[i][1] << endl;
    if (sum[i][0] > sum[i][1]) {
      x = x | (1 << i);
      inv += sum[i][1];
    }
    else
      inv += sum[i][0];
  }
  cout << inv << " " << x << endl;
  return 0;
}
