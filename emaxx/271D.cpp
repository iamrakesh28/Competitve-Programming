#include <iostream>
#include <cstring>
#include <vector>
#include <set>

#define N 1505
using namespace std;

char s[N];
int alph[26], prefix[N];

int solve(int k, int len) {
	
	const int p = 31, m = 1e9 + 9;
	vector <long long> power(len), hash(len + 1, 0);
	power[0] = 1;
	for (int i = 1; i < len ; ++i)
		power[i] = (power[i - 1] * p) % m;
	for (int i = 0; i < len; ++i)
		hash[i + 1] = (hash[i] + (s[i] - 'a' + 1) * power[i]) % m;
	int ans = 0;
	for (int i = 1; i <= len; ++i) {
		set <long long> q;
		for (int j = 0; j + i - 1 < len; ++j) {
			if (prefix[j + i] - prefix[j] <= k) {
				long long h = (hash[i + j] - hash[j] + m) % m;
				h = (h * power[len - j - 1]) % m;
				q.insert(h);
			}
		}
		ans += q.size();
	}
	return ans;
}
int main() {

	int i = 0, k, len;
	scanf("%s", s);
	char c = getchar();
	while ((c = getchar()) != '\n')
		alph[i++] = c - '0';
	scanf("%d", &k);
	len = strlen(s);
	prefix[0] = 0;
	for (i = 0; i < len; ++i)
		if (alph[s[i] - 'a'] == 0)
			prefix[i + 1] = prefix[i] + 1;
		else
			prefix[i + 1] = prefix[i];
	printf("%d\n", solve(k, len));
	return 0;
}
