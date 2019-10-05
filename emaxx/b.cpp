#include <bits/stdc++.h>

#define N 1000005
using namespace std;

char s1[N], s2[N], c1[N], c2[N];
int lene1[N], lene2[N];
int main() {

	int n;
	scanf("%d", &n);
	while (n--) {
		scanf("%s%s", s1, s2);
		int l = 0, r = 0, len1 = strlen(s1), len2 = strlen(s2);
		bool poss = true;
		if (len1 > len2) {
			printf("NO\n");
			continue;
		}
		lene1[0] = 1;
		int e = 0;
		c1[0] = s1[0];
		for (int i = 1; i < len1; ++i) {
			if (s1[i] == s1[i - 1])
				lene1[e]++;
			else {
				c1[++e] = s1[i];
				lene1[e] = 1;
			}
		}
		c1[e+1] = '\0';
		lene2[0] = 1;
		e = 0;
		c2[0] = s2[0];
		for (int i = 1; i < len2; ++i) {
			if (s2[i] == s2[i - 1])
				lene2[e]++;
			else {
				c2[++e] = s2[i];
				lene2[e] = 1;
			}
		}
		c2[e+1] = '\0';
		len1 = strlen(c1), len2 = strlen(c2);
		if (len1 != len2)
			poss = false;
		else {
			for (int i = 0, j = 0; i < len1; ++i, j++) {
				if(c1[i] != c2[j]) {
					poss = false;
					break;				
				}
				else if (lene1[i] > lene2[j]) {
					poss = false;
					break;
				}
			}
		}
		if (poss)
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}
