#include <bits/stdc++.h>

using namespace std;

long int dp[30005];

void change()
{
	dp[0] = 1;
	for(int i=1;i<30005;++i)
	dp[i] = 0;
	for(int i=1;i<30005;++i)
	{
		if(i >= 1)
		dp[i] += dp[i-1];
		if(i >= 5)
		dp[i] += dp[i-5];
		if(i >= 10)
		dp[i] += dp[i-10];
		if(i >= 25)
		dp[i] += dp[i-25];
		if(i >= 50)
		dp[i] += dp[i-50];
	}
}

int main()
{
	int n;
	change();
	while(scanf("%d",&n) != EOF)
	{
		if(dp[n] != 1)
		printf("There are %ld ways to produce %d cents change.\n",dp[n],n);
		else
		printf("There is only 1 way to produce %d cents change.\n",n);
	}
	return 0;
}
