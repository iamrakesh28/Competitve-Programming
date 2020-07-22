#include <iostream>

using namespace std;

const int N = 2e5 + 5;
int A[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n, k;
    scanf("%d%d", &n, &k);
    for (int j = 0; j < n; ++j)
      scanf("%d", A + j);
    int ans = 0;
    int j = 0, c;
    while (j <= n - k) {
      for (c = 0; c < k; ++c) {
	if (A[j + c] != k - c)
	  break;
      }
      if (c == k)
	ans++;
      if (c)
	j += c;
      else
	j++;
    }
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
