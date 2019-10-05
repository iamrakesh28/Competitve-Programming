#include <iostream>
#include <cstring>
#include <deque>
#include <vector>

//#define debug

using namespace std;

const int N = 7e6, alphabet = 256;

char s[N];
int cnt[N], p[N], pn[N], c[N], cn[N], lcp[N], ran[N], str[8], loc[N];

void suffix(int n) {
	
	for (int i = 0; i < alphabet; ++i)
		cnt[i] = 0;
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
}


int main() {

	#ifdef debug
		freopen("testcase", "r", stdin);
		freopen("out", "w", stdout);
	#endif

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, len = 0;
		scanf("%d", &n);
		char ch = getchar_unlocked();
		for (int i = 0; i < n; ++i) {
			while ((ch = getchar_unlocked()) != '\n') {
				s[len++] = ch;
				loc[len - 1] = i;
			}
			s[len++] = 'A' - (i + 1);
			loc[len - 1] = i;
		}
		s[len] = '\0';
		suffix(len);
		lcp_cons(len);
		for (int i = 0; i < n; ++i)
			str[i] = 0;
		deque <pair <int, int>> st;
		int num = 1, ans = 0, l = n, pos2 = loc[p[l]];
		str[pos2]++;
		//cout<<s<<endl;
		for (int i = n + 1; i < len; ++i) {
			int pos1 = loc[p[i]];
			if (str[pos1] == 0)
				num++;
			str[pos1]++;
			//cout<<i<<" "<<l<<" "<<pos1<<" "<<pos2<<" "<<lcp[i]<<endl;
			while (!st.empty() && st.back().first >= lcp[i - 1])
				st.pop_back();
			st.push_back({lcp[i - 1], i - 1});
			//st.insert({lcp[i - 1], i - 1});
			while (str[pos2] > 1) {
				str[pos2]--;
				//st.erase(st.loc({lcp[l], l}));
				pair <int, int> it = {lcp[l], l};
				if (!st.empty() && st.front() == it)
					st.pop_front();
				//cout<<lcp[l]<<" "<<l<<endl;
				l++;
				pos2 = loc[p[l]];
			} 
			if (num == n)
				ans = max(ans, st.front().first);
		}
		printf("%d\n", ans);
		//cout<<s<<endl;
	}
	return 0;
}
