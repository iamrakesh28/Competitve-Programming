#include <iostream>

using namespace std;

int mat[3][3];

int main() {
  int k, n, m, bit = -1;
  scanf("%d", &k);
  n = m = 3;
  for (int i = 31; i >= 0; --i) {
    if (k & (1 << i)) {
      bit = i;
      break;
    }
  }
  bit++;
  int a = (1 << bit) | k;
  mat[0][0] = mat[1][2] = a;
  mat[0][1] = mat[0][2] = mat[2][2] = k;
  mat[1][0] = mat[1][1] = mat[2][0] = mat[2][1] = 1 << bit;
  puts("3 3");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j)
      printf("%d ", mat[i][j]);
    puts("");
  }
}
