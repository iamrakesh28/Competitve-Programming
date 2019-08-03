#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {

	char word[85];
	int dp[85][85];
	vector <int> pi[85];

	while (scanf("%s", word) != EOF && word[0] != '*') {
		int n = strlen(word);
		for (int i = 0; i < n; ++i) {
			pi[i].resize(n);
			pi[i][i] = 0;
			for (int k = i + 1; k < n; ++k) {
				int j = pi[i][k - 1];
				while (j > 0 && word[j + i] != word[k])
					j = pi[i][i + j - 1];
				if (word[i + j] == word[k])
					j++;
				pi[i][k] = j;
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 0; j + i - 1 < n; ++j) {
				int l = j, r = j + i - 1;
				if (l == r)
					dp[l][r] = 1;
				else {
					dp[l][r] = i;
					for (int k = l; k < r; ++k)
						dp[l][r] = min(dp[l][r], dp[l][k] + dp[k + 1][r]);
					int len = pi[l][r];
					if (len == 0)
						continue;
					if (i % (i - len) == 0)
						dp[l][r] = min(dp[l][r], dp[l][l + i - len - 1]);
				}
			}
		}
		/*for (int i = 0; i < n; ++i) {
			for (int j = i; j < n; ++j)
				cout<<dp[i][j]<<" ";
			cout<<endl;
		}*/
		printf("%d\n", dp[0][n - 1]);
		for (int i = 0; i < n; ++i)
			pi[i].clear();
	}
	return 0;
}
