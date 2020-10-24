#include <iostream>

using namespace std;
const int N = 2e5 + 5;
int A[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int h = 0; h < t; ++h) {
    int n, ans = 2;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      scanf("%d", A + i);
    int ind = 1, cnt = 2, diff = A[0] - A[1];
    while (ind < n - 1) {
      if (A[ind] - A[ind + 1] == diff) {
	ind ++;
	cnt ++;
      }
      else {
	ans = max(ans, cnt);
	cnt = 2;
	diff = A[ind] - A[ind + 1];
	ind ++;
      }
    }
    ans = max(ans, cnt);
    printf("Case #%d: %d\n", h + 1, ans);
  }
  return 0;
}
