#include <bits/stdc++.h>

using namespace std;

int score(vector <int> &rank,vector <int> &st, int n)
{
	vector < vector <int> > table(n+1,vector<int>(n+1,0));
	for(int i=0;i<=n;++i)
	{
		for(int j=0;j<=n;++j)
		{
			if(i == 0 || j == 0)
			continue;
			if(st[i-1] == rank[j-1])
			table[i][j] = table[i-1][j-1] + 1;
			else
			table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}
	return table[n][n];
}
int main()
{
	int n,x,order;
	char ch;
	vector <int> rank;
	while(scanf("%d",&x) != EOF)
	{
		ch = getchar_unlocked();
		if(ch == '\n')
		{
			n = x;
			rank.resize(n);
			for(int i=0;i<n;++i)
			{		
				scanf("%d",&order);
				rank[order-1] = i;
			}
		}
		else
		{
			vector <int> st(n);
			st[0] = x-1;
			for(int i=1;i<n;++i)
			{		
				scanf("%d",&order);
				st[order-1] = i;
			}
			printf("%d\n",score(rank,st,n));
		}
	}
	return 0;
}
