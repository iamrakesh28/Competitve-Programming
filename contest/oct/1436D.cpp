#include <iostream>
#include <list>

using namespace std;

typedef long long ll;

const int N = 2e5 + 5;
ll mx[N], tot[N], a[N];
int lcnt[N];
list <int> adj[N];

void dfs(int u, int p) {

  mx[u] = a[u];
  lcnt[u] = 1;
  tot[u] = a[u];


  ll maxai = -1, cntai = 0;
  int cntleaf = 0;
  
  for (int v : adj[u])
    if (v != p) {
      dfs(v, u);
      cntleaf += lcnt[v];
      cntai += tot[v];
      maxai = max(maxai, mx[v]);
    }

  if (maxai < 0)
    return;

  mx[u] = maxai;
  lcnt[u] = cntleaf;
  tot[u] = a[u] + cntai;
  
  cntleaf--;
  cntai -= maxai;
  ll temp = cntleaf * maxai - cntai;
  //cout << temp << " " << cntai << endl;
  if (temp >= a[u] )
    return;

  ll au = a[u];
  au -= temp;
  
  cntleaf++;
  temp = au / cntleaf;
  
  if (au % cntleaf)
    temp++;
  mx[u] += temp;
  
  return;
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n - 1; ++i) {
    int pi;
    scanf("%d", &pi);
    adj[i + 1].push_back(pi - 1);
    adj[pi - 1].push_back(i + 1);
  }
  for (int i = 0; i < n; ++i)
    scanf("%lld", a + i);

  dfs(0, 0);
  
  printf("%lld\n", mx[0]);
  return 0;
}
