#include <bits/stdc++.h>

using namespace std;

int col[105];

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, m, k, poss = 1;
		scanf("%d%d%d", &n, &m, &k);
		for (int i = 0; i < n; ++i)
			scanf("%d", col + i);
		if (n == 1) {
			puts("YES");
			continue;
		}
		for (int i = 0; i < n - 1; ++i) {
			if (abs(col[i] - col[i + 1]) <= k) {
				if (col[i + 1] <= col[i]) {
					m = m + abs(col[i] - col[i + 1]);
					if (col[i + 1] >= k)
						m = m + k;
					else
						m = m + col[i + 1];
				}
				else
					m = m + min(k - abs(col[i] - col[i + 1]), col[i]);
			}
			else {
				if (col[i + 1] < col[i]) {
					m = m + abs(col[i] - col[i + 1]); 
					if (col[i + 1] >= k)
						m = m + k;
					else
						m = m + col[i + 1];
				}
				else	
					m = m + k - abs(col[i] - col[i + 1]);
				if (m < 0)
					poss = 0;
				//cout<<m<<" "<<i<<" ";
			}
		}
		if (poss)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
