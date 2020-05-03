#include <iostream>
#include <algorithm>

typedef long long ll;
using namespace std;

const int N = 1e5 + 5;
int A[N];

int main() {
  int n, ans = -1;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d", A + i);
  sort(A, A + n);
  ll sum = 0, cr = 10000000;
  for (int i = 0; i < n; ++i) {
    sum += A[i];
    if (sum >= cr) {
      ans = i + 1;
      break;
    }
  }
  printf("%d\n", ans);
  return 0;
}
