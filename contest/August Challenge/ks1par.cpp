#include <iostream>
#include <cmath>
#include <cassert>

using namespace std;

const int N = 1e5, Ai = 1050000;
int arr[N], prefix[N], cnt[Ai], pos[Ai];
long long way[Ai];

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
		for (int i = 0; i < n; ++i) {
			int xo = arr[i];
			for (int j = i + 1; j < n; ++j) {
				xo = xo ^ arr[j];
				if (xo == 0)
					ans += j - i;
			}
		}
		/*
		int bit = ceil(log2(mx));
		cnt[0] = 1;
		way[0] = 0;
		pos[0] = 0;
		for (int i = 1; i < (1 << bit); ++i)
			cnt[i] = 0;
		int xo = 0;
		for (int i = 0; i < n; ++i) {
			xo = xo ^ arr[i];
			assert(xo <= (1 << bit));
			way[xo] = way[xo] + (i - pos[xo]) * cnt[xo];
			pos[xo] = i;
			cnt[xo]++;
			ans += way[xo];
		}*/
		printf("%lld\n", ans);
	}
	return 0;
}

