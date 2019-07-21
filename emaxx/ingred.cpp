#include <bits/stdc++.h>

#define mk make_pair
#define pb push_back
using namespace std;

const int INF = 100000000;
typedef pair <int, int> ipair;

list <ipair> adj[100];
int dist1[100][256], dist2[100][256], s, n, shop[100], cost1[256], cost2[256];

void dijsktra(int s1, int dist[][256]) 
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < 1 << s; ++j)
				dist[i][j] = INF;
	set <pair <int, ipair>> q;
	int b = 0;
	if (shop[s1] != -1)
		b = b | (1 << shop[s1]);
	dist[s1][b] = 0;
	q.insert(mk(0, mk(s1, b)));
	while (!q.empty()) {
		auto p = *q.begin();
		q.erase(q.begin());
		int u = p.second.first, bit = p.second.second;
		for (auto it : adj[u]) {
			int v = it.second, next = bit;	
			if (shop[v] != -1)
				next = next | (1 << shop[v]);
			if (dist[v][next] == INF) {
				dist[v][next] = dist[u][bit] + it.first;
				q.insert(mk(dist[v][next], mk(v, next)));
			}
			else if (dist[v][next] > dist[u][bit] + it.first) {
				q.erase(q.find(mk(dist[v][next], mk(v, next))));
				dist[v][next] = dist[u][bit] + it.first;
				q.insert(mk(dist[v][next], mk(v, next)));
			}
		}
	}
	return ;
}

int main()
{
	int m;
	scanf("%d%d", &n, &m);
	memset(shop, -1, sizeof(int) * n);
	while (m--) {
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		adj[a].pb(mk(c, b));
		adj[b].pb(mk(c, a));
	}
	scanf("%d", &s);
	for (int i = 0; i < s; ++i) {
		int v;
		scanf("%d", &v);
		shop[v] = i;
	}
	for (int i = 0; i < 1 << s; ++i) {
		cost1[i] = INF;
		cost2[i] = INF;
	}
	int s1, s2;
	scanf("%d%d", &s1, &s2);
	dijsktra(s1, dist1);
	dijsktra(s2, dist2);
	for (int j = 0; j < 1 << s; ++j)
		for (int i = 0; i < n; ++i)
			cost1[j] = min(cost1[j], dist1[i][j]); 
	for (int j = 0; j < 1 << s; ++j)
		for (int i = 0; i < n; ++i)
			cost2[j] = min(cost2[j], dist2[i][j]);
	int ans = INF;
	for (int j = 0; j < 1 << s; ++j) {
		for (int i = 0; i < 1 << s; ++i)
			if ((i | j) == (1 << s) - 1) {
				ans = min(ans, cost1[i] + cost2[j]);
				//cout<<(i | j)<<endl;
			}
	}
	printf("%d\n",ans);
	return 0;
}
