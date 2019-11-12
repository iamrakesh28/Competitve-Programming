#include <bits/stdc++.h>

using namespace std;

int t, dp[10005];
set <string> q;
string ans;
int solve(int i) {
	if (i == t)
		return true;
	if (dp[i] == -1) {
		dp[i] = 0;
		for (int j = i; j < t; ++j) {
			string m = "";
			for (int m = i; m <=j; ++m)
				m = m + ans[m];
			if (q.find(m) != q.end()) {
			if (solve(j + 1) == 1) {
				dp[i] = 1;
				return 1;
			}
			}
		}
	}
	return dp[i];
}
int main() {

	int n;
	for (int i = 0; i < n; ++i) {
		string s;
		cin>>s;
		q.insert(s);
	}
	int q;
	scanf("%d", &q);
	while (q--) {
		ans = "";
		cin>>ans;
		t = ans.size();
		for (int i = 0; i <= t + 1; ++i)
			dp[i] = -1;
		if (solve(0) == 1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
