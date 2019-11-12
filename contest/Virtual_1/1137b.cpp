#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e5 + 5;
int pi[N];
char s[N], t[N];

void prefix(int n) {
	pi[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && t[i] != t[j])
			j = pi[j - 1];
		if (t[i] == t[j])
			j++;
		pi[i] = j;
	}
}

int main() {

	int zs = 0, os = 0, zt = 0, ot = 0;
	scanf("%s%s", s, t);
	char *c = s;
	int T;
	while (*c != '\0') {
		if (*c == '1')
			os++;
		else
			zs++;
		c++;
	}
	c = t;
	while (*c != '\0') {
		if (*c == '1')
			ot++;
		else
			zt++;
		c++;
	}
	prefix(zt + ot);
	T = zt + ot;
	if (zt > zs || ot > os) {
		puts(s);
		return 0;
	}
	for (int i = 0; i < zt + ot; ++i)
		putchar(t[i]);
	//cout<<pi[zt + ot - 1]<<endl;
	os -= ot;
	zs -= zt;
	for (int i = 0; i < pi[T - 1]; ++i)
		if (t[i] == '0')
			zt--;
		else
			ot--;
	//cout<<zt<<" "<<ot<<endl;
	while (zt <= zs && ot <= os) {
		for (int i = pi[T - 1]; i < T; ++i)
			putchar(t[i]);
		os -= ot;
		zs -= zt;
	}
	while (zs--)
			putchar('0');
	while (os--)
			putchar('1');
	puts("");
	return 0;
}
