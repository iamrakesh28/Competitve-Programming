#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

using namespace std;

const int N = 2e5 + 5, inf = 3e5, maxn = 20;
int a[N], perm[N], cp[N], lg[N], st[N][maxn];
bool visit[N];
vector <int> cnt[N];
list <int> adj[N];

int lower(int i, int ind) {
	int beg = 0, end = cnt[i].size() - 1, mid, ans = inf;
	while (beg <= end) {
		mid = (beg + end) >> 1;
		if (cnt[i][mid] >= ind) {
			ans = cnt[i][mid];
			end = mid - 1;
		}
		else
			beg = mid + 1;
	}
	return ans;
}

void dfs(int u, int d, int n) {
	visit[u] = true;
	if (d - n > 0)
		for (auto it : depth[n - d - 1])
			cp[it] = u;
	depth[d].push_back(u);
	for (int it : adj[u])
		if (visit[it] == false) 
			dfs(it. d + 1, n);
	return ;
}

int main() {

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 0; i < n; ++i)
		scanf("%d", perm + i);
	if (n == 1) {
		while (q--)
			putchar('1');
		puts("");
		return 0;
	}
	for (int i = 0; i < m; ++i) {
		scanf("%d", a + i);
		cnt[a[i] - 1].push_back(i);
		visit[i] = false;
	}
	for (int i = 0; i < n; i++) {
		for (int it : cnt[perm[i] - 1]) {
			int bound = lower(perm[(i + 1) % n] - 1, it);
			cp[it] = bound;
		}
	}

	for (int i = 0; i < m; ++i) {
		if (cp[i] == inf)
			continue;
		for (int j = cp[i]; j != inf; j = cp[j])
			adj[i].push_back(j);
	}
	for (int i = 0; i < m; ++i)
		cp[i] = inf;
	for (int i = 0; i < m; ++i) {
		if (visit[i] == false)
			dfs(i, 0, n);
	}
	for (int i = 0; i < m; ++i)
		cout<<cp[i]<<"\n";
	lg[1] = 0;
	for (int i = 2; i <= m; ++i)
		lg[i] = lg[i / 2] + 1;

	for (int i = 0; i < m; ++i)
		st[i][0] = cp[i];
	for (int j = 1; j <= maxn; j++)
		for (int i = 0; i + (1 << j) <= m; i++)
			st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);

	while (q--) {
		int l, r, j, minm;
		scanf("%d%d", &l, &r);
		l--, r--;
		j = lg[r - l + 1];
		minm = min(st[l][j], st[r - (1 << j) + 1][j]);
		//cout<<minm<<endl;
		if (minm <= r)
			putchar('1');
		else
			putchar('0');
	}
	puts("");
	return 0;
}
