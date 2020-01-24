#include <iostream>

using namespace std;

const int N = 1e6 + 5, size = 1 << 20;
int dp[21][size], subset[size], ans[N];
char s[N];

void solve(int i, int sub, int ind) {
	if (i < 0)
		return;
	if (dp[i][sub] == -1) {
		if (sub & (1 << i)) {
			dp[i][sub ^ (1 << i)] = ind;
			subset[sub ^ (1 << i)] = ind;
			solve(i - 1, sub ^ (1 << i), ind);
		}
		dp[i][sub] = ind;
		subset[sub] = ind;
		//cout<<sub<<" "<<(sub ^ (1 << i))<<endl;
		solve(i - 1, sub, ind);
	}
	return;
}

int main() {

	int q;
	scanf("%d", &q);
	while (q--) {
		int n, k;
		scanf("%d%d", &n, &k);
		for (int j = 0; j < 21; ++j)
			for (int i = 0; i < size; ++i) {
				dp[j][i] = -1;
				subset[i] = -1;
			}
		scanf("%s", s);
		char ch = getchar();
		for (int i = 0; i < k; ++i) {
			int bit = 0, len = 0;
			while ((ch = getchar()) != '\n') {
				int val = ch - 'a';
				bit = bit | (1 << val);
				len++;
			}
			solve(20, bit, i);
		}
		for (int i = 0; i < n; ++i)	
			ans[i] = -1;
		int bit = 0, prev = 0, val;
		for (int i = 0; i < n; ++i) {
			val = s[i] - 'a';
			bit = bit | (1 << val);
			if (subset[bit] == -1) {
				ans[i - 1] = subset[prev];
				bit = 0;
				bit = bit | (1 << val);
			}
			prev = bit;
		}
		ans[n - 1] = subset[prev];
		for (int i = n - 2; i >= 0; --i)
			if (ans[i] == -1)
				ans[i] = ans[i + 1];
		for (int i = 0; i < n; ++i)
			printf("%d ", ans[i] + 1);
		puts("");
	}
	return 0;
}
