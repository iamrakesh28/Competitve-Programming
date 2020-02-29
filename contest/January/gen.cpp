#include <iostream>

using namespace std;

int main() {
	int n = 10, d = 100000;
	printf("%d\n", n * d);
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= d; ++j) {
			printf("%d %d\n", i, j);
		}
	}
	return 0;
}
