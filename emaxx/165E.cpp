#include <iostream>
#include <vector>
#include <cmath>

#define N 4200005
using namespace std;

int freq[N], dp[N];
int main() {

	int n, m = -1;
	scanf("%d", &n);
	vector <int> arr(n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &arr[i]);
		freq[arr[i]]++;
		m = max(m, arr[i]);
	}
	for (int i = 0; i <= m; ++i)
		if (freq[i])
			dp[i] = i;
		else
			dp[i] = 0;
	int c = ceil(log2(m));
	for (int i = 0; i < c; ++i)
		for (int mask = 0; mask <= (1 << c); ++mask)
			if (mask & (1 << i))
				if (dp[mask] == 0)
					dp[mask] = dp[mask ^ (1 << i)];
	for (int i = 0; i < n; ++i) {
		if (dp[(1 << c) - 1 - arr[i]])
			printf("%d ", dp[(1 << c) - 1 - arr[i]]);
		else
			printf("-1 ");
	}
	puts("");
	return 0;
}
