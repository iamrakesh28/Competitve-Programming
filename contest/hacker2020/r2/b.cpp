#include <iostream>

using namespace std;

const int N = 8e3 + 5;
double dp[N][N], ans[N];

int main() {
  int t;
  scanf("%d", &t);
  for (int h = 0; h < t; ++h) {
    int n;
    double p;
    scanf("%d%lf", &n, &p);
    //cout << p << endl;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j) {
	int tot = i + j;
	if (tot > n - 1) {
	  dp[i][j] = 0.0;
	  break;
	}
	if (tot <= 1) {
	  if (tot == 0) {
	    dp[i][j] = 0.0;
	    continue;
	  };
	  dp[i][j] = 1.0;//n - tot;
	  continue;
	}
	dp[i][j] = 1.0;//n - tot;
	double prob = 0, temp, order, val;
	order = tot * (tot + 1) / 2;
	if (i > 0) {
	  val = i * (i - 1) / 2;
	  val = val / order;
	  temp = i / order;
	  val = val + p * temp;
	  //cout << val << endl;
	  //prob = prob + val;
	  dp[i][j] = dp[i][j] + val * dp[i - 1][j];
	}
	if (j > 0) {
	  val = j * (j - 1) / 2;
	  val = val / order;
	  temp = j / order;
	  val = val + (1 - p) * temp;
	  //prob = prob + val;
	  dp[i][j] = dp[i][j] + val * dp[i][j - 1];
	}
	val = i * j;
	val = val / order;
	if (i > 0 && j > 0) {
	  //prob = prob + val;
	  dp[i][j] = dp[i][j] + val * p * dp[i - 1][j];
	  dp[i][j] = dp[i][j] + val * (1 - p) * dp[i][j - 1];
	}
	//dp[i][j] = dp[i][j] + (n - tot) * prob;
      }
    for (int i = 0; i < n; ++i) {
      ans[i] = dp[i][n - i - 1];
      //cout << ans[i]<< endl;
    }
    //cout << ans[0] << endl;
    printf("Case #%d:\n", h + 1);
    for (int i = 0; i < n; ++i)
      printf("%0.12lf\n", ans[i]);
  }
  return 0;
}
