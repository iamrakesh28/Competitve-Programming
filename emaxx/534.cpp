#include <bits/stdc++.h>

using namespace std;

const int INF = 1000000000;
int n, x[200], y[200], par[200];
bool visit[200];
int dist[200];

int norm(int i, int u)
{
	int dx = x[i] - x[u], dy = y[i] - y[u];
	return (dx * dx + dy * dy);
}

float spann()
{
	set <pair <int, int>> q;
	q.insert(make_pair(0, 0));
	par[0] = 0;
	for (int i = 0; i < n; ++i) {
		dist[i] = INF;
		visit[i] = false;
	}
	dist[0] = 0;
	while (!q.empty()) {
		auto p = *q.begin();
		q.erase(q.begin());
		int u = p.second;
		visit[u] = true;
		for (int i = 0; i < n; ++i) {
			if (i == u)
				continue;
			int d = norm(i, u);
			if (dist[i] == INF) {
				dist[i] = d;
				q.insert(make_pair(d, i));
				par[i] = u;
			}
			else if (dist[i] > d && visit[i] == false) {
				q.erase(q.find(make_pair(dist[i], i)));
				q.insert(make_pair(d, i));
				dist[i] = d;
				par[i] = u;
			}
		}
	}
	float ans = -2000.0;
	for (int i = 1; i != 0; i = par[i]) {
		float d = sqrt(dist[i]);
		ans = max(ans, d);
	}
	return ans;
}

int main()
{
	int j = 0;
	while (scanf("%d", &n) != EOF && n) {
		for (int i = 0; i < n; ++i)
			scanf("%d%d", x + i, y + i);
		printf("Scenario #%d\nFrog Distance = %.3f\n", j + 1, spann());
		printf("\n");
		j++;
	}
	return 0;
}
