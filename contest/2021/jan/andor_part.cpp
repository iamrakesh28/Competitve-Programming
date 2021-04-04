#include <iostream>
#include <cstring>

using namespace std;

const int N = 1 << 20;
bool visit[N];
int A[N], B[N], n, m;

void dfs(int u) {

  visit[u] = true;
  for (int i = 0; i < n; ++i) {
    if (visit[u | A[i]] == false)
      dfs(u | A[i]);
  }

  for (int i = 0; i < m; ++i) {
    if (visit[u & B[i]] == false)
      dfs(u & B[i]);
  }
  
  return;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {

    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; ++i)
      scanf("%d", A + i);

    for (int i = 0; i < m; ++i)
      scanf("%d", B + i);

    memset(visit, false, sizeof visit);
    dfs(0);
    
    int cnt = 0;
    for (int i = 0; i < N; ++i)
      if (visit[i])
        cnt ++;

    printf("%d\n", cnt);
  }
  
  return 0;
}
