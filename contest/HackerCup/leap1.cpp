#include <iostream>
#include <cstring>

using namespace std;

int main() {

	char str[5005];
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		scanf("%s", str);
		int b = 0, dot = 0, n, req;
		bool poss = true;
		for (char *p = str; *p != '\0'; ++p) {
			if (*p == 'B')
				b++;
			if (*p == '.')
				dot++;
		}
		n = b + dot;
		if (b == 0 || dot == 0)
			poss = false;
		if (n % 2 == 0)
			req = n / 2;
		else
			req = n / 2 + 1;
		if (b < req)
			poss = false;
		printf("Case #%d: ", i + 1);
		if (poss)
			printf("Y\n");
		else
			printf("N\n");
	}
	return 0;
}
