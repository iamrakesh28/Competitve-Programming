#include <iostream>

using namespace std;

int main() {

	int x, rem, a;
	char c;
	scanf("%d", &x);
	rem = x % 4;
	if (rem == 1) {
		a = 0;
		c = 'A';
	}
	else if (rem == 2) {
		a = 1;
		c = 'B';
	}
	else if (rem == 3) {
		a = 2;
		c = 'A';
	}
	else {
		a = 1;
		c = 'A';
	}
	printf("%d %c\n", a, c);
	return 0;
}
