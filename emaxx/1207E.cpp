#include <iostream>

using namespace std;

const int n = 100;

int main() {
	
	int ret, ans = 0x7f, temp = 0xffffff80;
	printf("? ");
	for (int i = 1; i <= n; ++i)
		printf("%d ", i << 7);
	puts("");
	fflush(stdout);
	scanf("%d", &ret);
	ans = ans & ret;
	printf("? ");
	for (int i = 0; i < n; ++i)
		printf("%d ", i);
	puts("");
	fflush(stdout);
	scanf("%d", &ret);
	temp = temp & ret;
	ans = ans | temp;
	printf("! %d\n", ans);
	return 0;
}
