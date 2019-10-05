#include <bits/stdc++.h>

using namespace std;

int arr[1000];
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) && n && m)
	{
		for(int i=0;i<n++i)
		scanf("%d",arr+i);
		for(int i=0;i<=n;++i)
		{
			for(int j=0;j<=n;++j)
			{
				if(j == 0)
				{
					if(i==0)
					dp[i][j] = 0;
					else	
					dp[i][j] = INF;
				}
				else
				dp[i][j] = (dp[i][j-1] + arr[j-1]*dp[i-1][j-1])%m;
			}
		}
	}
	return 0;
}
