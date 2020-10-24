#include <iostream>
#include <cstring>

using namespace std;

const int N = 65, inf = 1e9;
int dp[N][N][N];
char C[N], J[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int h = 0; h < t; ++h) {
    int c, cj, len;
    scanf("%s%s", C, J);
    c = strlen(C), cj = strlen(J);
    len = max(c, cj);
    for (int i = 0; i <= len; ++i)
      for (int j = 0; j <= c; ++j)
	for (int k = 0; k <= cj; ++k) {
	  if (i == 0) {
	    dp[i][j][k] = i || j ? inf : 0;
	    continue;
	  }
	  if (C[j - 1] == C[k - 1]) {
	    // same character
	    dp[i][j][k] = dp[i - 1][j - 1][k - 1];
	  }
	  else {
	    // first same
	    dp[i][j][k] = dp[i - 1][][] + 1;
	  }
	}
  }
  return 0;
}
