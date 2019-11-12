#include <iostream>

using namespace std;

double ki[100005], ci[100005];
int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%lf", ki + i);
		for (int i = 0; i < n; ++i)
			scanf("%lf", ci + i);
		printf("%lf ", 0.0);
		for (int i = 0; i < n; ++i)
			printf("%lf ", 0.0);
		puts("");
	}
}
