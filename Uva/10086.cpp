#include <bits/stdc++.h>

using namespace std;

#define INF 100000000

int T1,T2,n,size;
int nc[31][21],bc[31][21],mi[31];
int dp[31][301][301];
int path[31][301][301];
int minCost(int i,int t1,int t2)
{
	if(t1 > T1 || t2 > T2)
	return INF;
	if(i == n)
	{
		if(t1 == T1 && t2 == T2)
		return 0;
		return INF;
	}
	if(dp[i][t1][t2] == -1)
	{
		dp[i][t1][t2] = INF;
		for(int cap=0;cap<=mi[i];++cap)
		{
			int val = minCost(i+1,t1+cap,t2+mi[i]-cap)+nc[i][cap]+bc[i][mi[i]-cap];
			if(val < dp[i][t1][t2])
			{
				dp[i][t1][t2] = val;
				path[i][t1][t2] = cap;
			}
		}
	}
	return dp[i][t1][t2];
}

int main()
{
	while(scanf("%d%d",&T1,&T2) != EOF && T1 + T2)
	{
		scanf("%d",&n);
		for(int i=0;i<n;++i)
		{
			int m;
			scanf("%d",&m);
			size = max(size,m);
			nc[i][0] = bc[i][0] = 0;
			mi[i] = m;
			for(int j=0;j<m;++j)
			scanf("%d",nc[i]+j+1);
			for(int j=0;j<m;++j)
			scanf("%d",bc[i]+j+1);
		} 
		/*for(int i=0;i<=n;++i)
		{
			for(int k=0;k<=max(T1,T2);++k)
			dp[i][k] = -1;
		}*/
		memset(dp,-1,sizeof dp );
		printf("%d\n",minCost(0,0,0));
		int i=0,t1=0,t2=0;
		while(t1 != T1 || t2 != T2)
		{
			int temp = t1;
			if(i)
			printf(" %d",path[i][t1][t2]);
			else
			printf("%d",path[i][t1][t2]);
			t1 = t1 + path[i][t1][t2];
			t2 = t2 + mi[i] - path[i][temp][t2];
			++i;
		}
		printf("\n\n");
	}
	return 0;
}
