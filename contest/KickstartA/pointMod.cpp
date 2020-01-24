#include <iostream>
#include <cmath>

using namespace std;

int even[100005], odd[100005];

int main() {

	int q;
	scanf("%d", &q);
	for (int j = 0; j < q; ++j) {
		long long l, r, m;
		int cnt = 0;
		scanf("%ld%ld", &l, &r);
		m = sqrt(r);
		for (int i = 0; i <= r - l; ++i)
			even[i] = 0, odd[i] = 0;
		for (int i = 1; i <= m; ++i) {
			long long ll = l / i, rr = r / i;
			if (ll * i < l)
				ll++;
			for (long long k = ll; k <= rr; ++k) {
				if (k < i)
					continue;
				if (k == i) {
					if (k & 1)
						odd[k * k - l]++;
					else
						even[k * k - l]++;
				}
				else {
					if (k & 1)
						odd[k * i - l]++;
					else
						even[k * i - l]++;
					if (i & 1)
						odd[k * i - l]++;
					else
						even[k * i - l]++;
				}
			}
		}
		for (int i = 0; i <= r - l; ++i)
			if (abs(even[i] - odd[i]) <= 2)
				cnt++;
		printf("Case #%d: %d\n", j + 1, cnt);
	}
	return 0;
}
