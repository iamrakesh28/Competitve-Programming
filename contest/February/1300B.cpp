#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
int A[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; ++i)
      scanf("%d", A + i);
    sort(A, A + 2 * n);
    int ans = A[n] - A[n - 1];
    printf("%d\n", ans);
  }
}
