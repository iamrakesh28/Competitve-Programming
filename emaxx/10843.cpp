#include <bits/stdc++.h>

const long long prime = 2000000011;
using namespace std;

long long exp(long long a, int m) {

	long long r = 1;
	while (m > 0) {
		if (m & 1)
			r = (r * a) % prime;
		a = (a * a) % prime;
		m = m >> 1;
	}
	return r;	
}
int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		printf("Case #%d: %ld\n", i + 1, exp((long long)n, n - 2));
	}
	return 0;
}
