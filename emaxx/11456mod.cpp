#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int arr[2000], l[2000], r[2000];

// 0 -> left, 1 -> right
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; ++i) {
			scanf("%d", arr + i);
			l[i] = r[i] = 1;
		}
		reverse(arr, arr + n);
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j) {
				if (arr[i] > arr[j])
					l[i] = max(l[i], l[j] + 1);
				else 
					r[i] = max(r[i], r[j] + 1);
			}
		}
		int ans = 0;
		for (int i = 0; i < n; ++i)
			ans = max(ans, l[i] + r[i] - 1);
		printf("%d\n", ans);
	}
	return 0;
}
