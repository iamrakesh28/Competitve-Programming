#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 100;
int sol[N][81 * N + 1][9], dp[N][81 * N + 1], ans[9], temp[9];

void solve(int i, int sum) {
  if (i == 0) {
    if (sum == 0)
      if (dp[0][0] == -1) {
	dp[0][0] = 1;
	for (int j = 0; j < 9; ++j)
	  sol[0][0][j] = 0;
      }
    if (sum > 0)
      dp[i][sum] = -2;
    return;
  }
  if (sum <= 0)
    return;
  if (dp[i][sum] == -1) {
    dp[i][sum] = -2;
    for (int j = 1; j <= 9; ++j) {
      solve(i - 1, sum - j * j);
      if (sum >= j * j && dp[i - 1][sum - j * j] == 1) {
	for (int k = 0; k < 9; ++k)
	  sol[i][sum][k] = sol[i - 1][sum - j * j][k];
	sol[i][sum][j - 1]++;
	dp[i][sum] = 1;
	break;
      }
    }
  }
  return;
}

int main() {
  memset(dp, -1, sizeof dp);
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j <= 81 * i; ++j)
      solve(i, j);
  }
  /*
  for (int i = 1; i < 10; ++i) {
    int cnt = 0;
    for (int j = 1; j < 100; ++j)
      if (dp[i][j] == 1)
	cnt++;
    printf("%d\n", cnt);
  }
  */
  int q;
  scanf("%d", &q);
  while (q--) {
    int n, sq, one, found = 0;
    scanf("%d", &n);
    sq = sqrt(n);
    int i = sq;
    if (sq * sq < n)
      i++;
    for (; i * i < (sq + 50) * (sq + 50); ++i) {
      for (int j = 0; j <= min(n, 99); ++j) {
	if (i * i - n + j < 0)
	  continue;
	if (dp[j][i * i - n + j] == 1) {
	  one = n - j;
	  //cout<<one<<endl;
	  if (found == 0) {
	    for (int k = 0; k < 9; ++k)
	      ans[k] = sol[j][i * i - n + j][k];
	  ans[0] += one;
	  }
	  else {
	    bool less = true;
	    for (int k = 0; k < 9; ++k)
	      temp[k] = sol[j][i * i - n + j][k];
	    temp[0] += (n - j);
	    for (int k = 0; k < 9; ++k) {
	      if (ans[k] == temp[k])
		continue;
	      if (ans[k] < temp[k])
		less = false;
	      break;
	    }
	    if (!less)
	      for (int k = 0; k < 9; ++k)
		ans[k] = temp[k];
	  }
	  //cout<<ans[0] - one<<endl;
	  found = 1;
	}
      }
    }
    if (found) {
      for (int i = 0; i < 9; ++i)
	//printf("%d ", ans[i]);
	while (ans[i]--)
	  putchar(i + '1');
      puts("");
      // puts("YES");
    }
    else
      puts("-1");
  }
  return 0;
}
