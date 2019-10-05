#include <iostream>
#include <cstring>

//#define debug
using namespace std;

const int N = 1e3 + 5, alphabet = 27;

char s[N];
int c[N], cn[N], p[N], pn[N], cnt[N], lcp[N], ran[N];

void suffix(int n) {
	
	for (int i = 0; i < alphabet; ++i)
		cnt[i] = 0;
	for (int i = 0; i < n; ++i)
		cnt[s[i] - '@']++;
	for (int i = 1; i < alphabet; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[--cnt[s[i] - '@']] = i;
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
		ran[p[i]] = i, lcp[i] = 0;	
	int k = 0;
	for (int i = 0; i < n; ++i) {
		if (ran[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = p[ran[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k])
			k++;
		lcp[ran[i]] = k;
		if (k)
			k--;
	}
	int ans = 0, ind, occ = 0;
	for (int i = 0; i < n - 1; ++i) {
		if (lcp[i] > ans) {
			ans = lcp[i];
			ind = i;
			occ = 2;
		}
		else if (lcp[i] == ans && ind + occ - 1 == i)
			occ++;
		//else
			//occ = 0;
		//v = max(v, occ);
	}
	if (ans) {
		int i = p[ind];
		for (int k = 0; k < ans; ++k)
			putchar(s[i + k]);
		printf(" %d\n", occ);
	}
	else
		puts("No repetitions found!");
	return;
}

int main() {
	
	#ifdef debug
		freopen("testcase", "r", stdin);
		freopen("out", "w", stdout);
	#endif
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int n = strlen(s);
		s[n++] = '@';
		s[n] = '\0';
		suffix(n);
		lcp_cons(n);
	}
	return 0;
}
