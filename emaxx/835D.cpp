#include <iostream>
#include <cstring>

#define N 5001

using namespace std;

char s[N];
int dp[N][N], ans[N];
int main() {

	int n;
	scanf("%s", s);
	n = strlen(s);
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j + i - 1 < n; ++j) {
			int l = j, r = i + j - 1;
			if (i == 1) {
				dp[l][r] = 1;
				ans[dp[l][r]]++;
				continue;
			}
			if (s[l] == s[r]) {
				if (i > 2 && dp[l + 1][r - 1]) {
					int m = l + r;
					if (m & 1)
						m = m / 2;
					else
						m = m / 2 - 1;
					dp[l][r] =  dp[l][m] + 1;
				}
				else if (i == 2)
					dp[l][r] = 2;
			}
			ans[dp[l][r]]++;
		}
	}
	for (int i = n; i > 0; i--)
		ans[i - 1] += ans[i];
	for (int i = 1; i <= n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
