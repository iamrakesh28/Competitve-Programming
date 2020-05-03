#include <iostream>

using namespace std;

const int N = 1e4 + 5;
int dp[105][N];

bool solve(int i, int j) {
  if (i == 0 && j == 0)
    return 1;
  if (dp[i][j] == -1) {
    if (i == 0) {
      if (B[j] == '*') {
	ans[j] = '*';
	dp[i][j] = solve(i, j - 1);
      }
      dp[i][j] = 0;
    }
    else if (j == 0)
      dp[i][j] = 0;
    else {
      if (B[j] == '*') {
	dp[i][j] = solve(i - 1, j - 1);
      }
      else {
	
      }
    }
  }
}

int main() {
}
