#include <iostream>
#include <cstring>

using namespace std;

char a[1001], b[1001];
bool dp[1001][1001];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s%s", a, b);
		int A = strlen(a), B = strlen(b);
		for (int i = 0; i <= A; ++i)
			for (int j = 0; j <= B; ++j) {
				if (j == 0) {
					if (i == 0)
						dp[i][j] = true;
					else {
						if (islower(a[i - 1]))
							dp[i][j] = dp[i - 1][j];
						else
							dp[i][j] = false;
					}
				}
				else if (i == 0)
					dp[i][j] = false;
				else {
					if (a[i - 1] == b[j - 1])
						dp[i][j] = dp[i - 1][j - 1];
					else if (a[i - 1] == (char)tolower(b[j - 1]))
						dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j];
					else {
						if (islower(a[i - 1]))
							dp[i][j] = dp[i - 1][j];
						else
							dp[i][j] = false;
					}
				}
			}
		if (dp[A][B])
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
