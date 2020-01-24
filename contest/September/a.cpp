#include <iostream>

using namespace std;

int main() {
	int a1, a2, k1, k2, n;
	scanf("%d%d%d%d%d", &a1, &a2, &k1, &k2, &n);
	int mi, ma;
	int rem, val;
	val = a2 * (k2 - 1) + a1 * (k1 - 1);
	rem = n - val;
	mi = 0;
	if (rem > 0)
		mi = rem;
	if (k1 < k2) {
		val = a1 * k1;
		if (val > n)
			ma = n / k1;
		else {
			ma = a1;
			n = n - val;
			val = a2 * k2;
			if (val > n)
			ma = ma + n / k2;
			else
			ma = ma + a2;
		}
	}
	else {
		val = a2 * k2;
		if (val > n)
			ma = n / k2;
		else {
			ma = a2;
			n = n - val;
			val = a1 * k1;
			if (val > n)
			ma = ma + n / k1;
			else
			ma = ma + a1;
		}
	}
	printf("%d %d\n", mi, ma);
	return 0;
}
