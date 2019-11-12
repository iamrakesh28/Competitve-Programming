#include <iostream>


using namespace std;

int dp[32][2], bit[32];
const int inf = -1e5;

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, cnt = 0, ans = 0, dist;
		scanf("%d", &n);
		for (int i = 0; i < 31; ++i) {
			if ((1 << i) & n)
				cnt++;
			bit[i] = cnt;
		}
		for (int i = 0; i < 31; ++i) {
			if ((1 << i) & n) {
				if (bit[i] == 1)
					dp[i][1] = 0;
				else
					dp[i][1] = max(dp[i - 1][1] + 1, dp[i - 1][0]);
				dp[i][0] = i;
				if (bit[i] == 1)
					dist = 0;
				else
					dist = dp[i - 1][1] + dp[i - 1][0] + 2;
				ans = max(ans, dist);
			}
			else {
				dp[i][0] = dp[i][1] = inf;
				if (i > 0)
					dp[i][0] = max(dp[i - 1][1] + 1, dp[i - 1][0]);
			}
			//cout<<dp[i][0]<<" "<<dp[i][1]<<endl;
		}
		cnt = 0;
		for (int i = 30; i >= 0; i--)
			if (((1 << i) & n) && cnt == 0) {
				dist = dp[i][1] + dp[i][0] + 1;
				//cout<<dp[i][1]<<" "<<dp[i][0]<<" "<<i<<endl;
				ans = max(ans, dist);
				cnt++;
			}
			else if (cnt) {
				dist = i + i + 1;
				ans = max(dist, ans);
			}
		printf("%d\n", ans);
	}
	return 0;
}
