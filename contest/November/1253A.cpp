#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int a[N];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, poss = 1;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			scanf("%d", a + i);
		for (int i = 0; i < n; ++i) {
			int val;
			scanf("%d", &val);
			a[i] = a[i] - val;
		}
		int seg = 0;
		for (int i = 0; i < n; ++i) {
			if (a[i] != 0) {
				if (a[i] > 0)
					poss = 0;
				if (i) {
					if (a[i - 1] == 0)
						seg++;
					else if (a[i - 1] != a[i])
						poss = 0;
				}
				else
					seg++;
			}
		}
		if (seg >= 2)
			poss = 0;
		if (poss)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
