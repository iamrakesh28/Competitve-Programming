#include <iostream>

//#define debug
const int N = 1e5;

int main() {
	#ifdef debug
		freopen("testcase", "w", stdout);
	#endif

	int mon = 1e8, hero;
	hero = mon + 1;
	puts("1");
	printf("%d\n%d", N, mon);
	for (int i = 1; i < N; ++i) {
		if (i & 1)
			printf(" %d", mon);
		else
			printf(" %d", mon / 2);
	}
	printf("\n%d\n", N);
	for (int i = 0; i < N; ++i) {
		if (i & 1)
			printf("%d %d\n", hero, 2);
		else
			printf("%d %d\n", hero / 2, 1);
	}
}
