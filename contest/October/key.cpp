#include <iostream>

using namespace std;

const int N = 505;
char s[N];
bool alph[26];

int main() {

	int t;
	scanf("%d", &t);
	char ch = getchar();
	while (t--) {
		int n = 0, len = 0;
		for (int i = 0; i < 26; ++i)
			alph[i] = false;
		while ((ch = getchar()) != '\n')
			s[n++] = ch;
		len = 1;
		for (int i = 1; i < n; ++i) {
			if (s[i] != s[i - 1]) {
				if (len & 1)
					alph[s[i - 1] - 'a'] = true;
				len = 1;
			}
			else
				len++;
		}
		if (len & 1)
			alph[s[n - 1] - 'a'] = true;
		for (int i = 0; i < 26; ++i)
			if (alph[i])
				putchar(i + 'a');
		puts("");
	}
	return 0;
}
