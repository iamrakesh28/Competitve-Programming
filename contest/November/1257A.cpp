#include <iostream>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, x, a, b;
		scanf("%d%d%d%d", &n, &x, &a, &b);
		int ans = min(n - 1, abs(a - b) + x);
		printf("%d\n", ans);
	}
	return 0;
}
