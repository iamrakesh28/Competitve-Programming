#include <bits/stdc++.h>

#define PRIME 1000000007
using namespace std;

list <int> *adj;
long long int ans[200005];
vector <vector<long int>> dp(200005); 

void addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
	dp[u].push_back(-1);
	dp[v].push_back(-1);
}
long long int DFS(int u,int par,int ind)
{
	if(dp[u][ind] != -1)
	return dp[u][ind];
	dp[u][ind] = 1;
	int i=0;
	for(auto it=adj[u].begin();it!=adj[u].end();++it,++i)
	{
		if(*it != par)
		{
			DFS(*it,u,dp);
			dp[u] = (dp[u]*(dp[*it]+1))%PRIME;
		}
	}
	return dp[u];
}
void DFSans(int u,int par)
{
	for(auto it=adj[u].begin();it!=adj[u].end();++it)
	{
		if(*it != par)
		{
			ans[*it] = (DFS(*it,u,dpUp)*DFS(u,*it,dpDown))%PRIME;
			DFSans(*it);
		}
	}
	return;
}
int main()
{
	int n;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	//scanf("%d",&n);
	cin>>n;
	adj = new list <int> [n];
	for(int i=0;i<n-1;++i)
	{
		int u;
		//scanf("%d",&u);
		cin>>u;
		addEdge(i+1,u-1);
	}
	memset(dpUp,-1,sizeof(long long int)*n);
	memset(dpDown,-1,sizeof(long long int)*n);
	//DFS(0,0,dpUp);
	for(int i=0;i<n;++i)
	cout<<dpUp[i]<<" ";
	cout<<endl;
	return 0;
}
