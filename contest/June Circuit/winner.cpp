#include <iostream>
//#include <cstdio>

using namespace std;

int main() {

	int t;
	scanf("%d", &t);
	char a[] = "gdf";
	len = strlen(a);
	while (t--) {
		long long n, k;
		scanf("%lld%lld", &n, &k);
		if (n % (k + 1))
			printf("Arpa\n");
		else
			printf("Dishant\n");
	}
	return 0;
}
