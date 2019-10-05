#include <bits/stdc++.h>

using namespace std;

const int M = 1e6;
pair <int, pair <int, int>> edge[M];
map <string, int> mp;
int cnt, par[400], size[400];

int find(int u) {
	if (u == par[u]) 
		return u;
	return find(par[u]);
}

void compress(int u, int v) {
	if (u == v)
		return;
	compress(par[u], v);
	par[u] = v;
}
int join(int u, int v, int w) {
	
	int u1 = u, v1 = v;
	u = find(u);
	v = find(v);
	if (u == v)
		return 0;
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
		compress(v1, u);
	}
	else {
		size[v] += size[u];
		par[u] = v;
		compress(u1, v);
	}
	return w;
}

int main() {
	
	int n, m;
	while (scanf("%d%d", &n, &m) != EOF && (n || m)) {
		mp.clear();
		cnt  = 0;
		for (int i = 0; i < n; ++i) {
			string s;
			cin>>s;
			mp[s] = cnt++;
			par[i] = i;
			size[i] = 1;	
		}
		for (int i = 0; i < m; ++i) {
			string s1, s2;
			int w;
			cin>>s1>>s2>>w;
			edge[i].first = w;
			edge[i].second.first = mp.at(s1);
			edge[i].second.second = mp.at(s2);
		}
		string s;
		cin>>s;
		sort(edge, edge + m);
		int ans = 0;
		for (int i = 0; i < m; ++i)
			ans += join(edge[i].second.first, edge[i].second.second, edge[i].first);
		if (size[find(0)] != n)
			printf("Impossible\n");
		else
			printf("%d\n", ans);
	}
}
