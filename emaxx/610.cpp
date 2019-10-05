#include <bits/stdc++.h>

#define N 1000
using namespace std;

list <pair<int,int>> adj[N];
bool visit[N],E[N*N];
int low[N],num[N],cnt;

void bridge(int u,int par)
{
	visit[u] = true;
	low[u] = num[u] = cnt++;
	for(auto it : adj[u]) {
		if(!visit[it.second]) {
			bridge(it.second,u);
			if(!E[it.first])
			printf("%d %d\n",u+1,it.second+1);
			E[it.first] = true;
			if(low[it.second] > num[u])
				printf("%d %d\n",it.second+1,u+1);
			low[u] = min(low[u],low[it.second]);
		}
		else if(it.second != par) {
			low[u] = min(low[u],num[it.second]);
			if(!E[it.first])
			printf("%d %d\n",u+1,it.second+1);
			E[it.first] = true;
		}
	}
}

int main()
{
	int n,m,ind=1;
	while(scanf("%d%d",&n,&m) != EOF && (n || m)) {
		for(int i=0;i<n;++i) {
			visit[i] = false;
			adj[i].clear();
		}
		for(int i=0;i<m;++i) {
			int u,v;
			scanf("%d%d",&u,&v);
			adj[u-1].push_back({i,v-1});
			adj[v-1].push_back({i,u-1});
			E[i] = false;
		}
		printf("%d\n\n",ind);
		cnt = 0;
		bridge(0,-1);
		printf("#\n");
		ind++;
	}
	return 0;
}
