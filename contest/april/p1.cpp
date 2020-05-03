#include <iostream>

using namespace std;

const int N = 105;
int h[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d", &n);
    for (int j = 0; j < n; ++j)
      scanf("%d", h + j);
    int ans = 0;
    for (int j = 1; j < n - 1; ++j) {
      if (h[j] > h[j - 1] && h[j] > h[j + 1])
	ans++;
    }
    printf("Case #%d: %d\n", i + 1, ans);
  }
  return 0;
}
