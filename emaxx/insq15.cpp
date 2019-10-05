#include <iostream>
#include <cstring>
#include <vector>

#define N 5000005
using namespace std;

const int p = 31, m = 1e9 + 9;
char S[N];
vector <long long> power, has;

int solve(int len, int p) {

	int beg = 0, end = p - 1, mid, ans = 0;
	while (beg <= end) {
		mid = (beg + end) >> 1;
		long long cur;
		if (p + mid + 1 > len) {
			end = mid - 1;
			continue;
		}
		cur = (has[p + mid + 1] - has[p] + m) % m;
		if (has[mid + 1] * power[p] % m == cur) {
			ans = mid + 1;
			beg = mid + 1;
		}
		else
			end = mid - 1;
	}
	return ans;
}

int main() {
	int q, len;
	scanf("%s%d", S, &q);
	len = strlen(S);
	power.resize(len);
	has.resize(len + 1);
	power[0] = 1;
	for (int i = 1; i < len; ++i)
		power[i] = (power[i - 1] * p) % m;
	has[0] = 0;
	for (int i = 0; i < len; ++i)
		has[i + 1] = (has[i] + (S[i] - 'a' + 1) * power[i]) % m;
	while (q--) {
		int p;
		scanf("%d", &p);
		printf("%d\n", solve(len, p));
	}
}
