#include <bits/stdc++.h>

const int INF = 100000000;
using namespace std;

list <int> adj[52];

int dijsktra(int s, int t, int cost) 
{
	int dist[52];
	for (int i = 0; i < 52; ++i)
		dist[i] = INF;
	set <pair <int, int>> q;
	dist[s] = cost;
	q.insert(make_pair(cost, s));
	while (!q.empty()) {
		auto p = *q.begin();
		q.erase(q.begin());
		int u = p.second, w;
		for (auto it : adj[u]) {
			if (u >= 26)
				w = dist[u] + 1;
			else {
				if (dist[u] % 19 == 0)
					w = dist[u] + dist[u] / 19;
				else
					w = dist[u] + dist[u] / 19 + 1;
			}
			if (dist[it] == INF) {
				dist[it] = w;
				q.insert(make_pair(dist[it], it));
			}
			else if (dist[it] > w) {	
				q.erase(q.find(make_pair(dist[it], it)));
				dist[it] = w;
				q.insert(make_pair(dist[it], it));
			}
		}
	}
	return dist[t];
}

int main()
{
	int n, i = 0;
	while (scanf("%d", &n) != EOF && n != -1) {
		for (int i = 0; i < 52; ++i)
			adj[i].clear();
		while (n--) {
			char a, b;
			int u, v;
			scanf(" %c %c", &a, &b);
			if (islower(a))
				u = a - 'a' + 26;
			else
				u = a - 'A';
			if (islower(b))
				v = b - 'a' + 26;
			else
				v = b - 'A';
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		int cost, s1, t1;
		char s, t;
		scanf(" %d %c %c", &cost, &s, &t);
		if (islower(s))
			t1 = s - 'a' + 26;
		else
			t1 = s - 'A';
		if (islower(t))
			s1 = t - 'a' + 26;
		else
			s1 = t - 'A';
		printf("Case %d: %d\n", i + 1, dijsktra(s1, t1, cost));
		i++;
	}
	return 0;
}
