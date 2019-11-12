#include <iostream>

using namespace std;

const int N = 21;

long long a[N], b[N];

long long backtrack(int i, long long sum1, long long sum2, long long h) {
	if (i < 0) {
		if (sum1 >= h && sum2 >= h)
			return 1;
		return 0;
	}
	long long ans = backtrack(i - 1, sum1 + a[i], sum2, h);
	ans += backtrack(i - 1, sum1, sum2 + b[i], h);
	ans += backtrack(i - 1, sum1 + a[i], sum2 + b[i], h);
	return ans;
}

int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		long long h;
		scanf("%d%lld", &n, &h);
		for (int j = 0; j < n; ++j)
			scanf("%lld", a + j);
		for (int j = 0; j < n; ++j)
			scanf("%lld", b + j);
		long long ans = backtrack(n - 1, 0, 0, h);
		printf("Case #%d: %lld\n", i + 1, ans);
	}
	return 0;
}
