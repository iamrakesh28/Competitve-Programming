#include <stdio.h>

int main() {
	
	int n, k;
	scanf("%d%d", &n, &k);
	if (n == 2)
		printf("%ld\n", (long long) k * k);
	else
		printf("%d\n", k);
	return 0;
}
