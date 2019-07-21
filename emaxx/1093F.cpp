#include <iostream>
#include <vector>

#define N 100005
using namespace std;

long long dp[N][105], sdp[N], d, s;
const long long prime = 998244353;

int main() {

	int n, k, len;
	scanf("%d%d%d", &n, &k, &len);
	vector <int> arr(n), dan(n, -2), win(k, 0);
	for (int i = 0; i < n; ++i)
		scanf("%d", &arr[i]);
	for (int i = 0; i < n; ++i) {
		if (arr[i] != -1)
			win[arr[i] - 1]++;
		if (i >= len) {
			if (arr[i - len] != -1)
				win[arr[i - len] - 1]--;
		}
		if (i >= len - 1) {
			int cnt = 0, ind;
			for (int it = 0; it < k; ++it)
				if (win[it] > 0)
					cnt++, ind = it;
			if (cnt == 0)
				dan[i] = -1;
			else if (cnt == 1)
				dan[i] = ind;
		}
	}
	sdp[0] = 1;
	for (int i = 1; i <= n; ++i) {
		for (int j = 0; j < k; ++j) {
			s = sdp[i - len], d = dp[i - len][j];
			if (dan[i - 1] == -1) {
				dp[i][j] = (sdp[i - 1] - s + d + prime) % prime;
				sdp[i] = (sdp[i] + dp[i][j]) % prime;
				continue;
			}
			else if (dan[i - 1] == j) {
				//cout<<sdp[i - 1]-s + d<<" ";
				dp[i][j] = (sdp[i - 1] - s + d + prime) % prime;
				sdp[i] = (sdp[i] + dp[i][j]) % prime;
				continue;
			}
			if (arr[i - 1] == -1) {
				dp[i][j] = sdp[i - 1];
				sdp[i] = (sdp[i] + dp[i][j]) % prime;
			}
			else if (dan[i - 1] == -2)
				sdp[i] = sdp[i - 1], dp[i][j] = sdp[i - 1];
				
		}
		//cout<<sdp[i]<<endl;
	}
	cout<<sdp[n]<<endl;
	return 0;
}
