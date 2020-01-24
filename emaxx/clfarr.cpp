#include <iostream>

using namespace std;

struct Query {
  int l, r, c;
};

const int N = 2e5 + 1;
Query query[N];
int parent[N], color[N];

int find(int u) {
  if (u == parent[u])
    return u;
  parent[u] = find(parent[u]);
  return parent[u];
}

int main() {

  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i <= n; ++i)
    parent[i] = i;
  for (int i = 0; i < q; ++i)
    scanf("%d%d%d", &query[i].l, &query[i].r, &query[i].c);
  
  for (int i = q - 1; i >= 0; i--) {
    int l, r, c;
    l = query[i].l - 1;
    r = query[i].r - 1;
    c = query[i].c;
    for (int j = find(l); j <= r; j = find(j)) {
      color[j] = c;
      parent[j] = j + 1;
    }
  }
  for (int i = 0; i < n; ++i)
    printf("%d\n", color[i]);
  return 0;
}
