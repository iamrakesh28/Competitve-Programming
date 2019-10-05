#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t,r,h;
	while(scanf("%d%d%d",&t,&r,&h) != EOF)
	{
		vector < vector <int>> T(t);
		vector < vector <int>> R(r);
		vector < vector <int>> H(h);
		int val,tt,rr,hh;
		for(int i=0;i<t;++i)
			for(int j=0;j<r+1;++j)
			{
				scanf("%d",&val);
				T[i].push_back(val);
			}
		for(int i=0;i<r;++i)
			for(int j=0;j<h+1;++j)
			{
				scanf("%d",&val);
				R[i].push_back(val);
			}
		for(int i=0;i<h;++i)
			for(int j=0;j<t+1;++j)
			{
				scanf("%d",&val);
				H[i].push_back(val);
			}
		int mincost = INT_MAX,cost;
		for(int i=0;i<t;++i)
		{
			for(int j=1;j<r+1;++j)
			{
				if(!T[i][j])
				for(int k=1;k<h+1;++k)
				{
					if(!R[j-1][k] && !H[k-1][i+1])
					{
						cost = T[i][0] + R[j-1][0] + H[k-1][0];
						if(mincost > cost)
						{
							mincost = cost;
							tt = i,rr=j-1,hh=k-1;
						}
					}
				}
			}
		}
		if(mincost != INT_MAX)
		printf("%d %d %d:%d\n",tt,rr,hh,mincost);
		else
		cout<<"Don't get married!\n";
	}
	return 0;
}
