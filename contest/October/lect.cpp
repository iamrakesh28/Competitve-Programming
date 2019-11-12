#include <iostream>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int a, b, c, d, k, x, y;
		scanf("%d%d%d%d%d", &a, &b, &c, &d, &k);
		x = a / c;
		if (x * c != a)
			x++;
		y = b / d;
		if (y * d != b)
			y++;
		if (x + y <= k)
			printf("%d %d\n", x, y);
		else
			puts("-1");
	}
	return 0;
}
