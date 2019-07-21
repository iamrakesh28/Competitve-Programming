#include <bits/stdc++.h>

using namespace std;

int dp[15001][101];
int m,n;
int *price,*f;
int solve(int k,int cost)
{
	if(cost > m + 200)
	return -400000;
	if(k == n)
	{
		if(cost > 2000)
		{
			if(cost <= m + 200)
			return 0;
			return -400000;
		}
		if(cost > m)
		return -400000;
		return 0;
	}
	if(dp[cost][k+1] == -1)
	dp[cost][k+1] = solve(k+1,cost);
	if(dp[cost+price[k]][k+1] == -1)
	dp[cost+price[k]][k+1] = solve(k+1,cost+price[k]);
	dp[cost][k] = max(dp[cost][k+1],dp[cost+price[k]][k+1]+f[k]);
	return dp[cost][k];
}
int main()
{
	while(scanf("%d%d",&m,&n) != EOF)
	{
		price = new int[n];
		f = new int[n];
		for(int i=0;i<n;++i)
		scanf("%d%d",price+i,f+i);
		for(int i=0;i<=m+5000;++i)
		{
			for(int j=0;j<=n;++j)
			dp[i][j] = -1;
		}
		printf("%d\n",solve(0,0));
	}
	return 0;
}
