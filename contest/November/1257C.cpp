#include <iostream>

using namespace std;

const int N = 2e5 + 5, inf = 1e8;
int occ[N], dom[N], pre[N];

int main() {
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, poss = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			occ[i] = 0, dom[i] = inf;
		for (int i = 0; i < n; ++i) {
			int a;
			scanf("%d", &a);
			occ[a - 1]++;
			if (occ[a - 1] > 1) {
				poss = 1;
				dom[a - 1] = min(dom[a - 1], i - pre[a - 1] + 1);
			}
			pre[a - 1] = i;
		}
		if (!poss) {
			puts("-1");
			continue;
		}
		int ans = inf;
		for (int i = 0; i < n; ++i)
			ans = min(ans, dom[i]);
		printf("%d\n", ans);
	}
	return 0;
}
