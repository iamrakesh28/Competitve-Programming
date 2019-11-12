#include <bits/stdc++.h>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n, m, k, a, b, pos = 0;
		int x[2], y[2];
		scanf("%d%d%d", &n, &m, &k);
		scanf("%d%d", &a, &b);
		for (int j = 0; j < k; ++j)
			scanf("%d%d", x + j, y + j);
		if (k == 1) {
			printf("Case #%d: N\n", i + 1);
			continue;
		}
		int dist = abs(x[0] - x[1]) + abs(y[0] - y[1]), d1, d2, d;
		if (dist & 1) {
			printf("Case #%d: N\n", i + 1);
			continue;
		}
		for (int j = 1; j <= n - 1; ++j) {
			for (int r = 1; r <= m - 1; ++r) {
				d1 = max(abs(j - x[0]) + abs(r - y[0]), abs(j - x[1] + 1) + abs(r - y[1] + 1));
				d2 = max(abs(j - x[1]) + abs(r - y[1]), abs(j - x[0] + 1) + abs(r - y[0] + 1));
				dist = min(d1, d2);
				d = min(abs(j - a) + abs(r - b), abs(j - a + 1) + abs(r - b + 1));
				if (d >= dist) {
					pos = 1;
					break;
				}
				if (dist % 2 == 0 && d % 2) {
					pos = 1;
					break;
				}
				if (dist % 2 && d % 2 == 0) {
					pos = 1;
					break;
				}
				
			}
		}
		printf("Case #%d: ", i + 1);
		if (pos)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
