#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, ans, ev = 0, odd = 0;
		scanf("%d", &n);
		char ch = getchar();
		vector <int> v;
		for (int i = 0; i < n; ++i) {
			int len = 0;
			while ((ch = getchar()) != '\n') {
				if (ch == '0')
					ev++;
				else
					odd++;
				len++;
			}
			v.push_back(len);
		}
		sort(v.begin(), v.end());
		ans = n;
		if (v[n - 1] & 1) {
			printf("%d\n", ans);
			continue;
		}
		int i = 0;
		for (int it : v) {
			int val = it;
			if (++i == n)
				break;
			if (val & 1) {
				if (ev & 1)
					ev--, val--;
				else if (odd & 1)
					odd--, val--;
				if (val >= ev) {
					ev -= val;
					continue;
				}
				if (val>= odd) {
					odd -= val;
					continue;
				}
			}
			else {
				if (val >= ev) {
					ev -= val;
					continue;
				}
				if (val>= odd) {
					odd -= val;
					continue;
				}
			}
		}
		if (ev & 1)
			ans--;
		printf("%d\n", ans);
	}
	return 0;
}
