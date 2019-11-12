#include <iostream>

using namespace std;

int main() {

	int arr[55], i = 0, sum = 0, ans;
	bool dp[10000][55];
	while (scanf("%d", arr + i) != EOF) {
		sum += arr[i];
		i++;
	}
	for (int j = 0; j <= sum / 2; ++j) {
		for (int k = 0; k <= i; ++k) {
			if (k == 0) {
				if (j == 0)
					dp[j][k] = true;
				else
					dp[j][k] = false;
			}
			else if (j < arr[k - 1])
				dp[j][k] = dp[j][k - 1];
			else
				dp[j][k] = dp[j - arr[k - 1]][k - 1] || dp[j][k - 1];
			if (dp[j][k])
				ans = j;
		}
	}
	printf("%d\n", max(sum - ans, ans));
	return 0;
}
