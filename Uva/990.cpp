#include <bits/stdc++.h>

using namespace std;

int dp[1001][31];
int path[1001][31];
int cnt[1001][31];
bool ch[1001][31];
int main()
{
	int t,w;
	while(scanf("%d%d",&t,&w) != EOF)
	{
		int n;
		scanf("%d",&n);
		vector <pair <int,int>> treas(n);
		for(int i=0;i<n;++i)
		{
			int d,v;
			scanf("%d%d",&d,&v);
			treas[i].first = d;
			treas[i].second = v;
		}
		for(int i=0;i<=t;++i)
		{
			for(int j=0;j<=n;++j)
			{
				ch[i][j] = false;
				if(i == 0 || j == 0)
				{
					dp[i][j] = 0;
					path[i][j] = 0;
					cnt[i][j] = 0;
				}
				else if(i >= 3*w*treas[j-1].first)
				{
					if(dp[i-3*w*treas[j-1].first][j-1] + treas[j-1].second >= dp[i][j-1])
					{
						dp[i][j] = dp[i-3*w*treas[j-1].first][j-1] + treas[j-1].second;
						path[i][j] = i-3*w*treas[j-1].first;
						cnt[i][j] = cnt[i-3*w*treas[j-1].first][j-1] + 1;
						ch[i][j] = true;
					}
					else
					{
						dp[i][j] = dp[i][j-1];
						path[i][j] = i;
						cnt[i][j] = cnt[i][j-1];
					} 
				}
				else
				{
					dp[i][j] = dp[i][j-1];
					cnt[i][j] = cnt[i][j-1];
					path[i][j] = i;
				}
			}
		}
		vector <int> id;
		for(int i=t,j=n;j>=0;i = path[i][j],j--)
		{
			if(ch[i][j] == true)
			id.push_back(j-1);
		}
		printf("%d\n%d\n",dp[t][n],cnt[t][n]);
		reverse(id.begin(),id.end());
		for(int i=0;i<cnt[t][n];++i)
		printf("%d %d\n",treas[id[i]].first,treas[id[i]].second);
		printf("\n");
	}
	return 0;
}
