#include <bits/stdc++.h>

using namespace std;

int m,n;
int arr[1005];
long int dp[1005][1005];
long int ans(int i,int k)
{
	if(i == 0)
	{
		if(k == 0)
		return 1;
		return 0; 
	}
	if(dp[i][k] == -1)
	dp[i][k] = (arr[i-1]*ans(i-1,k-1)%m+ans(i-1,k)%m)%m;
	return dp[i][k];
}
int main()
{
	while(scanf("%d%d",&n,&m) != EOF && n && m)
	{	
		for(int i=0;i<n;++i)
		scanf("%d",arr+i);
		memset(dp,-1,sizeof dp);
		long int maxm = -1;
		for(int i=1;i<=n;++i)
		maxm = max(maxm,ans(n,i));
		printf("%ld\n",maxm);
	}
	return 0;
}
