#include <bits/stdc++.h>

using namespace std;

list <int> adj[100];
string city[100];
int dfs_low[100],dfs_num[100],cnt,root,child;
bool art[100],visit[100];
void dfs(int u,int par)
{
	visit[u] = true;
	dfs_low[u] = dfs_num[u] = cnt++;
	for(auto it : adj[u]) {
		if(visit[it] == false) {
			if(u == root)
				child++;
			dfs(it,u);
			if(dfs_low[it] >= dfs_num[u])
				art[u] = true;
			dfs_low[u] = min(dfs_low[u],dfs_low[it]);
		}
		else if(it != par)
			dfs_low[u] = min(dfs_low[u],dfs_num[it]);
	}
}
int main()
{
	int n,m,ind=1;
	while(scanf("%d",&n) != EOF && n) {
		if(ind != 1)
			cout<<endl;
		map <string,int> mp;
		for(int i=0;i<n;++i) {
			cin>>city[i];
			mp.insert({city[i],i});
			visit[i] = art[i] = false;
			adj[i].clear();
		} 
		scanf("%d",&m);
		for(int i=0;i<m;++i) {
			string u,v;
			cin>>u>>v;
			int x,y;
			x = mp[u];
			y = mp[v];
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for(int i=0;i<n;++i) {
			cnt = 0, root = i, child = 0;
			if(visit[i] == false) {
				dfs(i,i);
				art[i] = (child > 1);
			}
		}
		int c = 0;
		vector <string> cam;
		for(int i=0;i<n;++i) 
			if(art[i]) {
				c++;
				cam.push_back(city[i]);
			}
		sort(cam.begin(),cam.end());
		printf("City map #%d: %d camera(s) found\n",ind,c);
		for(auto it : cam)
			cout<<it<<endl;
		ind++;
	}
	return 0;
}
