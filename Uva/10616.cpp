#include <bits/stdc++.h>

using namespace std;

unsigned long int dp[205][15][25];
int d,m,n,q,*arr;
unsigned long int ways(int k,int i,int mod)
{
	if(i == m)
	{
		if(mod == 0)
		return 1;
		return 0;
	}
	if(k == n)
	return 0;
	long int num;
	if(dp[k+1][i][mod] == -1)
	dp[k+1][i][mod] = ways(k+1,i,mod);
	if(dp[k+1][i+1][((mod + arr[k])%d + d)%d] == -1)
	dp[k+1][i+1][((mod + arr[k])%d + d)%d] = ways(k+1,i+1,((mod + arr[k])%d + d)%d);
	num = dp[k+1][i][mod] + dp[k+1][i+1][((mod + arr[k])%d + d)%d];
	return num;
}
void initial()
{
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=m;++j)
		{
			for(int k=0;k<=d;++k)
			dp[i][j][k] = -1;
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
			initial();
			printf("QUERY %d: %lu\n",i+1,ways(0,0,0));
		}
		set++;
	}
	return 0;
}
