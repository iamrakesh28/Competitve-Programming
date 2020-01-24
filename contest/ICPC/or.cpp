#include <iostream>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		long long l, r, ans, temp = 0;
		scanf("%lld%lld", &l, &r);
		ans = 0;
		for (int i = 62; i >= 0; i--) {
			if (r & (1LL << i)) {
				temp = (1LL << i) - 1;
				temp = ans | temp;
				if (temp >= l) {
					ans = temp | r;
					break;
				}
				else
					ans = ans | (1LL << i);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
