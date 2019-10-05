#include <iostream>
#include <set>

#define N 100005

using namespace std;

char S[N];
long long power1[N], hs1[N], power2[N], hs2[N];
const int p1 = 31, m1 = 1e9 + 9, p2 = 53, m2 = 1e9+ 7;

int main() {

	int q;
	scanf("%d", &q);
	power2[0] = power1[0] = 1;
	hs2[0] = hs1[0] = 0;
	while (q--) {
		int n, k;
		scanf("%d%d", &n, &k);
		scanf("%s", S);
		set <pair<long long, long long>> q;
		for (int i = 1; i < n; ++i) {
			power1[i] = (power1[i - 1] * p1) % m1;
			power2[i] = (power2[i - 1] * p2) % m2;
		}
		for (int i = 0; i < n; ++i) {
			hs1[i + 1] = (hs1[i] + (S[i] - 'a' + 1) * power1[i]) % m1;
			hs2[i + 1] = (hs2[i] + (S[i] - 'a' + 1) * power2[i]) % m2;
		}
		for (int i = 0; i + k - 1 < n; ++i) {
			long long cur1 = (hs1[i + k] - hs1[i] + m1) % m1;
			cur1 = cur1 * power1[n - i - 1] % m1;
			long long cur2 = (hs2[i + k] - hs2[i] + m2) % m2;
			cur2 = cur2 * power2[n - i - 1] % m2;
			q.insert({cur1, cur2});
		}
		printf("%d\n", q.size());
	}
	return 0;
}
