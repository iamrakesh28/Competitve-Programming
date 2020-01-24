#include <iostream>

using namespace std;

const int N = 2e5 + 5;
long long arr[N], dp[N];

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q;
	cin>>q;
	while (q--) {
		long long h;
		int n;
		cin>>h>>n;
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		dp[0] = 0;
		for (int i = 1; i < n; ++i) {
			if (arr[i - 1] - arr[i] >= 2)
				dp[i] = dp[i - 1] + 1;
			else {
				dp[i] = dp[i - 1] + 1;
				if (i - 2 >= 0)
					dp[i] = min(dp[i], dp[i - 2]);
			}
		}
		long long ans;
		if (arr[n - 1] == 1) {
			ans = dp[n - 1];
			if (n - 2 >= 0)
				ans = min(ans, dp[n - 2]);
		}
		else
			ans = dp[n - 1];
		cout<<ans<<"\n";
	}
	return 0;
}
