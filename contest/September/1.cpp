#include <iostream>

using namespace std;

long long arr[12];

int bit(int v) {
	for (int i = 0; i < 12; ++i) {
		if ((1 << i) == v)
			return i;
	}
}
int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 12; ++i)
			arr[i] = 0;
		for (int i = 0; i < n; ++i) {
			long long v;
			cin>>v;
			if (v > 2048)
				continue;
			arr[bit(v)]++;
		}
		int pos = 0;
		for (int i = 1; i < 12; ++i)
			arr[i] += arr[i - 1] / 2;
		if (arr[11])
			pos = 1;
		if (pos)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
