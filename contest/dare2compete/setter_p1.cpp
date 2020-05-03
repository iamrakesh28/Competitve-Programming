#include <iostream>

typedef long long ll;
using namespace std;

const int N = 1e3 + 5;
const ll inf = 1e15;
char S[N], T[N];
ll dp[N][N];
int fi[N], bi[N];

int main() {
  int t;
  scanf("%d", &t);
  while (t--) {
    int n;
    scanf("%d%s%s", &n, T, S);
    for (int i = 0; i < n; ++i)
      scanf("%d", fi + i);
    for (int i = 0; i < n; ++i)
      scanf("%d", bi + i);
    for (int i = 0; i <= n; ++i)
      for (int j = n; j >= 0; j--) {
	if (i == 0) {
	  dp[i][j] = 0;
	  continue;
	}
	if (n - i < j)
	  dp[i][j] = inf;
	else {
	  dp[i][j] = inf;
	  int l = i + j - 1;
	  ll val1 = inf, val2 = inf;
	  if (T[i - 1] == S[j])
	    val1 = dp[i - 1][j + 1];
	  if (T[i - 1] == S[l])
	    val2 = dp[i - 1][j];
	  if (val1 != inf && val2 != inf)
	    dp[i][j] = min(val1 + fi[i - 1], val2 + bi[i - 1]);
	  else if (val1 != inf)
	    dp[i][j] = val1 + fi[i - 1];
	  else if (val2 != inf)
	    dp[i][j] = val2 + bi[i - 1];
	}
      }
    if (dp[n][0] != inf)
      printf("%lld\n", dp[n][0]);
    else
      puts("cannot be formed");
  }
  return 0;
}
