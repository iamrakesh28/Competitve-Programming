#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int n, k;
	scanf("%d%d", &n, &k);
	vector <long long> prefix(n + 1), packet(n);
	prefix[0] = 0;
	for (int i = 0; i < n; ++i) {
		long long val;
		scanf("%lld", &val);
		packet[i] = val;
	}
	sort(packet.begin(), packet.end());
	for (int i = 0; i < n; ++i)
		prefix[i + 1] = prefix[i] + packet[i];
	long long ans, cur = 0;
	for (int i = 1; i < n; ++i) {
		if (i < k) {
			cur  = cur + packet[i] * i - prefix[i];
			if (i == k - 1)
				ans = cur;
			continue;
		}
		cur = cur - (prefix[i] - prefix[i - k + 1] - (k - 1) * packet[i - k]);
		cur  = cur + packet[i] * (k - 1) - (prefix[i] - prefix[i - k + 1]);
		ans = min(ans, cur);
	}
	printf("%lld\n", ans);
	return 0;
}
