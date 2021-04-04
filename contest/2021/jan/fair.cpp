#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

  int t;
  scanf("%d", &t);

  vector <int> A, B;

  while (t--) {
    int n, m, ans = 0, sumA = 0, sumB = 0;
    scanf("%d%d", &n, &m);

    A.resize(n), B.resize(m);
    for (int i = 0; i < n; ++i) {
      int ai;
      scanf("%d", &ai);
      sumA += ai;
      A[i] = ai;
    }

    for (int i = 0; i < m; ++i) {
      int bi;
      scanf("%d", &bi);
      sumB += bi;
      B[i] = bi;
    }

    if (sumA > sumB) {
      puts("0");
      continue;
    }

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int i = 0, j = m - 1;

    while (i < n && j >= 0 && sumA <= sumB) {
      if (A[i] < B[j]) {
        sumA += (B[j] - A[i]);
        sumB += (A[i] - B[j]);
      }
      else
        break;
      i++, j--;
      ans++;
    }

    if (sumA <= sumB)
      puts("-1");
    else
      printf("%d\n", ans);
  }
  
  return 0;
}
