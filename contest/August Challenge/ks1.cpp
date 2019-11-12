#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

const int N = 1e5, Ai = 1 << 21;
int arr[N], prev_pos[Ai], cnt[Ai], pos[Ai];
long long way[Ai], prev_way[Ai];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, mx = -1;
		long long ans = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
			mx = max(mx, arr[i]);
		}
		int bit = ceil(log2(mx)) + 1;
		cnt[0] = 1;
		way[0] = 0;
		pos[0] = -1;
		for (int i = 1; i < (1 << bit); ++i) {
			cnt[i] = 0;
			pos[i] = -1;
			way[i] = 0;
			prev_pos[i] = -1;
			prev_way[i] = 0;
		}
		int xo = 0;
		for (int i = 0; i < n; ++i) {
			xo = xo ^ arr[i];
			assert(xo <= (1 << bit));
			if (i - pos[xo] == 1)
				ans = ans + prev_way[xo] + (i - prev_pos[xo] - 1) * (cnt[xo] - 1);
			else
				ans = ans + way[xo] + (i - pos[xo] - 1) * cnt[xo];
			prev_way[xo] = way[xo];
			prev_pos[xo] = pos[xo];
			way[xo] = way[xo] + (i - pos[xo]) * cnt[xo];
			pos[xo] = i;
			cnt[xo]++;
			//cout<<xo<<" "<<ans<<endl;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
