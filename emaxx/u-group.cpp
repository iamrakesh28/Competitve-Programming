#include <iostream>

#define N 16
using namespace std;

long long arr[N][N], mask[1 << N], dp[1 << N];

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			scanf("%lld", arr[i] + j);
	// N^2 x 2 ^ N
	for (int i = 0; i < (1 << n); ++i) {
		long long mut = 0;
		for (int j = 0; j < n; ++j)
			for (int k = j + 1; k < n; ++k)
				if ((i & (1 << j)) && (i & (1 << k)))
					mut += arr[j][k];
		mask[i] = mut;
		//cout<<mut<<endl;
	}
	// N x 2 ^ N
	for (int i = 0; i < (1 << n); ++i)
		dp[i] = mask[i];
	for (int i = 0; i < (1 << n); ++i)
		for (int j = i; j > 0; j = (j - 1) & i)
			dp[i] = max(dp[i], dp[i ^ j] + mask[j]); 
	/*
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			if (j & (1 << i))
				dp[j] = max(dp[], dp[]);
		}
	}
	*/
	printf("%lld\n", dp[(1 << n) - 1]);
	return 0;
}
