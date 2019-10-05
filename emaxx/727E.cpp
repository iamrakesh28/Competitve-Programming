#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cassert>
#include <set>

#define N 1000005
using namespace std;

char cd[N];
const int p = 31, m = 1e9 + 9;
vector <long long> hs, power;

int solve(vector <pair <long long, int>> &ind, int n, long long cur) {

	int beg = 0, end = n - 1, mid, ans = -1;
	while (beg <= end) {
		mid = (beg + end) >> 1;
		if (ind[mid].first == cur)
			return ind[mid].second;
		else if (ind[mid].first > cur)
			end = mid - 1;
		else
			beg = mid + 1;
	}
	return ans;
}

int main() {

	int n, k, g, pos = 1, len;
	scanf("%d%d%s%d", &n, &k, cd, &g);
	len = n * k;
	power.resize(len + k);
	hs.resize(len + k + 1);
	power[0] = 1;
	hs[0] = 0;
	for (int i = 1; i < k + len; ++i)
		power[i] = (power[i - 1] * p) % m;
	vector <pair <long long, int>> ind(n);
	set <long long> g2;
	vector <int> ans(n);
	vector <long long> qs;
	for (int i = 0; i < g; ++i) {
		long long cur = 0;
		char c;
		for (int j = 0; j < k; ++j) {
			scanf(" %c", &c);
			cur = (cur + (c - 'a' + 1) * power[j]) % m;
		}
		g2.insert(cur * power[len - 1] % m);
		qs.push_back(cur * power[len - 1] % m);
	}
	for (int i = 0; i < len + k; ++i)
		hs[i + 1] = (hs[i] + (cd[i % len] - 'a' + 1) * power[i]) % m;
	for (int r = 0; r < k; ++r) {
		set <long long> g1;
		pos = 1;
		ind.clear();
		for (int i = 0; i < n; ++i) {
			long long cur = 0;
			cur = (hs[k + r + i * k] - hs[r + i * k] + m) % m;
			cur = cur * power[len - r - i * k - 1] % m;
			if (g1.find(cur) != g1.end()) {
				pos = 0;
				break;
			}
			if (g2.find(cur) == g2.end()) {
				pos = 0;
				break;
			}
			g1.insert(cur);
			ind.push_back({cur, i});
		}
		if (pos)
			break;
	}
	if (pos == 0) {
		puts("NO");
		return 0;
	}
	//cout<<ind.size()<<endl;
	sort(ind.begin(), ind.end());
	puts("YES");
	int cnt = 0;
	for (auto it : qs) {
		int in = solve(ind, n, it);
		if (in != -1)
			ans[in] = cnt + 1;
		cnt++;
	}
	for (auto it : ans)
		printf("%d ", it);
	puts("");
	return 0;
}
