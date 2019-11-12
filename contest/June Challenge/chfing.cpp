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
		long long n, k, diff, ans, t, up;
		scanf("%lld%lld", &n, &k);
		ans = (k - 1) % prime;
		if (k > n) {
			diff = k - n;
			t = diff / (n - 1) + 1;
			//if (diff + (1 - n) * (t - 1) == 0)
			//	t--;
			t = t % prime;
			n = n % prime;
			diff = diff % prime;
			up = ((t - 1) * (1 - n)) % prime;
			up = (t * ((2 * diff + up) % prime)) % prime;
			up = (up + prime) % prime;
			//cout<<up<<endl;
			ans = (ans + (up * mod2) % prime) % prime;
			assert(ans >= 0 && up >= 0);
		}
		printf("%lld\n", ans);
	}
}
