#include <iostream>
#include <cstring>

using namespace std;

int arr[2000], dp[2000][2], en[2000][2];

// 0 -> left, 1 -> right
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
			dp[i][0] = dp[i][1] = 1;
			en[i][0] = en[i][1] = -1;
		}
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (arr[i] > arr[j]) {
					if (dp[i][0] < dp[j][0] + 1) {
						dp[i][0] = dp[j][0] + 1;
						if (en[j][0] == -1)
							en[i][0] = arr[j];
						else
							en[i][0] = en[j][0];
					}
					if ((en[j][1] == -1 || en[j][1] < arr[i]) && dp[i][0] < dp[j][1] + 1) {
						dp[i][0] = dp[j][1] + 1;
						en[i][0] = arr[j];
					}
				}
				else {
					if (dp[i][1] < dp[j][1] + 1) {
						dp[i][1] = dp[j][1] + 1;
						if (en[j][1] == -1)
							en[i][1] = arr[j];
						else
							en[i][1] = en[j][1];
					}
					if ((en[j][0] == -1 || en[j][0] > arr[i] )&& dp[i][1] < dp[j][0] + 1) {
						dp[i][1] = dp[j][0] + 1;
						en[i][1] = arr[j];
					}
				}
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			ans = max(ans, dp[i][0]);
			ans = max(ans, dp[i][1]);
			cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		printf("%d\n", ans);
	}
	return 0;
}
