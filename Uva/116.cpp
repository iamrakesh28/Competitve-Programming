#include <bits/stdc++.h>

#define INF 100000000
using namespace std;

int n,m,mat[11][101],dp[15][105],path[15][105];
int main()
{
	while(scanf("%d%d",&n,&m) != EOF)
	{
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			scanf("%d",mat[i]+j);
		}
		for(int col=m-1;col>=0;col--)
		{
			for(int row = 0;row <= n+1;++row)
			{
				if(col == m-1)
				{
					if(row == n || row == 0)
					dp[row][col] = mat[n-1][col];
					else
					dp[row][col] = INF;
				}
				else if(row == 0 && col != 0)
				{
					dp[row][col] = dp[n][col];
					path[row][col] = n;
				}
				else if(row == n+1 && col != 0)
				{
					dp[row][col] = dp[1][col];
					path[row][col] = 1;
				}
				else
				{
					int val1 = mat[row-1][col]+dp[row][col+1];
					int val2 = mat[row-1][col]+dp[row-1][col+1];
					if(val2 <= val1)
					{
						dp[row][col] = val2;
						path[row][col] = row-1;
					}
					else
					{
						dp[row][col] = val1;
						path[row][col] = row;
					}
					val2 = mat[row-1][col]+dp[row+1][col+1];
					if(val2 < dp[row][col])
					{
						dp[row][col] = val2;
						path[row][col] = row+1;
					}
				}
			}
		}
		int mx = INF,ind;
		for(int row=1;row<=n;++row)
		{
			if(mx > dp[row][0])
			{
				mx  = dp[row][0];
				ind = row;
			}
		}
		for(int i=0;i<n;++i)
		{
			for(int j=0;j<m;++j)
			cout<<dp[i+1][j]<<" ";
			cout<<endl;
		}
		/*for(int i=0;i<=m-1;++i)	
		{
			if(path[ind][i] >= 1 && path[ind][i] <= n)
			printf("%d ",path[ind][i]);
			ind = path[ind][i];
		}*/
		printf("%d\n",mx);
	}
	return 0;
}
