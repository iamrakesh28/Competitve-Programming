#include <iostream>

#define N 1000005
using namespace std;

const long long prime =  1000000007;

int arr[N];
long long power[N];

int main() {

	int q;
	scanf("%d", &q);
	power[0] = 1;
	for (int i = 1; i <= N; ++i)
		power[i] = (2 * power[i - 1]) % prime;
	for (int i = 0; i < q; ++i) {
		int n, k, sub = 0;
		long long ans = 0;
		scanf("%d%d", &n, &k);
		for (int j = 0; j < n; ++j) {
			char st;
			scanf(" %c", &st);
			if (st == 'A')
				arr[j] = -1;
			else
				arr[j] = 1;
		}
		for (int j = n - 1; j >= 0; j--) {
			if (arr[j] + sub >= 0)
				sub += arr[j];
			else
				sub = 0;
			if (sub > k) {
				sub -= 2;
				ans = (ans + power[j + 1]) % prime;
				if (sub < 0)
				sub = 0;
			}
		}
		printf("Case #%d: %lld\n", i + 1, ans);
	}
	return 0;
}
