#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int main() {

	int q;
	scanf("%d", &q);
	char s[2001];
	vector <int> pi;
	while (q--) {
		scanf("%s", s);
		int n = strlen(s), ans;
		pi.resize(n);
		pi[0] = 0;
		for (int i = 1; i < n; ++i) {
			int j = pi[i - 1];
			while (j > 0 && s[i] != s[j])
				j = pi[j - 1];
			if (s[i] == s[j])
				j++;
			pi[i] = j;
			int l = i + 1;
			if (l % (l - j) == 0) {
				if (l == ((l - j) << 1))
					ans = j;
			}
		}
		int rem = n - 2 * ans;
		for (int i = 0; i < 8; ++i)
			putchar(s[(rem + i) % ans]);
		puts("...");
	}
	return 0;
}
