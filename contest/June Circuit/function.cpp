#include <iostream>

using namespace std;

int p;

long long power(long long a, long long x) {
	long long r = 1;
	while (x) {
		if (x & 1)
			r = (r * a) % p;
		a = (a * a) % p;
		x = x >> 1;
	}
	return r;
}

int main() {

	int t;
	scanf("%d%d", &t, &p);
	long long two = power(2, p - 2);
	while (t--) {
		long long l, r, ans = 0;
		int even, odd, estart, ostart;
		scanf("%lld%lld", &l, &r);
		if ((r - l + 1) % 2) {
			if (l % 2) {
				even = (r - l + 1) / 2;
				odd = even + 1;
				estart = l + 1;
				ostart = l;
			}
			else {
				odd = (r - l + 1) / 2;
				even = odd + 1;
				estart = l;
				ostart = l + 1;
			}
		}
		else {
			even = odd = (r - l + 1) / 2;
			if (l % 2) {
				ostart = l;
				estart = l + 1;
			}
			else {
				estart = l;
				ostart = l + 1;
			}
		}
		if (odd) {
			ans = (power(3, (ostart - 1) / 2 + odd) - 1 + p) % p;
			ans = (ans * two) % p;
			ans = (ans - (((power(3, (ostart - 1) / 2) - 1 + p) % p) * two) % p) % p;
		}
		if (even) {
		}
	}
	return 0;
}
