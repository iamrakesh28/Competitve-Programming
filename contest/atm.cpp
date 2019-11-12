#include <iostream>

using namespace std;

int dp[100005];

int main() {

	int n, amount, arr[4], mon[] = {100, 200, 500, 1000};
	scanf("%d%d", &n, &amount);
	for (int i = 0; i < 4; ++i)
		scanf("%d", arr + i);
	if (amount > n * 1000) {
		puts("0");
		return 0;
	}
	dp[0] = 0;
	for (int i = 1; i <= amount; ++i) {
		dp[i] = INT_MIN;
		for (int j = 0; j < 4; ++j) {
			if (i < mon[j])
				continue;
			dp[i] = max(dp[i], dp[i - ]);
	}
	return 0;
}
