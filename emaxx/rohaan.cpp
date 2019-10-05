#include <bits/stdc++.h>

using namespace std;

int adj[50][50];
int main()
{
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; ++i) {
		int n, r;
		scanf("%d", &n);
		for (int r = 0; r < n; ++r)
			for (int c = 0; c < n; ++c)
				scanf("%d", adj[r] + c);
		for (int k = 0; k < n; ++k) {
			for (int u = 0; u < n; ++u) {
				for(int v = 0; v < n; ++v)
					adj[u][v] = min(adj[u][v],adj[u][k] + adj[k][v]);
			}
		}
		scanf("%d", &r);
		int ans = 0;	
		while (r--) {
			int u, v;
			scanf("%d%d", &u, &v);
			ans += adj[u-1][v-1];
		}
		printf("Case #%d: %d\n",i + 1, ans);
	}
	return 0;
}
