#include <iostream>

using namespace std;

const int prime = 1e9 + 7;
char s[200001];

int main() {

	char *p;
	scanf("%s", s);
	p = s;
	long long ans = 0, prev = 0;
	int len = 1;
	while (*p != '\0') {
		prev = (prev * 10 + (*p - '0') * len) % prime;
		p++;
		len++;
		ans = (ans + prev) % prime;
	}
	printf("%lld\n", ans);
	return 0;
}
