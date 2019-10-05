#include <bits/stdc++.h>

using namespace std;

list <int> adj[700];
bool visit[700];
int low[700],num[700],cnt,f;
pair <int,int> E[500000];
void bridge(int u,int p)
{
	visit[u] = true;
	low[u] = num[u] = cnt++;
	for(auto it : adj[u]) {
		if(!visit[it]) {
			bridge(it,u);
			if(low[it] > num[u])
				E[f++] = {min(it,u),max(it,u)};
			low[u] = min(low[u],low[it]);
		}
		else if(it != p)
			low[u] = min(low[u],num[it]);
	}
}
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;++i) {
		int n,m;
		scanf("%d%d",&n,&m);
		for(int j=0;j<n;++j) {
			visit[j] = false;
			adj[j].clear();
		}
		while(m--) {
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u-1].push_back(v-1);
			adj[v-1].push_back(u-1);
		}
		cnt = 0, f = 0;
		bridge(0,-1);
		sort(E,E+f);
		printf("Caso #%d\n",i+1);
		if(!f) {
			printf("Sin bloqueos\n");
			continue;
		}
		printf("%d\n",f);
		for(int j=0;j<f;++j)
			printf("%d %d\n",E[j].first+1,E[j].second+1);
	}
	return 0;
}
