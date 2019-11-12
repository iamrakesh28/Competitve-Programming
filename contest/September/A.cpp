#include <iostream>

using namespace std;


int main() {

	char ch;
	int n, z = 0, one = 0;
	scanf("%d", &n);
	for (int i  = 0; i < n; ++i) {
		scanf(" %c", &ch);
		if (ch == 'z')
			z++;
		if (ch == 'n')
			one++;
	}
	while (one--)
		printf("1 ");
	while (z--)
		printf("0 ");
	puts("");
	return 0;
}
