#include <iostream>
#include <cstring>
#include <stack>

#define debug

using namespace std;

const int N = 4e5 + 5, alphabet = 27;

char s[N];
int cnt[N], p[N], pn[N], c[N], cn[N], lcp[N], ran[N], L[N], R[N], mx[N];

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
		while (i + k < n && j + k < n && s[i + k] == s[j + k])
			++k;
		lcp[ran[i]] = k;
		if (k)
			k--;
	}
	stack <pair<int, int>> s;
	for (int i = 1; i < n - 1; ++i) {
		mx[i] = max(p[i], p[i + 1]);
		while (!s.empty() && s.top().first >= lcp[i]) {
			int ind = s.top().second;
			mx[i] = max(mx[i], p[ind]);			
			s.pop();
		}
		if (s.empty())
			L[i] = 1;
		else
			L[i] = s.top().second + 1;
		s.push({lcp[i], i});
	}
	while (!s.empty())
		s.pop();

	for (int i = n - 2; i > 0; --i) {
		while (!s.empty() && s.top().first >= lcp[i]) {
			int ind = s.top().second;
			mx[i] = max(mx[i], p[ind]);			
			s.pop();
		}
		if (s.empty())
			R[i] = n - 2;
		else
			R[i] = s.top().second - 1;
		s.push({lcp[i], i});
	}
}


int main() {

	#ifdef debug
		freopen("testcase", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int m;
	while(scanf("%d", &m) != EOF && m) {
		int n = 0;
		scanf("%s", s);
		n = strlen(s);
		if (m == 1) {
			printf("%d %d\n", n, 0);
			continue;
		}
		s[n++] = '`';
		s[n] = '\0';
		//cout<<s<<endl;
		suffix(n);
		lcp_cons(n);
		long long occ, len = 0;
		int r;
		for (int i = 1; i < n - 1; ++i) {
			occ = R[i] - L[i] + 2;
			//cout<<occ<<" "<<lcp[i]<<" "<<p[i]<<" "<<p[i + 1]<<endl;
			if (occ >= m) {
				if (len < lcp[i])
					len = lcp[i], r = mx[i];
				else if (len == lcp[i])
					r = max(r, mx[i]);
			}
		}
		if (len == 0) {
			puts("none");
			continue;
		}
		printf("%d %d\n", len, r);
	}
	puts("");
	return 0;
}
