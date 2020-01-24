#include <iostream>
#include <list>
#include <cmath>

#define debug

using namespace std;

const int N = 5e5;

bool leaf[N];
int arr[2 * N], up[2 * N][20], l;
list <int> adj[2 * N];
pair <int, int> ans[N];
long long sum[2 * N][20];

void dfs1(int u, int p) {
 
  sum[u][0] = arr[u];
  for (int i = 1; i <= l; ++i)
    sum[u][i] = sum[u][i - 1] + sum[up[u][i - 1]][i - 1];
  for (int v : adj[u])
    if (v != p)
      dfs1(v, u);
}

void dfs2(int u, int p) {
  up[u][0] = p;
  leaf[u] = true;
  for (int i = 1; i <= l; ++i)
    up[u][i] = up[up[u][i - 1]][i - 1];
  for (int v : adj[u])
    if (v != p) {
      leaf[u] = false;
      dfs2(v, u);
    }
}

long long nsum(int u, int h) {
  long long s = 0;
  int len = 0;
  for (int i = l; i >= 0; i--)
    if (len + (1 << i) <= h) {
      len = len + (1 << i);
      s += sum[u][i];
      u = up[u][i];
    }
  return s;
}

int node(int u, int h) {
  int len = 0;
  for (int i = l; i >= 0; i--)
    if (len + (1 << i) <= h) {
      len = len + (1 << i);
      u = up[u][i];
    }
  return u;
}

int main() {

  #ifdef debug
    freopen("test", "r", stdin);
  #endif
  int n, q, update = 0, query = 0;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u - 1].push_back(v - 1);
    adj[v - 1].push_back(u - 1);
  }
  for (int i = 0; i < n; ++i)
    scanf("%d", arr + i);
  char ch = getchar_unlocked();
  int k, v;
  for (int i = 0; i < q - 1; ++i) {
    adj[n + i].push_back(n + i + 1);
    adj[n + i + 1].push_back(n + i);
  }
  // new root -> n
  
  adj[n + q - 1].push_back(0);
  adj[0].push_back(n + q - 1);
  l = ceil(log2(n + q));
  dfs2(n, n);
  int height;
  for (int i = 0; i < q; ++i) {
    ch = getchar_unlocked();
    //cout<<ch<<endl;
    if (ch == '+') {
      update++;
      scanf("%d%d", &v, &k);
      height = node(v - 1, i + 1);
      arr[height] += k;
    }
    else {
      scanf("%d", &v);
      ans[query++] = {v - 1, i};
    }
    ch = getchar_unlocked();  
  }
  dfs1(n, n);
  for (int i = 0; i < query; ++i) {
    
    if (leaf[ans[i].first] == true) {
      long long a = nsum(ans[i].first, ans[i].second + 1);
      printf("leaf: %lld\n", a);
    }
    else {
      int a = node(ans[i].first, ans[i].second + 1);
      printf("%d\n", arr[a]);
    }
  }
  return 0;
}
