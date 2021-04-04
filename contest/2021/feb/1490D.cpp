#include <iostream>

using namespace std;

const int N = 105;

int dv[N], p[N];

int find_max(int l, int r) {

  int val = -1, id;
  for (int i = l; i <= r; ++i) {
    if (p[i] > val) {
      val = p[i];
      id = i;
    }
  }

  return id;
}

void dfs(int l, int r, int d) {
  if (l > r)
    return;

  if (l == r) {
    dv[l] = d;
    return;
  }

  int elem = find_max(l, r);
  dfs(l, elem - 1, d + 1);
  dfs(elem + 1, r, d + 1);

  dv[elem] = d;
  return;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
      scanf("%d", p + i);

    dfs(0, n - 1, 0);

    for (int i = 0; i < n; ++i)
      printf("%d ", dv[i]);
    puts("");
  }
  
  return 0;
}
