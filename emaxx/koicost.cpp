#include <bits/stdc++.h>

using namespace std;

const int prime = 1e9, N = 1e5;

pair <int, pair <int, int> > edge[N];
int par[N], size[N];
long long sum[N];

int root(int u) {	
	if (u == par[u])
		return u;
	return root(par[u]);
}

int main() {
	
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; ++i) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		edge[i].second.first = u - 1;
		edge[i].first = w;
		edge[i].second.second = v - 1;
		//edge[i] = {w, u - 1, v - 1};
	}
	for (int i = 0; i < n; ++i) {
		par[i] = i;
		size[i] = 1;
	}
	sort(edge, edge + m);
	for (int i = 0; i < m; ++i)
		if (i == 0)
			sum[i] = edge[i].first;
		else
			sum[i] = sum[i - 1] + 1LL * edge[i].first;
	long long ans = 0;
	for (int i = m - 1; i >= 0; --i) {
		int u = edge[i].second.first, v = edge[i].second.second;
		u = root(u);
		v = root(v);
		if (u != v) {
			ans = (ans + ((size[u] * (long long)size[v]) % prime) * sum[i]) % prime;
			if (size[u] > size[v]) {
				size[u] += size[v];
				par[v] = u;
			}
			else {
				size[v] += size[u];
				par[u] = v;
			}
		}
	}
	printf("%ld\n", ans);
	return 0;
}
