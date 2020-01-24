#include <iostream>
#include <algorithm>
#include <stack>
#include <cstring>

//#define debug
using namespace std;

const int N = 2e5 + 5, alphabet = 27;

char s[N], b[N];
int c[N], cn[N], p[N], pn[N], lcp[N], cnt[N], ran[N], sum[N], L[N], R[N];

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

	int k = 0;
	for (int i = 0; i < n; ++i)
		ran[p[i]] = i;
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
	stack <pair <int, int>> start, end;
	for (int i = 1; i < n - 1; ++i) {
		while (!start.empty() && start.top().first >= lcp[i])
				start.pop();
		if (start.empty())
			L[i] = 1;
		else
			L[i] = start.top().second + 1;
		start.push({lcp[i], i});
		//cout<<"L : "<<L[i]<<endl;
	}
	for (int i = n - 2; i > 0; --i) {
		while (!end.empty() && end.top().first >= lcp[i])
				end.pop();
		if (end.empty())
			R[i] = n - 2;
		else
			R[i] = end.top().second - 1;
		end.push({lcp[i], i});
		//cout<<"R : "<<R[i]<<endl;
	}
}

long long solve(int n) {
	long long ans = 0, temp;
	for (int i = 1; i < n - 1; ++i) {
		int len = R[i] - L[i] + 2 - sum[R[i] + 2] + sum[L[i]];
		temp = (long long)len * lcp[i];
		//cout<<lcp[i]<<" "<<len<<" "<<sum[R[i] + 2] - sum[L[i]]<<endl;
		ans = max(ans, temp);
	}
	temp = n - 1;
	if (b[0] != '1')
		ans = max(ans, temp);
	return ans;
}

int main() {

	#ifdef debug
		freopen("testcase", "r", stdin);
	#endif

	int n;
	scanf("%d%s%s", &n, s, b);
	reverse(s, s + n);
	reverse(b, b + n);
	s[n++] = '`';
	s[n] = '\0';
	suffix(n);
	lcp_cons(n);
	sum[1] = 0;
	for (int i = 1; i < n; ++i)
		sum[i + 1] = sum[i] + b[p[i]] - '0';
	cout<<solve(n)<<endl;
	return 0;
}
