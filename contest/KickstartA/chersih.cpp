#include <iostream>

using namespace std;

const int N = 1e5 + 5;
int par[N], size[N], cmp[N];

int find(int u) {
	if (par[u] == u)
		return u;
	return find(par[u]);
}

void join(int u, int v) {

	u = find(u), v = find(v);
	if (size[u] > size[v]) {
		par[v] = u;
		size[u] += size[v];
	}
	else {
		par[u] = v;
		size[v] += size[u];
	}
}

int main() {

	int t;
	scanf("%d", &t);
	for (int j = 0; j < t; ++j) {
		int n, m, ans = 0;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; ++i) {
			size[i] = 1;
			par[i] = i;
			cmp[i] = 0;
		}
		for (int i = 0; i < m; ++i) {
			int c, d;
			scanf("%d%d", &c, &d);
			c--, d--;
			if (find(c) == find(d))
				continue;
			join(c, d);
			ans += 1;
		}
		for (int i = 0; i < n; ++i)
			cmp[find(i)] = 1;
		int cnt = 0;
		for (int i = 0; i < n; ++i)
			if (cmp[i] == 1)
				cnt++;
		ans = ans + (cnt - 1) * 2;
		printf("Case #%d: %d\n", j + 1, ans);
	}
	return 0;
}
