#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int n = 5005, alpha = 27;
char s[n];
int p[n], c[n][14], cnt[n], pn[n];

int lcp(int t) {
	
	int log_n = ceil(log2(t)), ans = 0;
	for (int i = 1; i < t; ++i) {
		int a = p[i], b = p[i - 1], temp = 0;
		for (int k = log_n; k >= 0; k--) {
			//cout<<c[a][k]<<" "<<c[b][k]<<endl;
			if (c[a][k] == c[b][k]) {
				temp += 1 << k;
				a += 1 << k;
				b += 1 << k;
			}
		}
		ans = max(ans, temp);
	}
	return ans;
}

void cyclic_shift(int t) {

	for (int i = 0; i < alpha; ++i)
		cnt[i] = 0;
	for (int i = 0; i < t; ++i)
		cnt[s[i] - '`']++;
	for (int i = 1; i < alpha; ++i)
		cnt[i] += cnt[i - 1];
	for (int i = 0; i < t; ++i)
		p[--cnt[s[i] - '`']] = i;
	c[p[0]][0] = 0;
	int classes = 1;
	for (int i = 1; i < t; ++i) {
		if (s[p[i]] != s[p[i - 1]])
			classes++;
		c[p[i]][0] = classes - 1;
	}
	for (int h = 0; (1 << h) < t; ++h) {
		for (int i = 0; i < t; ++i) {
			pn[i] = p[i] - (1 << h);
			if (pn[i] < 0)
				pn[i] += t;
		}
		for (int i = 0; i < classes; ++i)
			cnt[i] = 0;
		for (int i = 0; i < t; ++i)
			cnt[c[pn[i]][h]]++;
		for (int i = 1; i < classes; ++i)
			cnt[i] += cnt[i - 1];
		for (int i = t - 1; i >= 0; i--)
			p[--cnt[c[pn[i]][h]]] = pn[i];
		c[p[0]][h + 1] = 0;
		classes = 1;
		for (int i = 1; i < t; ++i) {
			pair <int, int> cur = {c[p[i]][h], c[(p[i] + (1 << h)) % t][h]};
			pair <int, int> prev = {c[p[i - 1]][h], c[(p[i - 1] + (1 << h)) % t][h]};
			if (cur != prev)
				++classes;
			c[p[i]][h + 1] = classes - 1;
		}
	}
	//for (int i = 0; i < t; ++i)
	//	cout<<p[i]<<endl;
	return;
}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s", s);
		int t = strlen(s);
		s[t] = '`';
		s[t + 1] = '\0';
		//cout<<s<<endl;
		cyclic_shift(t + 1);
		printf("%d\n", lcp(t + 1));
	}
	return 0;
}

