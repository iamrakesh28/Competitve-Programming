#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair< int, int > pii;
typedef pair< int, pii > edge;
typedef long long i64;

const int MAX = 100009;
const int MOD = 1000000000;

vector< edge > G;
int parent[MAX];
i64 cnt[MAX], sum[MAX];

int find(int u) {
	if(u != parent[u]) parent[u] = find(parent[u]);
	return parent[u];
}

int main() {
	int n, e, u, v, w, i;
	i64 res, cu, cv;
	scanf("%d %d", &n, &e);
	for(i = 0; i < e; i++) {
		scanf("%d %d %d", &u, &v, &w);
		G.push_back(edge(w, pii(u, v)));
	}
	sort(G.begin(), G.end());
	for(i = 0; i < e; i++) sum[i] = G[i].first + (i > 0 ? sum[i-1] : 0);
	for(i = 1; i <= n; i++) {
		parent[i] = i;
		cnt[i] = 1;
	}
	for(res = 0, i = G.size() - 1; i >= 0; i--) {
		u = find(G[i].second.first);
		v = find(G[i].second.second);
		if(u != v) {
			cu = cnt[u], cv = cnt[v];
			res += (cu * cv) * sum[i];
			if(res > MOD) res %= MOD;
			parent[u] = parent[v];
			cnt[find(G[i].second.first)] = cu + cv;
			cnt[find(G[i].second.second)] = cu + cv;
		}
	}
	printf("%lld\n", res);
	return 0;
}
