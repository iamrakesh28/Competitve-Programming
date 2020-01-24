#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

const int N = 2e5 + 1, alphabet = 27;
char s[N];
int p[N], c[N][18], pn[N], cnt[N], lcpref[N];

void suffix(int n) {

	for (int i = 0; i < max(alphabet, n); ++i)
		cnt[i] = 0;
	for (int i = 0; i < n; ++i)
		cnt[s[i] - '`']++;
	for (int i = 1; i < n; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[--cnt[s[i] - '`']] = i;
	c[p[0]][0] = 0;
	int classes = 1;
	for (int i = 1; i < n; ++i) {
		if (s[i] != s[i - 1])
			classes++;
		c[p[i]][0] = classes - 1;
	}
	for (int h = 0; (1 << h) < n; ++h) {
		for (int i = 0; i < n; ++i) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0)
				pn[i] += n;
		}
		for (int i = 0; i < classes; ++i)
			cnt[i] = 0;
		for (int i = 0; i < n; ++i)
			cnt[c[pn[i]][h]]++;
		for (int i = 1; i < classes; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]][h]]] = pn[i];
		c[p[0]][h] = 0;
		classes = 1;
		for (int i = 1; i < n; ++i) {
			pair <int, int> cur = {c[p[i]][h], c[(p[i] + (1 << h)) % n][h]};
			pair <int, int> prev = {c[p[i - 1]][h], c[(p[i - 1] + (1 << h)) % n][h]};
			if (cur != prev)
				++classes;
			c[i][h] = classes - 1;
		}
	}
}

void lcp(int n) {

	for (int i = 2; i < n; ++i) {
		int a = i, b = i - 1, ans = 0;
		int log_n = ceil(log2(n));
		for (int j = log_n; i >= 0; i--)
			if (c[a][j] == c[b][j]) {
				a += (1 << j);
				b += (1 << j);
				ans += (1 << j);
			}
		lcpref[i - 1] = ans;
	}
}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int q, n;
		long long ans = 0;
		scanf("%s%d", s, q);
		n = strlen(s);
		s[n] = '`';
		s[++n] = '\0';
		suffix(n);
		lcp(n);
		int prev = 1, v = lcpref[prev];
		for (int i = 2; i < n; ++i) {
			
		}
	}
	return 0;
}
