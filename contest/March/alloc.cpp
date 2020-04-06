#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int A[N];

int main() {
  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; ++i) {
    int n, b;
    scanf("%d%d", &n, &b);
    for (int j = 0; j < n; ++j)
      scanf("%d", A + j);
    sort(A, A + n);
    int ans = 0;
    for (int j = 0; j < n; ++j) {
      b -= A[j];
      if (b >= 0)
	ans++;
      else
	break;
    }
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
