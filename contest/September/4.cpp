#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 5;

long long a[N], b[N], dp[N][3];

int main() {

	//ios_base::sync_with_stdio(false);
    //cin.tie(nullptr);
	int q;
	cin>>q;
	while (q--) {
		int n;
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>a[i]>>b[i];
		dp[0][1] = b[0];
		dp[0][0] = 0;
		dp[0][2] = 2 * b[0];
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < 3; ++j) {
				long long cur = a[i] + j, v = -1;
				
				for (int k = 0; k < 3; ++k) {
					if (a[i - 1] + k == cur)
						continue;
					if (v == -1)
						v = dp[i - 1][k] + b[i] * j;
					else
						v = min(v, dp[i - 1][k] + b[i] * j);
				}
				dp[i][j] = v;
			}
		}
		long long ans = min(dp[n - 1][0], dp[n - 1][1]);
		ans = min(ans, dp[n - 1][2]);
		cout<<ans<<endl;
	}
}
