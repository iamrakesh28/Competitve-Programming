#include <bits/stdc++.h>

using namespace std;

unsigned long int dp[201][11][21];
int d,m,n,q,*arr;
void solve()
{
	for(int i=n;i>=0;--i)
	{
		for(int j=m;j>=0;--j)
		{
			for(int k=d;k>=0;--k)
			{
				if(j == m)
				{
					if(k == 0)
					dp[i][j][k] = 1;
					else
					dp[i][j][k] = 0;
				}
				else if(i == n)
				dp[i][j][k] = 0;
				else
				dp[i][j][k] = dp[i+1][j+1][((k+arr[i])%d + d)%d] + dp[i+1][j][k];
			}
		}
	}
}
int main()
{
	int set=0;
	while(scanf("%d%d",&n,&q) != EOF && n && q)
	{
		arr = new int[n];
		for(int i=0;i<n;++i)
		scanf("%d",arr+i);
		printf("SET %d:\n",set+1);
		for(int i=0;i<q;++i)
		{
			scanf("%d%d",&d,&m);
			solve();
			printf("QUERY %d: %lu\n",i+1,dp[0][0][0]);
		}
		set++;
	}
	return 0;
}
