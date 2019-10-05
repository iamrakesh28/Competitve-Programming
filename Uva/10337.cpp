#include <bits/stdc++.h>

using namespace std;

#define INF 10000000
int sky[10][1005],dp[1005][15],x;
/*
int fuel(int d,int alt)
{
	if(alt > 9 || alt < 0 || d > x)
	return INF;
	if(d == x)	
	{
		if(alt == 0)
		return 0;
		return INF;
	}
	if(dp[d][alt] != -1)
	return dp[d][alt];
	dp[d][alt] = min(fuel(d+1,alt+1)+60-sky[alt][d],fuel(d+1,alt)+30-sky[alt][d]);
	dp[d][alt] = min(dp[d][alt],fuel(d+1,alt-1)+20-sky[alt][d]);
	return dp[d][alt];
}*/
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		scanf("%d",&x);
		x = x/100;
		for(int i=9;i>=0;--i)
		{
			for(int j=0;j<x;++j)
			scanf("%d",sky[i]+j);
		}
		/*
		for(int d=x;d>=0;--d)
		{
			for(int alt=0;alt<=10;++alt)
			{
				if(d == x && alt == 0)
				dp[d][alt] = 0;
				else if(alt == 0)
				dp[d][alt] = INF;
				else if(alt == 10)
				dp[d][alt] = INF;
				else if(d == x)
				dp[d][alt] = INF;
				else
				{
					dp[d][alt] = min(dp[d+1][alt+1]-sky[alt][d]+60,dp[d+1][alt]-sky[alt][d]+30);
					dp[d][alt] = min(dp[d][alt],dp[d+1][alt-1]-sky[alt][d]+20);
				}
			}
		}*/
		for(int d=0;d<=x;++d)
		{
			for(int alt=0;alt<=10;++alt)
			dp[d][alt] = -1;
		}
		printf("%d\n\n",fuel(0,0));
	}
	return 0;
}
