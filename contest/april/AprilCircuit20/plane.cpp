#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> A, B, ind;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  A.resize(n);
  B.resize(m);
  ind.resize(n);
  for (int i = 0; i < n; ++i)
    scanf("%d", &A[i]);
  for (int i = 0; i < m; ++i)
    scanf("%d", &B[i]);
  sort(A.begin(), A.end());
  sort(B.begin(), B.end());
  if (A[n - 1] > B[m - 1]) {
    puts("-1");
    return 0;
  }
  for (int i = 0; i < n; ++i) {
    auto it = lower_bound(B.begin(), B.end(), A[i]);
    ind[i] = it - B.begin();
  }
  int ans = 1, cur = 0, id = ind[cur], val = 1;
  while (cur < n) {
    id = max(id, ind[cur]);
    if (id >= m) {
      val++;
      id = -1;
      continue;
    }
    id++;
    ans = 2 * val - 1;
    cur++;
  }
  printf("%d\n", ans);
  return 0;
}
