#include <iostream>
#include <cmath>

using namespace std;

const int size = 5005;
double dp[size][4][2], inf = 2e15;

pair <int, int> N[size], M[size], K[size];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		double x1, y1;
		scanf("%lf%lf", &x1, &y1);
		int n, m, k;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d%d", &N[i].first, &N[i].second);
		for (int i = 0; i < m; ++i)
			scanf("%d%d", &M[i].first, &M[i].second);
		for (int i = 0; i < k; ++i)
			scanf("%d%d", &K[i].first, &K[i].second);
		for (int i = 0; i < k; ++i)
			dp[i][3][0] = 0.0;
		for (int i = 0; i < m; ++i) {
			dp[i][2][0] = inf;
			for (int j = 0; j < k; ++j) {
				double x = M[i].first - K[j].first;
				double y = M[i].second - K[j].second;
				double d = sqrt(x * x + y * y);
				dp[i][2][0] = min(dp[i][2][0], d);
			}
		}

		for (int i = 0; i < n; ++i) {
			dp[i][1][0] = inf;
			for (int j = 0; j < k; ++j) {
				double x = N[i].first - K[j].first;
				double y = N[i].second - K[j].second;
				double d = sqrt(x * x + y * y);
				dp[i][1][0] = min(dp[i][1][0], d);
			}
		}

		for (int i = 0; i < m; ++i) {
			dp[i][2][1] = inf;
			for (int j = 0; j < n; ++j) {
				double x = M[i].first - N[j].first;
				double y = M[i].second - N[j].second;
				double d = sqrt(x * x + y * y);
				dp[i][2][1] = min(dp[i][2][1], d + dp[j][1][0]);
			}
		}

		for (int i = 0; i < n; ++i) {
			dp[i][1][1] = inf;
			for (int j = 0; j < m; ++j) {
				double x = N[i].first - M[j].first;
				double y = N[i].second - M[j].second;
				double d = sqrt(x * x + y * y);
				dp[i][1][1] = min(dp[i][1][1], d + dp[j][2][0]);
			}
		}

		double ans = inf;
		for (int j = 0; j < m; ++j) {
			double x = x1 - M[j].first;
			double y = y1 - M[j].second;
			double d = sqrt(x * x + y * y);
			ans = min(ans, d + dp[j][2][1]);
		}

		for (int j = 0; j < n; ++j) {
			double x = x1 - N[j].first;
			double y = y1 - N[j].second;
			double d = sqrt(x * x + y * y);
			ans = min(ans, d + dp[j][1][1]);
		}
		printf("%0.12lf\n", ans);
	}
	return 0;
}
