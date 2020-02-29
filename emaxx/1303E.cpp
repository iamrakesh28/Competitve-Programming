#include <iostream>
#include <cstring>

using namespace std;

const int N = 405;
char s[N], t[N];
bool dp[N][N][N];

int main() {
  int q;
  scanf("%d", &q);
  while (q--) {
    int S, T;
    scanf("%s%s", s, t);
    S = strlen(s), T = strlen(t);
    for (int i = 0; i <= S; ++i)
      for (int j = T; j >= 0; j--)
	for (int k = T; k >= 0; k--) {
	  if (i == 0) {
	    if (j == T)
	      dp[i][j][k] = true;
	    else
	      dp[i][j][k] = false;
	    continue;
	  }
	  dp[i][j][k] = dp[i - 1][j][k];
	  if (j == 0 || k == T) {
	    if (j == 0 && k == T)
	      continue;
	    if (j == 0) {
	      if (t[k - 1] == s[i - 1])
		dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k + 1];
	    }
	    else {
	      if (s[i - 1] == t[j - 1])
		dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - 1][k];
	    }	
	    continue;
	  }
	  if (s[i - 1] == t[j - 1])
	    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j - 1][k];
	  if (s[i - 1] == t[k])
	    dp[i][j][k] = dp[i][j][k] || dp[i - 1][j][k + 1];
	}
    bool ans = false;
    for (int i = 0; i <= T; ++i)
      if (dp[S][i][i]) {
	cout<<i<<" "<<i+1<<endl;
	ans = true;
	break;
      }
    if (ans)
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
