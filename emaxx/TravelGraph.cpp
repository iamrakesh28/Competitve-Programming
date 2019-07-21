#include <bits/stdc++.h>

using namespaces std;

const int inf = 1e9;
int adj[15][15], mat[15][15], n, m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int j = 0; j < n; ++j)
		for (int i = 0; i < n; ++i)
			if (i == j)
				adj[i][j] = 0;
			else
				adj[i][j] = inf;
	while (m--) {
		int x, y, w;
		scanf("%d%d%d", &x, &y, &w);
		adj[x - 1][y - 1] = min(adj[x - 1][y - 1], w);
		adj[y - 1][x - 1] = min(adj[y - 1][x - 1], w);
	}
	return 0;
}


