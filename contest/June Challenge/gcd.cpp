#include <iostream>
#include <cassert>
#include <set>

using namespace std;

int arr[100000], pre[100000], pos[100000];
int gcd(int a, int b) {
	if (a == 0)
		return b;
	return gcd(b%a, a);
}
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, x, a, b, ans = 0;
		scanf("%d", &n);
		set <int> q;
		for (int i = 0; i < n; ++i) {
			scanf("%d", &x);
			q.insert(x);
		}
		n = q.size();
		if (n == 1) {
			printf("%d\n", 2 * (*q.begin()));
			continue;
		}
		auto it = q.begin();
		pre[0] = 0, pos[n - 1] = 0;
		for (int i = 0; i < n; ++i, it++) {
			arr[i] = *it;
			if (i)
				pre[i] = gcd(pre[i - 1], arr[i - 1]);
		}
		for (int i = n - 2; i >= 0; i--)
			pos[i] = gcd(pos[i + 1], arr[i + 1]);
		for (int i = 0; i < n; ++i)
			ans = max(ans, arr[i] + gcd(pos[i], pre[i]));//, cout<<pos[i]<<" "<<pre[i]<<" "<<arr[i]<<endl;;
		printf("%d\n", ans);
	}
	return 0;
}
