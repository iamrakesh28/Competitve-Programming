#include <bits/stdc++.h>

#define PRIME 1000000007
using namespace std;

list <int> *adj;
long long int dp[200005],ans[200005];
vector <vector<long long int>> suff(200005),pref(200005); 
bool visit[200005];
void addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void DFS(int u,int par)
{
	visit[u] = true;
	dp[u] = 1;
	pref[u].push_back(1);
	int i=0;
	for(auto it=adj[u].begin();it!=adj[u].end();++it,++i)
	{
		if(visit[*it] == false)
		DFS(*it,u);
		if(*it != par)
		{
			dp[u] = (dp[u]*(dp[*it]+1))%PRIME;
			pref[u].push_back((pref[u][i]*(dp[*it]+1))%PRIME);
		}
		else
			pref[u].push_back(pref[u][i]);	
	}
	suff[u].push_back(1);
	i=0;
	for(auto it=adj[u].rbegin();it!=adj[u].rend();++it,++i)
	{
		if(*it != par)
		suff[u].push_back((suff[u][i]*(dp[*it]+1))%PRIME);
		else
			suff[u].push_back(suff[u][i]);		
	}
	return;
}

void DFSans(int u,long long int par)
{
	visit[u] = true;
	int i=0;
	for(auto it=adj[u].begin();it!=adj[u].end();++it,++i)
	{
		if(visit[*it] == false)
		{
			int len = pref[u].size();
			long long int val = (pref[u][i]*suff[u][len-i-2])%PRIME;
			val = (val*(par))%PRIME;
			//cout<<val<<" "<<u<<" "<<" "<<par<<" "<<pref[u][i]<<" "<<suff[u][len-i-2]<<endl;
			dp[u] = val;
			ans[*it] = (dp[*it]*(val+1))%PRIME;
			DFSans(*it,dp[u]+1);
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
	memset(visit,false,sizeof(bool)*n);
	DFS(0,0);
	ans[0] = dp[0];
	//dp[0] = 1;
	memset(visit,false,sizeof(bool)*n);
	DFSans(0,1);
	for(int i=0;i<n;++i)
	cout<<ans[i]<<" ";
	cout<<endl;
	return 0;
}
