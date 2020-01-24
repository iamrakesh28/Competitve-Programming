#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

//#define debug
using namespace std;

const int size = 2e6 + 1;

int p[size], pn[size], cnt[size], lcp[size], c[size][20], ran[size];
char s[size], A[size], B[size];
int order(char c) {

	switch(c) {
		case '#' : return 0;
		case '-' : return 1;
		case '~' : return 2;
		case '^' : return 3;
		default : return 4;
	}
}

int suffix(int n, int a) {

	//cout<<s<<" "<<n<<endl;
	for (int i = 0; i < n; ++i)
		cnt[order(s[i])]++;
	for (int i = 1; i < 5; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < n; ++i)
		p[--cnt[order(s[i])]] = i;
	int classes = 1;
	c[p[0]][0] = 0;
	for (int i = 1; i < n; ++i) {
		if (s[p[i]] != s[p[i - 1]])
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
		for (int i = n - 1; i >= 0; --i)
			p[--cnt[c[pn[i]][h]]] = pn[i];
		c[p[0]][h + 1] = 0;
		classes = 1;
		for (int i = 1; i < n; ++i) {
			pair <int, int> cur = {c[p[i]][h], c[(p[i] + (1 << h)) % n][h]};
			pair <int, int> prev = {c[p[i - 1]][h], c[(p[i - 1] + (1 << h)) % n][h]};
			if (cur != prev)
				classes++;
			c[p[i]][h + 1] = classes - 1;
		}
	}
	//cout<<s<<endl;
	/*
	for (int i = 0; i < n; ++i) {
		cout<<p[i]<<" ";
		for (int j = p[i]; j < n; ++j)
			cout<<s[j];
		cout<<endl;
	}
	
	int log_n = ceil(log2(n));
	for (int i = 2; i < n; ++i) {
		int a = p[i], b = p[i - 1], len = 0;
		//cout<<c[4][0]<<" "<<c[17][0]<<endl;
		for (int k = log_n; k >= 0; k--)
			if (c[a][k] == c[b][k]) {
				len += (1 << k);
				a += (1 << k);
				a = a % n;
				b += (1 << k);
				b = b % n;
			}
		lcp[i - 1] = len;
		//cout<<len<<endl;
	}*/
	for (int i = 0; i < n; i++)
        ran[p[i]] = i;

    int k = 0;
    for (int i = 0; i < n; i++) {
        if (ran[i] == n - 1) {
            k = 0;
            continue;
        }
        int j = p[ran[i] + 1];
        while (i + k < n && j + k < n && s[i+k] == s[j+k])
            k++;
        lcp[ran[i]] = k;
        if (k)
            k--;
    }
	int ans = 0;
	for (int i = 2; i < n - 1; ++i) {
		//cout<<lcp[i]<<" "<<p[i]<<" "<<p[i + 1]<<endl;
		if (p[i] < a && p[i + 1] > a || p[i] > a && p[i + 1] < a)
			ans = max(ans, lcp[i]);
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef debug
    	freopen("testcase", "r", stdin);
	#endif
	int a = 0, i;
	char ch;
	while ((ch = getchar_unlocked()) != '\n')
		s[a++] = ch;
	//scanf("%s%s", s, B);
	s[a] = '#';
	i = a + 1;
	while ((ch = getchar_unlocked()) != '\n')
		s[i++] = ch;
	s[i++] = '#';
	s[i] = '\0';
	int ans = suffix(i, a);
	printf("%d\n", ans);
	return 0;
}
