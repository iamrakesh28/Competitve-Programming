#include <bits/stdc++.h>

using namespace std;

char S[2050];
int k,n;
long int dp[2050][33][27];

long int steps(int i,int j,int p)
{
	if(j > k)
	return INT_MAX;
	if(i == n && j <= k)
	return 0;
	if(dp[i][j][p] == -1)
	{
		int diff = S[i]-'a';
		dp[i][j][p] = INT_MAX;
		for(int al=0;al<26;++al)
		{	
			if(p != (diff+al)%26)
			dp[i][j][p] = min(dp[i][j][p],steps(i+1,j+1,(diff+al)%26)+al);
			else
			dp[i][j][p] = min(dp[i][j][p],steps(i+1,j,(diff+al)%26)+al);
		}
	}
	return dp[i][j][p];
}

int main()
{
	scanf("%s%d",S,&k);
	n = strlen(S);
	memset(dp,-1,sizeof dp);
	int diff = S[0]-'a';
	long int ans = INT_MAX;
	for(int al=0;al<26;++al)
	ans = min(ans,steps(1,0,(diff+al)%26)+al);
	printf("%ld\n",ans);
	return 0;
}
