#include <iostream>
#include <climits>

using namespace std;

int arr[10000], dp[10000][2];
int main() {

	int n;
	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i)
			scanf("%d", arr + i);
		for (int i = 0; i <= n; ++i) {
			if (i == 0) {
				dp[i][0] = 0, dp[i][1] = INT_MIN;
				continue;
			}
			dp[i][0] = max(arr[i - 1], dp[i - 1][0] + arr[i - 1]);
			dp[i][1] = max(dp[i][0], dp[i - 1][1]);
		}
		if (dp[n][1] > 0)
			printf("The maximum winning streak is %d.\n", dp[n][1]);
		else
			printf("Losing streak.\n");
	}
}
