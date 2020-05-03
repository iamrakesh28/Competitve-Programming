#include <iostream>

using namespace std;

const int N = 1e6 + 5;
char S[N];
int A[N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, ans;
    scanf("%d%s", &n, S);
    A[0] = 0;
    for (int i = 0; i < n; ++i) {
      if (S[i] == 'A')
	A[i + 1] = A[i] + 1;
      else
	A[i + 1] = A[i];
    }
    ans = A[n];
    for (int i = 0; i < n; ++i) {
      int temp = i + 1 - A[i + 1] + A[n] - A[i + 1];
      ans = min(temp, ans);
    }
    printf("%d\n", ans);
  }
  return 0;
}
