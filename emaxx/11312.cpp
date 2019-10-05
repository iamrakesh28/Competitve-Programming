#include <bits/stdc++.h>

using namespace std;


bool visit[10000000];
int cost[10000000];
int BFS(int t,int n,int l,int r)
{
	memset(visit,false,sizeof(bool)*n);
	queue <int> q;
	q.push(0);
	visit[0] = true;
	cost[0] = 0;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		if(p == t)
		return cost[p];
		if(p >= l && visit[p-l] == false)
		{
			q.push(p-l);
			visit[p-l] = true;
			cost[p-l] = cost[p] + 1;
		}
		if(p + r < n && visit[p+r] == false)
		{
			q.push(p+r);
			visit[p+r] = true;	
			cost[p+r] = cost[p] + 1;
		}
	}
	return -1;
}
int main()
{
	int c;
	scanf("%d",&c);
	while(c--)
	{
		int n,l,r,t;
		scanf("%d%d%d%d",&n,&l,&r,&t);
		int res = BFS(t-1,n,l,r);
		if(res == -1)
		{
			printf("uh-oh!\n");
			continue;	
		}
		printf("%d\n",res);
	}
	return 0;
}
