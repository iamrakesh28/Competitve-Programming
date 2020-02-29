#include <iostream>

using namespace std;

char s[105];
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int k;
		scanf("%d%s", &k, s);
		char c;
		int ans = 0, ang = -1, prev = 0;
		for (int i = 0; i < k; ++i) {
			if (s[i] == 'A') {
				ang = i;
				break;
			}
		}
		if (ang == -1) {
			puts("0");
			continue;
		}
		for (int i = ang; i < k; ++i) {
			if (s[i] == 'P')
				prev++;
			else {
				ans = max(ans, prev);
				prev = 0;
			}
		}
		ans = max(ans, prev);
		printf("%d\n", ans);
	}
	return 0;
}
