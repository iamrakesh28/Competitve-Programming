#include <iostream>

using namespace std;

const int N = 2e5 + 5;

int power[N], en[N], mons[N], hero[N];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, mxm = -1, mxh = -1, m, ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", mons + i);
			mxm = max(mxm, mons[i]);
			hero[i] = 0;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			scanf("%d%d", power + i, en + i);
			mxh = max(mxh, power[i]);
			hero[en[i] - 1] = max(hero[en[i] - 1], power[i]);
		}
		if (mxh < mxm) {
			puts("-1");
			continue;
		}
		for (int i = n - 2; i >= 0; --i)
			hero[i] = max(hero[i], hero[i + 1]);
		int day = 0, cur = -1, cons = -1;
		while (day < n) {
			cur = max(cur, mons[day]);
			//cout<<day+1<<" "<<cur<<" ";
			cons++;
			if (hero[cons] < cur) {
				ans++;
				cons = 0;
				cur = mons[day];
			}
			//cout<<ans<<endl;
			day++;
		}
		ans++;
		printf("%d\n", ans);
	}
	return 0;
}
