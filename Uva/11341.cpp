#include <bits/stdc++.h>

using namespace std;

int mat[11][105],n,m;
int dp[11][105];

int average(int k,int hour)
{
	if(k == 0)
	return 0;
	int avg = 0;
	bool found = false;
	for(int i=1;i<=hour;++i)
	{
		if(mat[k-1][i-1] >= 5)
		{
			if(dp[k-1][hour-i] == -2)
			dp[k-1][hour-i] = average(k-1,hour-i);
			if(dp[k-1][hour-i] != -1)
			{
				found = true;
				avg = max(avg,dp[k-1][hour-i]+mat[k-1][i-1]);
			}	
		}
	}
	if(!found)
	return -1;
	return avg;
}
int solve()
{
	bool found;
	for(int i=0;i<=n;++i) {
		for(int j=0;j<=m;++j) {
			if(i == 0)
			dp[i][j] = 0;
			else {
			found = false;
			for(int k=1;k<=j;++k) {
				if(mat[i-1][k-1] >= 5) {
					if(dp[i-1][j-k] != -1) {
					found = true;
					dp[i][j] = max(dp[i][j],mat[i-1][k-1]+dp[i-1][j-k]);
					}
				}
			}
			if(!found)
			dp[i][j] = -1;
			}
		}
	}
}

int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			scanf("%d",mat[i]+j);
		}
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=m;++j)
			dp[i][j] = -2;
		}
		//solve();
		long double ans = average(n,m);//dp[n][m];
		if(ans == -1 || ans/n < 5.0)
		printf("Peter, you shouldn't have played billiard that much.\n");
		else
		printf("Maximal possible average mark - %0.2Lf.\n",ans/n+1e-9);
	}
	return 0;
}
