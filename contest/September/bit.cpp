#include <iostream>

using namespace std;

const int N = 1e5 + 5;
char s[N];
int digit[10], cnt[10];
bool rem[10];

int main() {

	int n, pos = 0, req = 0;
	scanf("%d%s", &n, s);
	for (int i = 0; i < n; ++i)
		digit[s[i] - '0']++;
	for (int i = 0; i < 10; ++i) {
		if (digit[i] & 1)
			rem[i] = true, req++;
		else
			rem[i] = false;
		if (digit[i] > 1)
			pos = 1;
	}
	if (pos == 0) {
		puts("-1");
		return 0;
	}
	if (req == 0) {
		puts("0");
		return 0;
	}
	int l = 0, r = 0, ans = N, num = 0;
	for (int i = 0; i < n; ++i) {
		if (rem[s[i] - '0'] == false)
			continue;
		if (cnt[s[i] - '0'] == 0)
			num++;
		cnt[s[i] - '0']++;
		while (cnt[s[l] - '0'] > 1 || rem[s[l] - '0'] == false) {
			if (cnt[s[l] - '0'] > 1)
				cnt[s[l] - '0']--;
			l++;
		}
		if (req == num)
			ans = min(ans, i - l);
	}
	printf("%d\n", ans);
	return 0;
}
