#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;
long long a[N];
long long sum[N], ans[N];

int main() {
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; ++i)
		scanf("%lld", a + i);
	sort(a, a + n);
	reverse(a, a + n);
	for (int i = 0; i < m; ++i) {
		long long val = 0;
		for (int j = i; j < n; j += m)
			val += a[j];
		sum[i] = val;
	}
	int day = 0;
	long long par = 0;
	for (int i = 0; i < n; ++i) {	
		if (i % m == 0)
			day++;
		par = par + day * a[i];
	}
	ans[n - 1] = par;
	day = 0;
	for (int i = n - 2; i >= 0; i--) {
		par = par - sum[day];
		ans[i] = par;
		sum[day] = sum[day] - a[n - i - 2];
		day = (day + 1) % m;
	}
	for (int i = 0; i < n; ++i)
		printf("%lld ", ans[i]);
	puts("");
	return 0;
}
