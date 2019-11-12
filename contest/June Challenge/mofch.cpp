#include <bits/stdc++.h>

using namespace std;

const long long prime = 1e9 + 7;

long long mod(long long a, long long y) {
	
	long long r = 1;
	while (y) {
		if (y % 2)
			r = (r * a) % prime;
		a = (a * a) % prime;
		y = y >> 1;
	}
	return r;
}
int main() {

	int q;
	scanf("%d", &q);
	long long mod2 = mod(2, prime - 2);
	while (q--) {
		long long n, k, diff, ans;
		scanf("%ld%ld", &n, &k);
		diff = (k - n) % prime;
		ans = (k - 1) % prime;
		if (k > n)
			ans = (ans + (((diff * (diff + 1)) % prime) * mod2) % prime) % prime;
		printf("%ld\n", ans);
	}
}

