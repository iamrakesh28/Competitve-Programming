#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 5, prime = 1e9 + 7;
char s[N];
long long dp[N];

int main() {

	bool f = true;
	scanf("%s", s);
	int n = strlen(s);
	dp[0] = 1;
	for (int i = 0; i < n; ++i) {
		if (s[i] == 'w' || s[i] == 'm') {
			f = false;
			break;
		}
		if (s[i] == 'u') {
			if (i >= 1)
				if (s[i - 1] == 'u') {
					dp[i + 1] = (dp[i - 1] + dp[i]) % prime;
					continue;
				}
		}
		else if (s[i] == 'n') {
			if (i >= 1)
				if (s[i - 1] == 'n') {
					dp[i + 1] = (dp[i - 1] + dp[i]) % prime;
					continue;
				}
		}
		dp[i + 1] = dp[i];
	}
	if (f == false) {
		puts("0");
		return 0;
	}
	long long ans = dp[n];
	printf("%lld\n", ans);
	return 0;
}
