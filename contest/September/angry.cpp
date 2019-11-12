#include <iostream>

using namespace std;

const int prime = 1e9 + 7, N = 1e5 + 5;
long long perm[N];

long long power(long long a, long long b) {
	long long r = 1;
	while (b) {
		if (b & 1)
			r = r * a % prime;
		a = a * a % prime;
		b = b >> 1;
	}
	return r;
}

int main() {

	int q;
	scanf("%d", &q);
	perm[1] = 1;
	for (int i = 2; i < N; ++i)
		perm[i] = perm[i - 1] * i % prime;
	while (q--) {
		long long m, ans = 0;
		int n, k;
		scanf("%d%ld%d", &n, &m, &k);
		ans = power(m, n - k);
		printf("%ld\n", ans);
	}
	return 0;
}
