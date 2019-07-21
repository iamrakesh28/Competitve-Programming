#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int mask[1 << 21];
vector <int> init;

int inter(int bit, int n, int i) {

	if (i == 0) {
		if (n == 0)
			return mask[bit];
		return 0;
	}
	if ((bit & (1 << (i - 1))) == 0)
		return inter(bit, n, i - 1);
	else
		return inter(bit ^ (1 << (i - 1)), n - 1, i - 1) + inter(bit, n, i - 1);
}

void subset(int bit, int i, int val) {
	if (i == 0) {
		mask[bit] += val;
		return;
	}
	subset(bit, i - 1, val);
	if (bit & (1 << (i - 1))) 
		subset(bit ^ (1 << (i - 1)), i - 1, val);
	return;
}
int main() {

	int n, t, m, cas = 0;
	while (scanf("%d%d", &n, &t) != EOF && (n || t)) {
		int ans = -1, b;
		for (int i = 0; i < n; ++i) {
			int tower;
			scanf("%d", &tower);
			mask[1 << i] = tower;
		}
		scanf("%d", &m);
		for (int i = 0; i < m; ++i) {
			int c, bit = 0, on;
			scanf("%d", &c);
			while (c--) {
				scanf("%d", &on);
				bit = bit | (1 << (on - 1));
			}
			scanf("%d", &on);
			subset(bit, n, on);
			for (int j = 0; j < n; ++j)
				if (bit & (1 << j))
					mask[1 << j] -= on;
		}
		for (int i = 0; i < (1 << n); ++i) {
			int cnt = 0, sum = 0, val = i;
			while (val) {
				cnt++;
				val = val & (val - 1);
			}
			if (cnt != t)
				continue;
			for (int j = 0; j < t; ++j) {
				if (j & 1)
					sum = sum - inter(i, t - j - 1, n);
				else
					sum = sum + inter(i, t - j - 1, n);
			}
			if (sum > ans) {
				ans = sum;
				b = i;
			}
			else if (sum == ans) {
				for (int j = 0; j < n; ++j)
					if (((b >> j) & 1) == ((i >> j) & 1))
						continue;
					else {
						if ((i >> j) & 1)
							b = i;
						break;
					}
			}
		}
		printf("Case Number  %d\nNumber of Customers: %d\nLocations recommended:", cas + 1, ans);
		for (int i = 0; i < 20; ++i)
			if (b & (1 << i))
				printf(" %d", i + 1);
		puts("\n");
		cas++;
		memset(mask, 0, sizeof(mask));
	}
	return 0;
}
