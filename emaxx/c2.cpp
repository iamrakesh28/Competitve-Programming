#include <bits/stdc++.h>

#define N 200005
using namespace std;

int arr[N], ans[N];
int main() {

	int n, m, sum = 0, prev = 0;
	scanf("%d%d", &n, &m);
	multiset <int> q;
	for (int i = 0; i < n; ++i) {
		scanf("%d", arr + i);
		sum += arr[i];
		if (sum <= m) {
			ans[i] = prev;
			q.insert(arr[i]);
		}
		else {
			auto it = q.end();
			it--;
			int req = sum, cnt = 0;
			if (*it >= arr[i]) {
				prev++;
				sum = sum - *it;
				q.erase(it);
				q.insert(arr[i]);
				ans[i] = prev;
			}
			else {
				sum -= arr[i];
				while (req > m) {
					req = req - (*it);	
					it--;
					cnt++;
				}
				ans[i] = cnt + prev;
				prev++;
			}
		}
	}
	for (int i = 0; i < n; ++i)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
