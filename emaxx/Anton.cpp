#include <bits/stdc++.h>

using namespace std;

int color[200000],dp[200000],ans[200000];
list <int> adj[200000];
vector <vector<int>> suff(200000),pref(200000);

void addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void DFS(int u,int par)
{
	dp[u] = 0;
	int i=0;
	pref[u].push_back(0);
	for(auto it=adj[u].begin();it!=adj[u].end();++it,++i)
	{
		if(*it != par)
		{
			DFS(*it,u);
			if(color[u] != color[*it])
			dp[u] = max(dp[u],dp[*it]+1);
			else
			dp[u] = max(dp[u],dp[*it]);
		}
		pref[u].push_back(dp[u]);
	}
	i=0;
	suff[u].push_back(0);
	int temp=0;
	for(auto it=adj[u].rbegin();it!=adj[u].rend();++it,++i)
	{
		if(*it != par)
		{
			if(color[u] != color[*it])
			temp = max(temp,dp[*it]+1);
			else
			temp = max(temp,dp[*it]);
		}
		suff[u].push_back(temp);
	}
}

void DFSans(int u,int par,int p)
{
	int len = suff[u].size();
	int i=0;
	for(auto it=adj[u].begin();it!=adj[u].end();++it,++i)
	{
		if(*it != p)
		{
			dp[u] = max(par,max(suff[u][len-i-2],pref[u][i]));
			//cout<<dp[u]<<" "<<u+1<<endl;
			if(color[u] == color[*it])
			ans[*it]= max(dp[*it],dp[u]);
			else
			ans[*it] = max(dp[*it],dp[u]+1);
			if(color[u] == color[*it])
			DFSans(*it,dp[u],u);
			else
			DFSans(*it,dp[u]+1,u);
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);	
	for(int i=0;i<n;++i)
	scanf("%d",color+i);
	for(int i=0;i<n-1;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u-1,v-1);
	}
	DFS(0,0);
	ans[0] = dp[0];
	DFSans(0,0,0);
	int ansm = ans[0];
	for(int i=0;i<n;++i)
	ansm = min(ansm,ans[i]);
	printf("%d\n",ansm);
	return 0;
}
