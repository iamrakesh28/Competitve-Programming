#include <iostream>

using namespace std;

const int N = 1000;
int mat[N][N];

void print(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j)
      printf("%5d ", mat[i][j]);
    puts("");
  }
}

bool check(int i, int j, int n, int v) {
  bool poss = true;
  for (int c = 0; c < n; c++)
    if (mat[j][c] == v) {
      poss = false;
      break;
    }
  for (int r = 0; r < n; ++r)
    if (mat[r][j] == v) {
      poss = false;
      break;
    }

  for (int c = 0; c < n; c++)
    if (mat[i][c] == v) {
      poss = false;
      break;
    }
  for (int r = 0; r < n; ++r)
    if (mat[r][i] == v) {
      poss = false;
      break;
    }
  
  return poss;
}

bool brute(int i, int j, int n) {
  if (i >= n) {
    print(n);
    return true;
  }
  if (j >= n)
    return brute(i + 1, 0, n);

  for (int v = 1; v < 2 * n; ++v) {
    if (check(i, j, n, v) == false)
      continue;
    mat[i][j] = v;
    if (brute(i, j + 1, n) == true)
      return true;
  }
  return false;
}

int main () {
  int n;
  scanf("%d", &n);
  bool ans = brute(0, 0, n);
  return 0;
}
