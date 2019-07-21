#include <bits/stdc++.h>

//knapsack
using namespace std;

int m,sum;
int *coin;/*
int change(int k,int wt)	
{
	if(k == m)
	return abs(sum - 2*wt);
	return min(change(k+1,wt+coin[k]),change(k+1,wt));
}
*/
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		sum=0;
		scanf("%d",&m);
		coin = new int[m];
		for(int i=0;i<m;++i)
		{
			scanf("%d",coin+i);
			sum += coin[i];
		}
		int **dp = new int*[sum+1];
		for(int i=0;i<=sum;++i)
		dp[i] = new int[m+1];
		for(int i=sum;i>=0;--i)
		{
			for(int j=m;j>=0;--j)
			{
				if(j == m)
				dp[i][j] = abs(sum-2*i);
				else if(i + coin[j] <= sum)
				dp[i][j] = min(dp[i+coin[j]][j+1],dp[i][j+1]);
				else
				dp[i][j] = dp[i][j+1];	
			}
		}
		printf("%d\n",dp[0][0]);
		
		//printf("%d\n",change(0,0));
	}
	return 0;
}
