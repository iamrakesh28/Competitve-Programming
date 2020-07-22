#include <iostream>

using namespace std;

const int N = 205;
int dp[3][N][N][N];

int main() {
  for (int i = 1; i < N; ++i)
    for (int j = 1; j < N; ++j)
      for (int k = 1; k < N; ++k)
	for (int p = 0; p < 3; ++p) {
	  if (i == 1 ||  j == 1 || k == 1) {
	    dp[p][i][j][k] = p;
	    continue;
	  }
	  int arr[] = {0, 0, 0};
	  arr[dp[(p + 1) % 3][i - 1][j][k]] = 1;
	  arr[dp[(p + 1) % 3][i][j - 1][k]] = 1;
	  arr[dp[(p + 1) % 3][i][j][k - 1]] = 1;
	  if (arr[p])
	    dp[p][i][j][k] = p;
	  else if (arr[(p + 1) % 3])
	    dp[p][i][j][k] = (p + 1) % 3;
	  else
	    dp[p][i][j][k] = (p + 2) % 3;
	  //cout<<((p+1)%3)<<" "<<p<<" "<<i<<" "<<j<<" "<<k<<endl;
	}
  int t;
  scanf("%d", &t);
  char ans[][9] = {"Santhosh", "Ahmed", "Rakesh"};
  while (t--) {
    int c1, c2, c3;
    scanf("%d%d%d", &c1, &c2, &c3);
    puts(ans[dp[0][c1][c2][c3]]);
    //cout<<dp[0][2][3][3]<<endl;
  }
  return 0;
}
