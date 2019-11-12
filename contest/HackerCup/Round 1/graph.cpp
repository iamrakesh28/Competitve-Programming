#include <iostream>
#include <vector>

#define N 55
using namespace std;

const int inf = 1e9;
int dist[N][N], path[N][N];

void init(int n) {
	for (int i = 0; i <= n; ++i)
		for (int j = 0; j <= n; ++j) {
			if (i == j)
				dist[i][j] = path[i][j] = 0;
			else
				dist[i][j] = path[i][j] = inf;
		}
	return;
}

bool floyd(int n) {
	for (int k = 0; k < n; ++k)
		for (int i = 0; i < n; ++i)
			for (int j = 0; j < n; ++j)
				path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			if (dist[i][j] != inf)
				if (path[i][j] < dist[i][j])
					return false;
	return true;
}
int main() {

	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n, m;
		bool poss = true;
		scanf("%d%d", &n, &m);
		init(n);
		while (m--) {
			int x, y, z;
			scanf("%d%d%d", &x, &y, &z);
			if (dist[x - 1][y - 1] == inf)
				path[x - 1][y - 1] = path[y - 1][x - 1] = dist[x - 1][y - 1] = dist[y - 1][x - 1] = z;
			else if (dist[x - 1][y - 1] != z)
				poss = false;
		}
		poss = floyd(n);
		printf("Case #%d: ", i + 1);
		if (poss) {
			int e = 0;
			vector <pair <int, pair <int, int>> > edge;
			for (int i = 0; i < n; ++i)
				for (int j = 0; j < i; ++j)
					if (dist[i][j] != inf) {
						e++;
						edge.push_back({i + 1, {j + 1, dist[i][j]}});
					}
			printf("%d\n", e);
			for (auto it : edge)
				printf("%d %d %d\n", it.first, it.second.first, it.second.second);
		}
		else
			printf("Impossible\n");
	}
	return 0;
}
