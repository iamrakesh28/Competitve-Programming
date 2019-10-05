#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

char s[1000005];
vector <int> pi;

void KMP(int n) {

	pi[0] = 0;
	for (int i = 1; i < n; ++i) {
		int j = pi[i - 1];
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		pi[i] = j;
	}
}

int solve(int n) {
	int ans = 1, j = 0;
	for (int i = n - 1; i >= 0; i--) {
		while (j > 0 && s[i] != s[j])
			j = pi[j - 1];
		if (s[i] == s[j])
			j++;
		ans = max(ans, j);
	}
	return ans;
}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		scanf("%s", s);
		int n = strlen(s);
		pi.resize(n);
		int ans = solve(n);
		for (int i = ans - 1; i >= 0; i--)
			putchar(s[i]);
		puts("");
	}
	return 0;
}
