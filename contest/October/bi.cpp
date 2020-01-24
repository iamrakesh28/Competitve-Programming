#include <iostream>
#include <set>

using namespace std;

const int N = 1e5;
int arr[N], bi[N];

int main() {

	int n, sum = 0;
	scanf("%d", &n);
	set <int> tun;
	for (int i = 0; i < n; ++i)
		scanf("%d", arr + i);
	for (int i = 0; i < n; ++i) {
		int v;
		scanf("%d", &v);
		bi[v - 1] = i;
	}
	for (int i = 0; i < n; ++i) {
		auto it = tun.lower_bound(bi[arr[i] - 1]);
		if (it == tun.end()) {
			tun.insert(bi[arr[i] - 1]);
			continue;
		}
		sum += 1;
		tun.insert(bi[arr[i] - 1]);
		
	}
	printf("%d\n", sum);
	return 0;
}
