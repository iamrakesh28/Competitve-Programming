#include <iostream>
#include <cstring>

//#define debug
using namespace std;

const int N = 90005, alphabet = 27;

char s[N];
int c[N], cn[N], p[N], pn[N], lcp[N], cnt[N], ran[N];
long long sum[N];

void suffix(int n) {
	
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
		for (int i = 1; i < n; ++i)
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

	int k = 0;
	for (int i = 0; i < n; ++i)
		ran[p[i]] = i;
	for (int i = 0; i < n - 1; ++i) {
		if (ran[i] == n - 1) {
			k = 0;
			continue;
		}
		int j = p[ran[i] + 1];
		while (i + k < n && j + k < n && s[i + k] == s[j + k])
			++k;
		lcp[ran[i]] = k;
		if (k)
			k--;
	}
	
}

void solve(long long k, int n) {
	
	int beg = 1, end = n - 1, mid, ans = 1;
	while (beg <= end) {
		mid = (beg + end) >> 1;
		if (sum[mid] < k)
			beg = mid + 1;
		else {
			ans = mid;
			end = mid - 1;
		}
	}
	long long rem = k - sum[ans - 1], ind;
	ind = lcp[ans - 1] + rem;
	//cout<<ind<<endl;
	for (int i = p[ans]; i < ind + p[ans]; ++i)
		putchar(s[i]);
	puts("");
	return;
}

int main() {

	#ifdef debug
		freopen("testcase", "r", stdin);
	#endif

	int n, q;
	scanf("%s%d", s, &q);
	n = strlen(s);
	s[n++] = '`';
	s[n] = '\0';
	suffix(n);
	lcp_cons(n);
	sum[1] = n - p[1] - 1;
	for (int i = 2; i < n; ++i)
		sum[i] = sum[i - 1] + n - p[i] - lcp[i - 1] - 1;
	while (q--) {
		long long k;
		scanf("%ld", &k);
		solve(k, n);
	}
	return 0;
}
