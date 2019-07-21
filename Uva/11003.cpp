#include <bits/stdc++.h>

using namespace std;

int n,c,weight[1005],load[1005];
int dp[1005][3005];

int length(int k,int cap)
{
	if(k == n)
	return 0;
	if(dp[k+1][cap] == -1)
	dp[k+1][cap] = length(k+1,cap);
	if(cap < weight[k])
	return dp[k+1][cap];
	if(dp[k+1][min(cap-weight[k],load[k])] == -1)
	dp[k+1][min(cap-weight[k],load[k])] = length(k+1,min(cap-weight[k],load[k]));
	return max(dp[k+1][cap],dp[k+1][min(cap-weight[k],load[k])]+1);
}

/*
int solve()
{
	for(int i=n;i>=0;i--)
	{
		for(int j=0;j<=c;j++)
		{
			if(i == n)
			dp[i][j] = 0;
			else if(j < weight[i])
			dp[i][j] = dp[i+1][j];
			else
			dp[i][j] = max(dp[i+1][j],dp[i+1][min(j-weight[i],load[i])]+1);
		}
	}
}
*/
int main()
{
	while(scanf("%d",&n) != EOF && n)
	{
		c = 0;
		for(int i=0;i<n;++i)
		{
			scanf("%d%d",weight+i,load+i);
			c = max(load[i],c);
			c = max(c,weight[i]);
		}
		//solve();
		int len=0;
		for(int i=0;i<=n;++i)
		for(int j=0;j<=c;++j)
		dp[i][j] = -1;
		for(int i=0;i<n;++i)
		len = max(len,length(i+1,load[i])+1);
		//len = max(len,dp[i+1][load[i]]+1);
		printf("%d\n",len);
	}
	return 0;
}
