#include <iostream>
#include <cstring>

using namespace std;

const int N = 205, inf = 1e9;
int dist[N][N], B[10005], mat[N][N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, m, l;
    scanf("%d%d%d", &n, &m, &l);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
	dist[i][j] = mat[i][j] = inf;
    for (int i = 0; i < n; ++i)
      dist[i][i] = 0;
    for (int i = 0; i < l; ++i)
      scanf("%d", B + i);
    for (int i = 0 ; i < m; ++i) {
      int u, v, d;
      scanf("%d%d%d", &u, &v, &d);
      u--, v--;
      mat[u][v] = dist[u][v] = d;
      mat[v][u] = dist[v][u] = d;
    }

    for (int k = 0; k < n; ++k)
      for (int i = 0; i < n; ++i)
	for (int j = 0; j < n; ++j)
	  if (dist[i][k] < inf && dist[k][j] < inf)
	  dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

    int ans = 2, prev = 0, cur = 0;
    for (int i = 1; i < l; ++i) {
      cur += mat[B[i - 1] - 1][B[i] - 1];
      //cout<<dist[B[prev] - 1][B[i] - 1]<<" "<<cur<<" "<<prev<<" "<<i<<endl;;
      if (dist[B[prev] - 1][B[i] - 1] < cur) {
	if (prev == i - 1) {
	  ans = -1;
	  break;
	}
	ans++;
	prev = i - 1;
	cur = mat[B[prev] - 1][B[i] - 1];
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
