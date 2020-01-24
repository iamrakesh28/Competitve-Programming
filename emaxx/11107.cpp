#include <iostream>
#include <cstring>
#include <vector>
#include <deque>
#include <cmath>

//#define debug

using namespace std;

const int N = 2e5 + 5, alphabet = 27;

char s[N];
int cnt[N], p[N], pn[N], c[N], cn[N], lcp[N], ran[N], pos[N], pres[105];

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
	
	int n, k = 0;
	while(scanf("%d", &n) != EOF && n) {
		char ch = getchar_unlocked();
		int l = 0;
		for (int i = 0; i < n; ++i) {
			while ((ch = getchar()) != '\n')
				s[l++] = ch, pos[l - 1] = i;
			s[l++] = '`';
			pos[l - 1] = i;
			pres[i] = 0;
		}
		s[l] = '\0';
		if (n == 1) {
			s[l - 1] = '\0';
			printf("%s\n\n", s);
			continue;
		}
		//cout<<s<<endl;
		suffix(l);
		lcp_cons(l);
		int ans = 0, cnt = 1, left = n, half = n / 2 + 1;
		pres[pos[p[left]]]++;
		deque <pair <int, int>> q;
		vector <int> v;
		for (int i = n; i < l - 1; ++i) {
			if (pres[pos[p[i + 1]]] == 0)
				cnt++;
			pres[pos[p[i + 1]]]++;
			while (cnt >= half) {
				if (pres[pos[p[left]]] > 1 || cnt > half)
					pres[pos[p[left++]]]--;
				else
					break;
				if (pres[pos[p[left - 1]]] == 0)
					cnt--;
				pair <int, int> p= {lcp[left - 1], left - 1};
				if (!q.empty() && q.front() == p)
					q.pop_front();
			}
			while (!q.empty() && q.back().first >= lcp[i])
				q.pop_back();
			q.push_back({lcp[i], i});
			if (cnt >= half) {
				//cout<<left<<" "<<i<<" "<<q.front().first<<endl;
				if (ans == q.front().first && ans) {
					if (v[v.size() - 1] == i - 1)
						v[v.size() - 1] = i;
					else
						v.push_back(i);
				}
				else if (ans < q.front().first) {
					ans = q.front().first;
					v.clear();
					v.push_back(i);
				} 
			}
			//cout<<left<<" "<<i+1<<" "<<lcp[i]<<" "<<cnt<<" "<<q.front().first<<endl;
		}
		if (k++)
			puts("");
		if (ans == 0)
			puts("?");
		else {
			for (int it : v) {
				for (int i = 0; i < ans; ++i)
					putchar(s[i + p[it]]);
				puts("");
			}
		}
	}
	return 0;
}
