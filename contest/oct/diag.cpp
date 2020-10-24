#include <iostream>

using namespace std;

const int N = 1e3 + 5;

int mat[N][N];

int main() {
  int t;
  scanf("%d", &t);
  for (int q = 0; q < t; ++q) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
	scanf("%d", mat[i] + j);
    long long ans = 0, temp;
    for (int i = 0; i < n; ++i) {
      temp = 0;
      for (int j = 0; i + j < n; ++j)
	temp += mat[i + j][j];
      ans = max(ans, temp);
    }

    for (int j = 1; j < n; ++j) {
      temp = 0;
      for (int i = 0; i + j < n; ++i)
	temp += mat[i][i + j];
      ans = max(ans, temp);
    }
    printf("Case #%d: %lld\n", q + 1, ans);
  }
  return 0;
}
