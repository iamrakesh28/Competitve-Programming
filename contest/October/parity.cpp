#include <iostream>

using namespace std;

const int N = 3e5 + 5;
char s[N];
char even[N], odd[N];

int main() {
	int t;
	scanf("%d", &t);
	char ch = getchar();
	while (t--) {
		int e = 0, o = 0, n = 0;
		while ((ch = getchar()) != '\n') {
			if ((ch - '0') & 1)
				odd[o++] = ch;
			else
				even[e++] = ch;
			n++;
		}
		int i = 0, j = 0;
		while (i < e && j < o) {
			int l = even[i] - '0', r = odd[j] - '0';
			if (l < r)
				putchar(even[i++]);
			else
				putchar(odd[j++]);
		}
		while (i < e)
			putchar(even[i++]);
		while (j < o)
			putchar(odd[j++]);
		puts("");
	}
	return 0;
}
