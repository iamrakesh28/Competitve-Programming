#include <iostream>

using namespace std;

char s[105], t[105];

int main() {

	int q;
	scanf("%d", &q);
	char ch = getchar();
	while (q--) {
		int alph1[26], alph2[26], pos = 0;
		for (int i = 0; i < 26; ++i)
			alph1[i] = alph2[i] = 0;
		while ((ch = getchar()) != '\n')
			alph1[ch - 'a']++;
		while ((ch = getchar()) != '\n')
			alph2[ch - 'a']++;
		for (int i = 0; i < 26; ++i)
			if (alph1[i] && alph2[i]) {
				pos = 1;
				break;
			}
		if (pos)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
