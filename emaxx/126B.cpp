#include <iostream>
#include <vector>
#include <cstring>

#define N 1000005
using namespace std;

char s[N];
const int p = 31, m = 1e9 + 9;

bool poss(int n, long long hash, int len, vector <long long> & power, vector <long long> & h_s) {

	for (int i = 1; i + len - 1 < n - 1; ++i) {
		long long cur = (h_s[i + len] - h_s[i] + m) % m;
		cur = cur * power[n - i - 1] % m;
		if (cur == hash)
			return true;
	}
	return false;
}
void solve(int n) {

	vector <long long> power(n), h_s(n + 1, 0);
	power[0] = 1;
	for (int i = 1; i < n; ++i)
		power[i] = power[i - 1] * p % m;
	for (int i = 0; i < n; ++i)
		h_s[i + 1] = (h_s[i] + (s[i] - 'a' + 1) * power[i]) % m;
	long long pre, suf;
	vector <pair <int, long long>> q;
	for (int i = 0; i < n; ++i) {
		pre = h_s[i + 1] % m;
		suf = (h_s[n] - h_s[n - i - 1] + m) % m;
		pre = pre * power[n - 1] % m;
		suf = suf * power[i] % m;
		if (pre == suf)
			q.push_back({i + 1, suf});
	}
	int beg = 0, end = q.size() - 1, mid, ans = -1;
	while (beg <= end) {
		mid = (beg + end) >> 1;
		auto it = poss(n, q[mid].second, q[mid].first, power, h_s);
		if (it) {
			beg = mid + 1;
			ans = q[mid].first;
		}
		else
			end = mid - 1;
	}
	if (ans == -1) {
		printf("Just a legend\n");
		return;
	}
	s[ans] = '\0';
	printf("%s\n", s);
	return;
}
int main() {

	scanf("%s", s);
	int n = strlen(s);
	solve(n);
	return 0;
}
