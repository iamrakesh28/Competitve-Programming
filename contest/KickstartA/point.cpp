#include <iostream>

using namespace std;

int diff(long long num) {
	long long even = 0, odd = 0;
	for (long long i = 1; i * i <= num; ++i) {
		if (num % i == 0) {
			if (i & 1)
				odd++;
			else
				even++;
			if (i * i == num)
				continue;
			long long v = num / i;
			if (v & 1)
				odd++;
			else
				even++;			
		}
	}
	return abs(odd - even);
}

int main() {

	int q;
	scanf("%d", &q);
	for (int j = 0; j < q; ++j) {
		long long l, r;
		int cnt = 0;
		scanf("%ld%ld", &l, &r);
		for (long long i = l; i <= r; ++i)
			if (diff(i) <= 2)
				cnt++;
		printf("Case #%d: %d\n", j + 1, cnt);
	}
	return 0;
}
