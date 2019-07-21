#include <bits/stdc++.h>

#define mk(x,y) make_pair(x,y)
#define INF 10000000

using namespace std;
typedef pair <int,int> ipair;

list <ipair> adj[10000];
int cost[10000][2];

void addEdge(int u,int v)
{
	adj[u].push_back(mk(0,v));
	adj[v].push_back(mk(1,u));
}

int gears(int s,int t)
{
	set <pair<int,ipair>> q;	
	cost[s][0] = cost[s][1] = 0;
	for(auto it = adj[s].begin();it != adj[s].end();++it)
	{
		int u = (*it).second;
		cost[u][(*it).first] = 0;
		q.insert(mk(0,mk((*it).first,u)));
	}
	while(!q.empty())
	{
		pair<int,ipair> p = *q.begin();
		int u = p.second.second;
		int w = p.first;
		int s = p.second.first;
		q.erase(q.begin());
		for(auto it = adj[u].begin();it != adj[u].end();++it)
		{
			int c = cost[u][s],x = (*it).second,y = (*it).first;
			if(s == 0 && y == 1)
			c += 1;
			else if(s == 1 && y == 0)
			c += 1;
			if(cost[x][y] == INF)
			{
				q.insert(mk(c,mk((*it).first,x)));
				cost[x][y] = c;
			}
			else if(cost[x][y] > c)
			{
				q.erase(q.find(mk(cost[x][y],mk(y,x))));
				q.insert(mk(c,mk(y,x)));
				cost[x][y] = c;
			}
		}
	}
	return min(cost[t][0],cost[t][1]);
}

int main()
{
	int n,m,s,t;
	scanf("%d%d",&n,&m);
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u-1,v-1);
	}
	scanf("%d%d",&s,&t);
	for(int i=0;i<n;++i)
		for(int j=0;j<2;++j)
			cost[i][j] = INF;
	printf("%d\n",gears(s-1,t-1));
	return 0;
}
