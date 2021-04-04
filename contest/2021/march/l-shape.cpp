#include <iostream>

using namespace std;
using LL = long long;

const int N = 1005;
int grid[N][N], _left[N][N], _right[N][N],
  up[N][N], down[N][N];

void precompute(int r, int c) {

  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (j == 0) {
        _left[i][j] = grid[i][j];
      }
      else {
        if (grid[i][j] == 1)
          _left[i][j] = _left[i][j - 1] + 1;
        else
          _left[i][j] = 0;
      }
    }
  }

  for (int i = 0; i < r; ++i) {
    for (int j = c - 1; j >= 0; --j) {
      if (j == c - 1) {
        _right[i][j] = grid[i][j];
      }
      else {
        if (grid[i][j] == 1)
          _right[i][j] = _right[i][j + 1] + 1;
        else
          _right[i][j] = 0;
      }
    }
  }

  for (int j = 0; j < c; ++j) {
    for (int i = r - 1; i >= 0; i--) {
      if (i == r - 1) {
        down[i][j] = grid[i][j];
      }
      else {
        if (grid[i][j] == 1)
          down[i][j] = down[i + 1][j] + 1;
        else
          down[i][j] = 0;
      }
    }
  }

  for (int j = 0; j < c; ++j) {
    for (int i = 0; i < r; i++) {
      if (i == 0) {
        up[i][j] = grid[i][j];
      }
      else {
        if (grid[i][j] == 1)
          up[i][j] = up[i - 1][j] + 1;
        else
          up[i][j] = 0;
      }
    }
  }

  return;
}

int l_shapes(int l1, int l2) {

  int cnt = 0;
  if (min(l1, l2) >= 2) {
    int high = l2 >> 1;
    int low = min(high, l1);
    cnt = cnt + low - 1;
    
    high = l1 >> 1;
    low = min(high, l2);
    cnt = cnt + low - 1;
  }

  return cnt;
}

LL solve(int r, int c) {

  LL cnt = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      int l1 = _left[i][j], l2 = down[i][j];
      cnt += l_shapes(l1, l2);

      l2 = up[i][j];
      cnt += l_shapes(l1, l2);

      l1 = down[i][j], l2 = _right[i][j];
      cnt += l_shapes(l1, l2);

      l1 = _right[i][j], l2 = up[i][j];
      cnt += l_shapes(l1, l2);
    }
  }
  
  return cnt;
}

int main() {

  int t;
  scanf("%d", &t);

  for (int q = 0; q < t; ++q) {
    int r, c;
    scanf("%d%d", &r, &c);

    for (int i = 0; i < r; ++i)
      for (int j = 0; j < c; ++j)
        scanf("%d", grid[i] + j);

    precompute(r, c);
    //cout << _left[3][0] << " " << _right[3][0] << " " << up[3][0] << " "
    //     << down[3][0] << endl;
    printf("Case #%d: %lld\n", q + 1, solve(r, c));
  }
  
  return 0;
}
