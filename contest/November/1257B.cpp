#include <iostream>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x >= y) {
			puts("YES");
			continue;
		}
		if (x == 1) {
			puts("NO");
			continue;
		}
		if (x <= 3 && y > 3) {
			puts("NO");
			continue;
		}
		puts("YES");
	}
	return 0;
}
