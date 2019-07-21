#include <bits/stdc++.h>

using namespace std;

const long long inf = 1e18;
long long adj[100][100], dist[100];
char city[100][21];


void Bellman(int s, int n) {
	
	//dist[]
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			for (int k = 0; k < n; ++k) {
				if (adj[j][k] == inf)
					continue;
				if (dist[k] > dist[j] + adj[j][k]) {
					dist[k] = dist[j]  + adj[j][k];
				}
			}
		}
	}
}

int main() {
	
	int n, i = 0;
	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i) {
			scanf("%s", city[i]);
			for (int j = 0 ; j < n; ++j) {
				scanf("%ld", adj[i] + j);
				if (adj[i][j] == 0 && i != j)
					adj[i][j] = inf;
				if (i == j && adj[i][j] > 0)
					adj[i][j] = 0;
			}
		}
		for (int k = 0; k < n; ++k) {
			for (int i = 0; i < n; ++i) {
				for (int j = 0; j < n; ++j) {
					if (adj[i][k] == inf || adj[k][j] == inf)
						continue;
						adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
				}
			}
		}
		bool neg = false;
		for (int i = 0; i < n; ++i)
			if (adj[i][i] < 0)
				neg = true;
		int q;
		scanf("%d", &q);
		printf("Case #%d:\n", i + 1);
		for (int i = 0; i < q; ++i) {
			int u, v;
			scanf("%d%d", &u, &v);
			if (neg)
				printf("NEGATIVE CYCLE\n");
			else {
				printf("%s-%s ",city[u], city[v]);
				if (adj[u][v] == inf)
					printf("NOT REACHABLE\n");
				else
					printf("%d\n", adj[u][v]);
			}
		}
		i++;
	}
	return 0;
}
