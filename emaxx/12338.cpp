#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>

//#define debug

using namespace std;

const int N = 2e6, alphabet = 27, maxn = 20;

char s[N];
int cnt[N], p[N], pn[N], c[N], cn[N], lcp[N], ran[N], st[N][maxn], pres[N], logn[N + 1];

void suffix(int n) {
	
	for (int i = 0; i < alphabet; ++i)
		cnt[i] = 0;
	for (int i = 0; i < n; ++i)
		cnt[s[i] - '`']++;
	for (int i = 1; i < alphabet; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[--cnt[s[i] - '`']] = i;
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
	/*
	for (int i = 0 ; i < n; ++i) {
		for (int j = p[i]; j < n; ++j)
			cout<<s[j];
		cout<<endl;
	}
	*/
	return;
}

void lcp_cons(int n) {

	for (int i = 0; i < n; ++i)
		ran[p[i]] = i;
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (ran[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = p[ran[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k] && s[i + k] != '`')
			++k;
		lcp[ran[i]] = k;
		if (k)
			k--;
	}
	
}


int main() {

	#ifdef debug
		freopen("testcase", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	
	int q, n;
	scanf("%d", &q);
	logn[1] = 0;
	for (int i = 2; i <= N; ++i)
		logn[i] = logn[i / 2] + 1;

	for (int k = 0; k < q; ++k) {
		scanf("%d", &n);
		char ch = getchar_unlocked();
		int l = 0, t;
		for (int i = 0; i < n; ++i) {
				pres[i] = l;
			while ((ch = getchar()) != '\n')
				s[l++] = ch;
			s[l++] = '`';
		}
		s[l] = '\0';
		suffix(l);
		lcp_cons(l);
		scanf("%d", &t);
		printf("Case %d:\n", k + 1);

		// sparse table
		for (int i = 0; i < l - 1; ++i)
			st[i][0] = lcp[i];

		for (int j = 1; j <= maxn; ++j)
			for (int i = 0; i + (1 << j) <= l - 1; ++i)
				st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
		while (t--) {
			int L, R, j, temp;
			scanf("%d%d", &L, &R);
			L--, R--;
			if (L == R) {
				if (L < n - 1)
					printf("%d\n", pres[L + 1] - pres[L] - 1);
				else
					printf("%d\n", l - pres[L] - 1);	
				continue;
			}

			L = ran[pres[L]];
			R = ran[pres[R]];
			temp = L;
			L = min(L, R);
			R = max(temp, R);
			R--;
			//cout<<L<<" "<<R<<endl;
			j = logn[R - L + 1];
			int minm = min(st[L][j], st[R - (1 << j) + 1][j]);
			printf("%d\n", minm);
		}
	}
	return 0;
}
