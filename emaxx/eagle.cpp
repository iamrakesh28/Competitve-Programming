#include <bits/stdc++.h>

#define mk(x,y) make_pair(x,y)
using namespace std;
typedef pair<int,long int> ipair; 
typedef vector<vector<long int>> V;
list <ipair> adj[100000];
V suff(100000),pref(100000);
long int dp[100000],ans[100000];
void addEdge(int u,int v,long int w)
{
	adj[u].push_back(mk(v,w));
	adj[v].push_back(mk(u,w));
}
void DFS(int u,int par)
{
	dp[u] = 0;
	int i=0;
	pref[u].push_back(0);
	for(auto it=adj[u].begin();it!=adj[u].end();++it,++i)
	{
		if((*it).first != par)
		{
			DFS((*it).first,u);
			dp[u] = max(dp[u],dp[(*it).first]+(*it).second);
			pref[u].push_back(dp[u]);
		}
		else
			pref[u].push_back(pref[u][i]);
		//cout<<pref[u][i]<<endl;
	}
	suff[u].push_back(0);
	i=0;
	for(auto it=adj[u].rbegin();it!=adj[u].rend();++it,++i)
	{
		if((*it).first != par)
			suff[u].push_back(max(suff[u][i],dp[(*it).first]+(*it).second));
		else
			suff[u].push_back(suff[u][i]);
	}
}
void DFSans(int u,long int par,int p)
{
	int i=0;
	for(auto it=adj[u].begin();it!=adj[u].end();++it,++i)
	{
		if((*it).first != p)
		{
			int len = pref[u].size();
			dp[u] = max(par,max(suff[u][len-i-2],pref[u][i]));
			//cout<<u+1<<" "<<dp[u]<<" "<<suff[u][len-i-2]<<" "<<pref[u][i]<<endl;
			ans[(*it).first] = max(dp[(*it).first],dp[u]+(*it).second);
			DFSans((*it).first,dp[u]+(*it).second,u);
		}
	}
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			adj[i].clear();
			suff[i].clear();
			pref[i].clear();
		}
		for(int i=0;i<n-1;++i)
		{
			int u,v;
			long int w;
			scanf("%d%d%ld",&u,&v,&w);
			addEdge(u-1,v-1,w);
		}
		DFS(0,0);
		ans[0] = dp[0];
		DFSans(0,0,0);
		for(int i=0;i<n;++i)
		printf("%ld ",ans[i]);
		printf("\n");
	}
	return 0;
}
