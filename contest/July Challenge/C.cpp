#include <bits/stdc++.h>

#define N 105
using namespace std;

char s[N], p[N], t[N];

int main() {
	
	int q;
	int alph[26];
	scanf("%d", &q);
	while (q--) {
		int S, T, P;
		scanf("%s%s%s", s, t, p);
		for (int i = 0; i < 26; ++i)
			alph[i] = 0;
		S = strlen(s);
		T = strlen(t);
		P = strlen(p);
		if (S > T) {
			puts("NO");
			continue;
		}
		if (S == T) {
			if (strcmp(s, t) == 0)
				puts("YES");
			else
				puts("NO");
			continue;
		}
		for (int i = 0; i < P; ++i)
			alph[p[i] - 'a']++;
		int a = 0, b = 0, pos = 1;
		while (b < T) {
			if (a < S && s[a] == t[b])
				a++, b++;
			else {
				if (alph[t[b] - 'a']) {
					alph[t[b] - 'a']--;
					b++;
				}
				else {
					pos = 0;
					break;
				}
			}
			if (a < S && b == T) {
				pos = 0;
				break;
			}
		}
		if (pos)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
