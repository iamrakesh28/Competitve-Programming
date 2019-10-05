#include <iostream>

using namespace std;

int ladd[100000], m;

bool poss(int k, int n) {
	int g = 0;
	for (int i = 0; i < n; ++i) {
		if (ladd[i] - g == k)
			k--;
		else if (ladd[i] - g > k)
			return false;
		g = ladd[i];
	}
	return true;
}
int solve(int n) {
	int beg = 1, end = m, mid, ans = m;
	while (beg <= end) {
		mid = (beg + end) / 2;
		if (poss(mid, n)) {
			ans = mid;
			end = mid - 1;
		}
		else
			beg = mid + 1;
	}
	return ans;
}
int main() {

	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i) {
		int n;
		scanf("%d", &n);
		m = -1;
		for (int j = 0; j < n; ++j) {
			scanf("%d", ladd + j);
			m = max(m, ladd[j]);
		}
		printf("Case %d: %d\n", i + 1, solve(n));
	}
	return 0;
}
