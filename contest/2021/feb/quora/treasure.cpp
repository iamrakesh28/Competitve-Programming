#include <iostream>

using namespace std;

const int N = 1e3 + 5, prime = 1e9 + 7;
char grid[N][N];
int dp[N][N], ways[N][N];

int main() {

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", grid[i]);

  dp[0][0] = grid[0][0] - '0';
  ways[0][0] = 1;
  for (int i = 1; i < n; ++i) {
    dp[0][i] = dp[0][i - 1] + grid[0][i] - '0';
    ways[0][i] = 1;
  }

  for (int i = 1; i < n; ++i) {
    dp[i][0] = dp[i - 1][0] + grid[i][0] - '0';
    ways[i][0] = 1;
  }
  
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j < n; ++j) {
      int ch = grid[i][j] - '0';
      if (dp[i][j - 1] > dp[i - 1][j]) {
        dp[i][j] = dp[i][j - 1] + ch;
        ways[i][j] = ways[i][j - 1];
      }
      else if (dp[i][j - 1] < dp[i - 1][j]) {
        dp[i][j] = dp[i - 1][j] + ch;
        ways[i][j] = ways[i - 1][j];
      }
      else {
        dp[i][j] = dp[i - 1][j] + ch;
        ways[i][j] = (ways[i - 1][j] + ways[i][j - 1]) % prime;
      }
    }
  }

  printf("%d %d\n", dp[n - 1][n - 1], ways[n - 1][n - 1]);
  return 0;
}
