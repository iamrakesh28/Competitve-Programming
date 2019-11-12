#include <iostream>
#include <cstdio>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	char c = getchar();
	while (q--) {
		int cnt = 0;
		while ((c = getchar()) && c != '\n') {
			if (c == '1')
				cnt++;
		}
		if (cnt % 2)
			puts("WIN");
		else
			puts("LOSE");
	}
	return 0;
}
