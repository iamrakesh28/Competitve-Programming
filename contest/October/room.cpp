#include <iostream>

using namespace std;

char s[1005];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, ans, l, r = -1;
		char ch;
		scanf("%d", &n);
		ch = getchar();
		l = n;
		for (int i = 0; i < n; ++i) {
			ch = getchar();
			s[i] = ch;
			if (ch == '1') {
				l = min(l, i);
				r = max(r, i);
			}
		}
		ans = n;
		if (l == n) {
			printf("%d\n", ans);
			continue;
		}
		ans = 2 * max(n - l, r + 1);
		printf("%d\n", ans);
	}
	return 0;
}
