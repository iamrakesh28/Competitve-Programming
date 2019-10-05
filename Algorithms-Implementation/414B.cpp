#include <bits/stdc++.h>

using namespace std;

#define PRIME 1000000007

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	long int dp[n][k];
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<k;++j)
		dp[i][j] = 0;
		dp[i][0] = 1;
	}
	for(int i=n;i>=1;i--)
	{
		for(int m=1;m < k;m++)
		{
			for(int j = i;j <= n;j+=i)
			{
				//if(dp[j-1][m-1]==0)
				//break;
				dp[i-1][m] = (dp[i-1][m] + dp[j-1][m-1]) % PRIME;
			}
		}
	}
	long int sum = 0;
	for(int i=0;i<n;++i)
	{
		sum  = (sum + dp[i][k-1]) % PRIME;
	}
	cout<<sum<<endl;
	return 0;
}
