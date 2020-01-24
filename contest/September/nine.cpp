#include <iostream>

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		long long n;
		scanf("%ld", &n);
		int last = n % 10;
		int step = 9 - last;
		n = n - 9 * step;
		if (n > 0)
			printf("%d\n", step + 1);
		else
			printf("-1\n");
	}
	return 0;
}
