#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e6 + 5, inf = 1e9;
int arr[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k, cnt = 0;
    scanf("%d%d", &n, &k);
    memset(arr, 0, sizeof(int) * n);
    for (int i = 0; i < n; ++i) {
      char c;
      scanf(" %c", &c);
      if (c == '0')
	continue;
      cnt++;
      int x = n - i - 1;
      x = x / k;
      if (i + x * k < n - 1)
	x++;
      arr[i + x * k - n + 1]++;
    }
    int ans = inf;
    for (int i = 0; i < k; ++i) {
      int temp = cnt - arr[i];
      ans = min(ans, temp);
    }
    printf("%d\n", ans);
  }
  return 0;
}
