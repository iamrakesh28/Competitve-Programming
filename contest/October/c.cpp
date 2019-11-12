#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 5;
long long p[N], sum[N];

long long solve(int x, int y, int aa, int bb, int lcm) {
	long long cur = 0;
	if (x > y) {
		cur = x * (sum[lcm + aa] - sum[lcm]) / 100;
		cur = cur + y * (sum[lcm + aa + bb] - sum[lcm + aa]) / 100;
		return cur;
	}
	else {
		cur = y * (sum[lcm + bb] - sum[lcm]) / 100;
		cur = cur + x * (sum[lcm + aa + bb] - sum[lcm + bb]) / 100;
		return cur;
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int q;
	cin>>q;
	while (q--) {
		int n, x, a, y, b, ans = -1;
		long long k, cur;
		cin>>n;
		for (int i = 0; i < n; ++i)
			cin>>p[i];
		cin>>x>>a>>y>>b>>k;
		sort(p, p + n);
		reverse(p, p + n);
		sum[0] = 0;
		for (int i = 0; i < n; ++i)
			sum[i + 1] = sum[i] + p[i];
		int ca = 0, cb = 0, lcm = 0, aa, bb;
		for (int i = 1; i <= n; ++i) {
			if (i % a == 0 && i % b == 0) {
				ca++;
				cb++;
				lcm++;
				aa = ca - lcm;
				bb = cb - lcm;
				cur = 0;
				cur = sum[lcm];
				cur = (x + y) * cur;
				cur = cur / 100;
				cur = cur + solve(x, y, aa, bb, lcm);
				if (cur >= k) {
					ans = i;
					break;
				}
				//cout<<cur<<endl;
				continue;
			}
			if (i % a == 0) {
				ca++;
				aa = ca - lcm;
				bb = cb - lcm;
				cur = 0;
				cur = sum[lcm];
				cur = (x + y) * cur;
				cur = cur / 100;
				cur = cur + solve(x, y, aa, bb, lcm);
				if (cur >= k) {
					ans = i;
					break;
				}
				continue;
			}
			if (i % b == 0) {
				cb++;
				aa = ca - lcm;
				bb = cb - lcm;
				cur = 0;
				cur = sum[lcm];
				cur = (x + y) * cur;
				cur = cur / 100;
				cur = cur + solve(x, y, aa, bb, lcm);
				if (cur >= k) {
					ans = i;
					break;
				}
				continue;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
