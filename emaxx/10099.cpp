#include <bits/stdc++.h>

using namespace std;

int par[100], size[100];
pair <int, pair <int, int>> edge[10000];

int find(int u) {
	
	if (u == par[u]) 
		return u;
	return find(par[u]);
}


void join(int u, int v) {
	
	u = find(u);
	v = find(v);
	if (u == v)
		return ;
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
	}
	else {
		size[v] += size[u];
		par[u] = v;
	}
	return ;
}
int main() {

	int n, r, i = 0;
	while (scanf("%d%d", &n, &r) != EOF && (n || r)) {

		for (int i = 0; i < r; ++i) {
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			edge[i].first = c - 1;
			edge[i].second.first = x - 1;
			edge[i].second.second = y - 1;
		}
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			size[i] = 1;
		}
		sort(edge, edge + r);
		int ans = 0;
		int s, d, t;
		scanf("%d%d%d", &s, &d, &t);
		s--, d--;
		for (int i = r - 1; i >= 0; --i) {
			int u = edge[i].second.first, v = edge[i].second.second, c = edge[i].first;
			join(u, v);
			if (find(s) == find(d)) {
				ans = t / c;
				if (t % c)
					ans++;
				break;
			}
		}
		printf("Scenario #%d\nMinimum Number of Trips = %d\n\n", i + 1, ans);
		i++;
	}
	return 0;
}
