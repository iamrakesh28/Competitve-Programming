#include <bits/stdc++.h>

//knapsack
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int m,sum=0;
		scanf("%d",&m);
		int *coin = new int[m];
		for(int i=0;i<m;++i)
		{
			scanf("%d",coin+i);
			sum += coin[i];
		}
		int **dp = new int*[sum/2 + 1];
		for(int i=0;i<=sum/2;++i)
		dp[i] = new int[m+1];
		for(int i=0;i<=sum/2;++i)
		{
			for(int j=0;j<=m;++j)
			{
				if(i == 0 || j == 0)
				dp[i][j] = 0;
				else if(i >= coin[j-1])
				dp[i][j] = max(dp[i-coin[j-1]][j-1] + coin[j-1],dp[i][j-1]);
				else
				dp[i][j] = dp[i][j-1];	
			}
		}
		printf("%d\n",sum-2*dp[sum/2][m]);
		/*int K[m+1][sum/2+1]; 
  		for (int i = 0; i <= m; i++) 
   		{ 
       			for (int w = 0; w <= sum/2; w++) 
       			{ 
           			if (i==0 || w==0) 
               			K[i][w] = 0; 
           			else if (coin[i-1] <= w) 
                 		K[i][w] = max(coin[i-1] + K[i-1][w-coin[i-1]],  K[i-1][w]); 
           			else
                 		K[i][w] = K[i-1][w]; 
       			} 
   		} 
		printf("%d\n",sum-2*K[m][sum/2]);*/
	}
	return 0;
}
