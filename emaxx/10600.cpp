#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int u, v, w;
	bool take;
} edge[10000];

vector <int> E;
int par[100], size[100];
int find(int u) {
	if (u == par[u])
		return u;
	return find(par[u]);
}

int join(int u, int v, int i, int s) {
	u = find(u);
	v = find(v);
	if (u == v)
		return 0;
	if (size[u] > size[v]) {
		size[u] += size[v];
		par[v] = u;
	}
	else {
		size[v] += size[u];
		par[u] = v;
	}
	if (s == 0)
		E.push_back(i);
	return edge[i].w;
}

bool compare(Edge &a, Edge &b) {
	return a.w < b. w;
}

int MST(int m, int n, int s) {
	
	for (int i = 0; i < n; ++i) {
		size[i] = 1;
		par[i] = i;
	}
	int ans = 0;
	for (int i = 0; i < m; ++i) {
		if (edge[i].take == false) {
			ans += join(edge[i].u, edge[i].v, i, s);
		}
	}
	//cout<<size[find(0)]<<"\t"<<n<<endl;
	if (size[find(0)] != n)
		return 1e9;
	return ans;
}
int main() {
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		E.clear();
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edge[i] = {u - 1, v - 1, w, false};
		}
		sort(edge, edge + m, compare);
		int s1 = MST(m, n, 0), s2 = 1e9;
		for (auto it : E) {
			edge[it].take = true;
			s2 = min(s2, MST(m, n, 1));
			edge[it].take = false;;
		}
		if (s2 == 1e9)
			s2 = s1;
		printf("%d %d\n", s1, s2);
	}
	return 0;
}
