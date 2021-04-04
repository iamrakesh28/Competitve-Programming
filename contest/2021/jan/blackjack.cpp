#include <iostream>

using namespace std;

const int N = 1e3 + 5, ST_MAX = 12, INF = 1e9;
int A[N], _log[N], dp_left[N][N],
  dp_right[N][N], st[N][N][ST_MAX];

void preprocess(int n, int y) {

  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= y ; ++j) {
      if (i == 0) {
        dp_left[i][j] = (j == 0 ? 0 : INF);
        continue;
      }
      
      dp_left[i][j] = dp_left[i - 1][j];
      if (j >= A[i - 1]) {
        dp_left[i][j] = min(dp_left[i][j], dp_left[i - 1][j - A[i - 1]] + 1);
      }
    }
  }

  for (int i = n; i >= 0; --i) {
    for (int j = 0; j <= y ; ++j) {
      if (i == n) {
        dp_right[i][j] = (j == 0 ? 0 : INF);
        continue;
      }
      
      dp_right[i][j] = dp_right[i + 1][j];
      if (j >= A[i]) {
        dp_right[i][j] = min(dp_right[i][j], dp_right[i + 1][j - A[i]] + 1);
      }
    }
  }

  return;
}

int solve(int n, int x, int y) {

  _log[1] = 0;
  for (int i = 2; i < N; ++i)
    _log[i] = _log[i >> 1] + 1;
  
  // builds the sparse table
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= y; ++j) {
      st[i][j][0] = dp_right[i][j];
    }

    for (int j = 1; j <= ST_MAX; ++j) {
      for (int k = 0; k + (1 << j) <= y + 1; ++k) {
        st[i][k][j] = min(st[i][k][j - 1], st[i][k + (1 << (j - 1))][j - 1]);
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= y; ++j) {

      int l = max(x, j) - j, r = y - j, power;
      power = _log[r - l + 1];
      
      int right_min = min(st[i + 1][l][power], st[i + 1][r - (1 << power) + 1][power]);

      if (dp_left[i + 1][j] >= INF || right_min >= INF)
        continue;
      int val = max(i + 1 - dp_left[i + 1][j], right_min);
      // cout << i + 1 << " " << j << " " << k << " " << val << endl;
      ans = min(ans, val);
      
    }
  }

  if (ans >= INF)
    ans = -1;
  
  return ans;
}

int main() {

  int t;
  scanf("%d", &t);

  while (t--) {
    int n, x, y;
    scanf("%d%d%d", &n, &x, &y);

    for (int i = 0; i < n; ++i)
      scanf("%d", A + i);

    preprocess(n, y);
    int ans = solve(n, x, y);

    printf("%d\n", ans);
  }
  
  return 0;
}
