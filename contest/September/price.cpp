#include <iostream>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, cost = 0, val;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", &val);
			cost += val;
		}
		val = cost / n;
		if (val * n == cost)
			printf("%d\n", val);
		else
			printf("%d\n", val + 1);
	}
	return 0;
}
