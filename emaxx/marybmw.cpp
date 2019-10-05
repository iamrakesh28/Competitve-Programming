#include <bits/stdc++.h>

using namespace std;

const int N = 1e5;
pair <long long, pair <int, int>> edge[N];
int par[N], size[N];

int root(int u) {
	if (u == par[u])
		return u;
	return root(par[u]);
}

int main() {
	
	int q;
	scanf("%d", &q);
	while (q--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) {
			int a, b;
			long long v;
			cin>>a>>b>>v;
			edge[i].first = v;
			edge[i].second.first = a - 1;
			edge[i].second.second = b - 1;
		}
		sort(edge, edge + m);
		reverse(edge, edge + m);
		for (int i = 0; i < n; ++i) {
			par[i] = i;
			size[i] = 1;
		}
		bool found = false;
		for (int i = 0; i < m; ++i) {
			int u1 = edge[i].second.first, u = root(u1);
			int v1 = edge[i].second.second, v = root(v1);
			long long w = edge[i].first;
			if (u != v) {
				if (size[u] > size[v]) {
					size[u] += size[v];
					par[v] = u;
				}
				else {
					size[v] += size[u];
					par[u] = v;
				}
			}
			if (root(0) == root(n - 1)) {
				cout<<w<<endl;
				found = true;
				break;
			}
		}
		if(!found)
			cout<<-1<<endl;
	}
	return 0;
}
