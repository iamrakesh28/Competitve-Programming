#include <bits/stdc++.h>

using namespace std;

int par[10000], size[10000];
pair <int, pair <int, int>> edge[100000];

int find(int u) {
	
	if (u == par[u]) 
		return u;
	return find(par[u]);
}

bool compare(pair <int, pair<int, int>> &a, pair <int, pair<int, int>> &b) {
	
	return a.first > b.first;
}
int join(int u, int v, int c) {
	
	u = find(u);
	v = find(v);
	if (u == v)
		return c;
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
	}
	else {
		size[v] += size[u];
		par[u] = v;
	}
	return 0;
}
int main() {

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		//cout<<n<<" "<<m<<" "<<ai<<endl;
		for (int i = 0; i < m; ++i) {
			int x, y, c;
			scanf("%d%d%d", &x, &y, &c);
			edge[i].first = c;
			edge[i].second.first = x - 1;
			edge[i].second.second = y - 1;
		}
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			size[i] = 1;
		}
		sort(edge, edge + m, compare);
		//cout<<m + n<<endl;
		int ans = 0;
		for (int i = 0; i < m; ++i) {
			int u = edge[i].second.first, v = edge[i].second.second, c = edge[i].first;
			//cout<<u<<" "<<v<<" "<<c<<endl;
			ans += join(u, v, c);
		}
		printf("%d\n", ans);
	}
	return 0;
}
