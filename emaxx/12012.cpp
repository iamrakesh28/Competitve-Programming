#include <iostream>
#include <cstring>
#include <vector>

#define N 1005
using namespace std;

char cd[N];
const int p = 31, m = 1e9 + 9;
vector <long long> hs, power1, hsS2, hsT2, power2;

int solve(int S, int T, int n) {

	int beg = 0, end = S - 1, mid, ans = -1;
	while (beg <= end) {
		mid = (beg + end) >> 1;
		int cnt = 0;
		pair <long long, long long> a, b;
		long long cur1, cur2;
		for (int i = 0; i + mid < T; ++i) {
			cur1 = (hsT1[i + mid + 1] - hsT1[i] + m1) % m1;
			cur2 = (hsT2[i + mid + 1] - hsT2[i] + m2) % m2;
			a = {hsS1[mid + 1] * power1[i] % m1, hsS2[mid + 1] * power2[i] % m2};
			b = {cur1, cur2};
			if (a == b)
				cnt++;
		}
		if (cnt >= n) {
			ans = mid;
			beg = mid + 1;
		}
		else
			end = mid - 1;
	}
	return ans;
}
int main() {

	int S, T, n;
	char c;
	scanf("%[^\n]s", A);
	c = getchar();
	scanf("%[^\n]s", B);
	scanf("%d", &n);
	S = strlen(B), T = strlen(A);
	power1.resize(T);
	hsS1.resize(S + 1);
	hsT1.resize(T + 1);
	power2.resize(T);
	hsS2.resize(S + 1);
	hsT2.resize(T + 1);
	power2[0] = power1[0] = 1;

	for (int i = 1; i < T; ++i) {
		power1[i] = (power1[i - 1] * p1) % m1;
		power2[i] = (power2[i - 1] * p2) % m2;
	}
	hsS1[0] = 0, hsT1[0] = 0;
	hsS2[0] = 0, hsT2[0] = 0;
	for (int i = 0; i < S; ++i) {
		hsS1[i + 1] = (hsS1[i] + (B[i] - 'a' + 1) * power1[i]) % m1;
		hsS2[i + 1] = (hsS2[i] + (B[i] - 'a' + 1) * power2[i]) % m2;
	}
	for (int i = 0; i < T; ++i) {
		hsT1[i + 1] = (hsT1[i] + (A[i] - 'a' + 1) * power1[i]) % m1;
		hsT2[i + 1] = (hsT2[i] + (A[i] - 'a' + 1) * power2[i]) % m2;
	}
	int ans = solve(S, T, n);
	if (ans == -1)
		puts("IMPOSSIBLE");
	else {
		B[ans + 1] = '\0';
		printf("%s\n", B);
	}
	return 0;
}
