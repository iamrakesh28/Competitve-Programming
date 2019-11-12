#include <iostream>
#include <cmath>

using namespace std;

const int N = 470;
int sol[N][81 * N + 1][9], dp[N][81 * N + 1], ans[9], temp[9];

int main() {

	for (int i = 0; i < N; ++i) {
		for (int sum = 0; sum <= 81 * i; ++sum) {
			if (i == 0) {
				if (sum == 0) {
					dp[0][0] = 1;
					for (int j = 0; j < 9; ++j)
	  				sol[0][0][j] = 0;
				}
				else
					dp[i][sum] = -2;
			}
			else {
				dp[i][sum] = -2;
				for (int j = 1; j <= 9; ++j) {
      				if (sum >= j * j && dp[i - 1][sum - j * j] == 1) {
						for (int k = 0; k < 9; ++k)
	  						sol[i][sum][k] = sol[i - 1][sum - j * j][k];
						dp[i][sum] = 1;
						sol[i][sum][j - 1]++;
						break;
					}
				}
			}
		}
  	}
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, sq, one, found = 0;
	    scanf("%d", &n);
	    sq = sqrt(n);
    
	  for (int j = 0; j <= min(n, N); ++j) {
	      for (int i = sq; i * i <= (sq + 20) * (sq + 20); ++i) {
	
			if (i * i - n + j < 0)
				continue;
			if (dp[j][i * i - n + j] == 1) {
				one = n - j;
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
			found = 1;
		}
	}
		if (found)
		break;
	}
    if (found) {
		for (int i = 0; i < 9; ++i)
			while (ans[i]--)
				putchar(i + '1');
		puts("");
      // puts("YES");
	}
	}
}
