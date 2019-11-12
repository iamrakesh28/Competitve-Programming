#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 5;
int mons[N];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, r, shot = 1, prev;
		long long move;
		scanf("%d%d", &n, &r);
		move = r;
		for (int i = 0; i < n; ++i)
			scanf("%d", mons + i);
		sort(mons, mons + n);
		prev = mons[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (prev == mons[i])
				continue;
			prev = mons[i];
			if (mons[i] - move > 0) {
				shot++;
				move += r;
			}
		}
		printf("%d\n", shot);
	}
	return 0;
}
