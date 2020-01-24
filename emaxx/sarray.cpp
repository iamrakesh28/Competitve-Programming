#include <iostream>
#include <cstring>

//#define debug
using namespace std;

const int N = 1e5 + 5, alphabet = 256;

char s[N];
int c[N], cn[N], p[N], pn[N], cnt[N];

void suffix(int n) {
	
	for (int i = 0; i < n; ++i)
		cnt[s[i]]++;
	for (int i = 1; i < alphabet; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[--cnt[s[i]]] = i;
	int classes = 1;
	c[p[0]] = 0;
	for (int i = 1; i < n; ++i) {
		if (s[p[i]] != s[p[i - 1]])
			++classes;
		c[p[i]] = classes - 1;
	}

	for (int h = 0; (1 << h) <  n; ++h) {
		for (int i = 0; i < n; ++i) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0)
				pn[i] += n;
		}
		for (int i = 0; i < classes; ++i)
			cnt[i] = 0;
		for (int i = 0; i < n; ++i)
			cnt[c[pn[i]]]++;
		for (int i = 1; i < classes; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = n - 1; i >= 0; i--)
			p[--cnt[c[pn[i]]]] = pn[i];
		classes = 1;
		cn[p[0]] = 0;
		for (int i = 1; i < n; ++i) {
			pair <int, int> cur = {c[p[i]], c[(p[i] + (1 << h)) % n]};
			pair <int, int> prev = {c[p[i - 1]], c[(p[i - 1] + (1 << h)) % n]};
			if (cur != prev)
				++classes;
			cn[p[i]] = classes - 1;
		}
		for (int i = 0; i < n; ++i)
			c[i] = cn[i];
	}
	for (int i = 1; i < n; ++i) {
		printf("%d\n", p[i]);
	}
	return;
}

int main() {
	
	#ifdef debug
		freopen("testcase", "r", stdin);
	#endif

	scanf("%s", s);
	int n = strlen(s);
	s[n++] = '#';
	s[n] = '\0';
	suffix(n);
	return 0;
}
