#include <iostream>

using namespace std;

int main() {
	
	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		long long a, b, c, d, e, s, num;
		scanf("%d%lld", &n, &a);
		s = a;
		num = 1;
		for (int i = 0; i < n; ++i)
			num = num * 10;
		s = s + (num << 1);
		printf("%lld\n", s);
		fflush(stdout);
		scanf("%lld", &b);
		c = num - b;
		printf("%lld\n", c);
		fflush(stdout);
		scanf("%lld", &d);
		e = num - d;
		printf("%lld\n", e);
		fflush(stdout);
		scanf("%d", &n);
		if (n == 1)
			continue;
		else
			return 0;
	}
	return 0;
}
