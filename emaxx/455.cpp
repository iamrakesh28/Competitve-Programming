#include <iostream>
#include <cstring>

using namespace std;

int main() {
	char s[100];
	int q, z[100], i = 0;
	scanf("%d", &q);
	while (q--) {
		if (i++)
			puts("");
		scanf("%s", s);
		int n = strlen(s);
		memset(z, 0, sizeof(int) * n);
		for (int i = 1, l = 0, r = 0; i < n; ++i) {
			if (i <= r)
				z[i] = min(z[i - l], r - i + 1);
			while (i + z[i] < n && s[z[i]] == s[i + z[i]])
				++z[i];
			if (z[i] + i - 1 > r)
				l = i, r = z[i] + i - 1;
		}
		int ans = n;
		for (int i = 1; i < n; ++i)
			if (i + z[i] == n && n % i == 0) {
				ans = i;
				break;
			}
		printf("%d\n", ans);
	}
	return 0;
}
