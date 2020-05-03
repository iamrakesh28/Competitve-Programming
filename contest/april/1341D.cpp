#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e3 + 5;
int dp[N][N], arr[] = {0b1110111, 0b0010010, 0b1011101, 0b1011011, 0b0111010,
		       0b1101011, 0b1101111, 0b1010010, 0b1111111, 0b1111011};
int str[N], ct[N], ac[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6}, par[N][N];

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int num = 0, cnt = 0;
    char ch;
    for (int j = 6; j >= 0; --j) {
      scanf(" %c", &ch);
      if (ch == '1') {
	cnt++;
	num = num | (1 << j);
      }
    }
    str[i] = num;
    ct[i] = cnt;
  }
  reverse(str, str + n);
  reverse(ct, ct + n);
  for (int i = 0; i <= n; ++i)
    for (int j = 0; j <= k; ++j) {
      if (i == 0) {
	if (j == 0)
	  dp[i][j] = 10;
	else
	  dp[i][j] = -1;
	continue;
      }
      dp[i][j] = -1;
      for (int r = 0; r <= 9; ++r) {
	if ((arr[r] | str[i - 1]) == arr[r]) {
	  int cost = ac[r] - ct[i - 1];
	  if (j - cost >= 0) {
	    if (dp[i - 1][j - cost] != -1) {
	      dp[i][j] = r;
	      par[i][j] = j - cost;
	    }
	  }
	}
      }
    }
  int prev = par[n][k], val = dp[n][k], i = n - 1;
  if (val == -1) {
    puts("-1");
    return 0;
  }
  printf("%d", val);
  while (i > 0) {
    val = dp[i][prev];
    prev = par[i][prev];
    i--;
    printf("%d", val);
  }
  puts("");
  return 0;
}
