#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2005;
long long c[N], k[N], x[N], y[N];
pair <long long, pair <int, int>> adj[N * N];
int par[N], size[N], mcity[N];
long long minm[N];
bool mark[N * N], city[N];

int find(int u) {
	if (u == par[u])
		return u;
	par[u] = find(par[u]);
	return par[u];
}

void join(int u, int v) {
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
		minm[u] = min(minm[u], minm[v]);
		if (minm[u] > minm[v])
			mcity[u] = mcity[v];
	}
	else {
		size[v] += size[u];
		par[u] = v;
		minm[v] = min(minm[u], minm[v]);
		if (minm[v] > minm[u])
			mcity[v] = mcity[u];
	}
}

int main() {

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%lld%lld", x + i, y + i);
	long long ans = 0;
	for (int i = 0; i < n; ++i) {
		scanf("%lld", c + i);
		ans += c[i];
		city[i] = true;
		minm[i] = c[i];
		par[i] = i;
		mcity[i] = i;
		size[i] = 1;
	}
	for (int i = 0; i < n; ++i)
		scanf("%lld", k + i);
	int edge = 0;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j) {
			long long w = abs(x[i] - x[j]) + abs(y[i] - y[j]);
			w = w * (k[i] + k[j]);
			adj[edge].first = w;
			adj[edge].second.first = i;
			adj[edge].second.second = j;
			edge++;
		}
	sort(adj, adj + edge);
	for (int i = 0; i < edge; ++i)
		mark[i] = false;
	int cnt = 0, ncnt = n;
	for (int i = 0; i < edge; ++i) {
		long long temp = ans;
		int u = adj[i].second.first;
		int v = adj[i].second.second;
		int u1 = find(u);
		int v1 = find(v);
		temp = temp - max(minm[u1], minm[v1]) + adj[i].first;
		if (temp < ans) {
			ans = temp;
			if (minm[u1] >= minm[v1])
				city[mcity[u1]] = false;
			else
				city[mcity[v1]] = false;
			join(u1, v1);
			mark[i] = true;
			cnt++;
			//city[u] = city[v] = true;

			ncnt--;
		}
	}
	printf("%lld\n%d\n", ans, ncnt);
	for (int i = 0; i < n; ++i)
		if (city[i])
			printf("%d ", i + 1);
	printf("\n%d\n", cnt);
	for (int i = 0; i < edge; ++i) {
		if (mark[i])
			printf("%d %d\n", adj[i].second.first + 1, adj[i].second.second + 1);
	}
	return 0;
}
