#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

const int bit = 62;
long long rep[bit], dp[bit][2], b;

long long solve(int len, int i, int end) {
	if (i >= len)
		return 0;
	if (i == len - 1) {
		return 1;
	}
	if (dp[i][end] == -1) {
		dp[i][end] = len - i;
		long long l = 1, r;
		if (end == 1) {
			r = rep[i];
			if (r > 0)
				dp[i][end] += (r - 1) * solve(len, i + 1, 0);
			dp[i][end] += solve(len, i + 1, 1);
		}
		else {
			r = b - 1;
			dp[i][end] += r * solve(len, i + 1, 0);
		}
		return dp[i][end];
	}
	return dp[i][end];
}

int main() {

	long long n, ans = 0, five, two;
	cin>>n>>b;
	int i = 0, k;
	while (n) {
		rep[i++] = n % b;
		n = n / b; 
	}
	k = i;
	//cout<<k<<endl;
	reverse(rep, rep + k);
	memset(dp, -1, sizeof dp);
	for (i = 0; i < k; ++i)
		cout<<rep[i]<<" ";
	long long l = 1, r;
	r = rep[0];
	ans += (r - 1) * solve(k, 1, 0);
	ans += solve(k, 1, 1);
	cout<<ans<<endl;
	for (i = 1; i < k; ++i)
		ans += solve(k, i, 0), cout<<solve(k, i, 0)<<" "<<i<<endl;
	cout<<ans - k<<endl;
	return 0;
}
