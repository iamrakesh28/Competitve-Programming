#include <iostream>
#include <cstring>
#include <vector>
#include <set>

using namespace std;

char s[1000001];

int main() {
	
	scanf("%s", s);
	int n = strlen(s);
	vector <int> z(n, 0);
	for (int i = 1, l = 0, r = 0; i < n; ++i) {
		if (i <= r)
			z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && s[z[i]] == s[i + z[i]])
			++z[i];
		if (i + z[i] - 1 > r)
			l = i, r = i + z[i] - 1;
	}
	int ans = -1, mx = 0;
	for (int i = 1; i < n; ++i) {
		if (i + z[i] < n)
			mx = max(mx, z[i]);
		else
			mx = max(mx, z[i] - 1);
	}
	for (int i = 1; i < n; ++i) {
		if (i + z[i] == n && mx >= z[i])
			ans = max(ans, z[i]);
	}
	if (ans != -1) {
		s[ans] = '\0';
		printf("%s\n", s);
	}
	else
		puts("Just a legend");
	return 0;
}
