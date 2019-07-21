#include <bits/stdc++.h>

const int inf = 1e9;
using namespace std;

pair <int, pair <int, int>> edge[2000];

void bellmon(int n, int m) {

	int dist[n];
	for (int i = 0; i < n; ++i)
		dist[i] = inf;
	dist[0] = 0;
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < m; ++j) {
			int u = edge[j].second.first, v = edge[j].second.second, w = edge[j].first;
			if (dist[v] > dist[u] + w)
				dist[v] = dist[u] + w;
		}
	for (int i = 0; i < m; ++i) {
			int u = edge[i].second.first, v = edge[i].second.second, w = edge[i].first;
			if (dist[v] > dist[u] + w) {
				//cout<<dist[v]<<" "<<u<<" "<<v<<endl;
				printf("possible\n");
				return;
			}
	}
	printf("not possible\n");
	return;
}
int main() {
	
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; ++i) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			edge[i].first = w;
			edge[i].second.first = u;
			edge[i].second.second = v;
		}
		bellmon(n, m);
	}
	return 0;
}
