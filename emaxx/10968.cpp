#include <bits/stdc++.h>

using namespace std;

list <int> *adj;
int *indegre;
void addEdge(int u,int v)
{
	indegre[u]++;
	indegre[v]++;
	adj[u].push_back(v);
	adj[v].push_back(u);
}
int BFS(int s,int n)
{
	bool visit[n];
	int cost[n];
	memset(visit,false,sizeof(bool)*n);
	//memset(cost,0,sizeof(int)*n);
	cost[s] = 0;
	queue <int> q;
	q.push(s);
	visit[s] = true;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		if(s != p && indegre[p]%2)
		return cost[p];
		for(auto it=adj[p].begin();it!=adj[p].end();++it)
		{
			if(visit[*it] == false && indegre[*it]>2)
			{
					visit[*it] = true;
					q.push(*it);
					cost[*it] = cost[p] + 1;
			}
		}
	}
	return -1;
}
int main()
{
	int n,m;
	while(scanf("%d%d",&n,&m) != EOF && (n || m))
	{
		if(m==0)
		{
			printf("Poor Koorosh\n");
			continue;
		}
		adj = new list<int> [n];
		indegre = new int[n];
		memset(indegre,0,sizeof(int)*n);
		while(m--)
		{
			int u,v;
			scanf("%d%d",&u,&v);
			//cout<<u<<" "<<v<<endl;
			addEdge(u-1,v-1);
		}
		int s,cnt=0;
		bool f = true;
		for(int i=0;i<n;++i)
		{
			if(indegre[i] < 2)
			f = false;
			if(indegre[i]%2)
			{
				s = i;
				cnt++;
			}
		}
		if(f == false)
		{
			printf("Poor Koorosh\n");
			delete [] adj,indegre;
			continue;
		}
		if(cnt==0)
		{
			printf("0\n");
			delete [] adj,indegre;
			continue;
		}
		if(cnt!=2)
		{
			printf("Poor Koorosh\n");
			delete [] adj,indegre;
			continue;
		}
		int res = BFS(s,n);
		if(res == -1)
		printf("Poor Koorosh\n");
		else
		printf("%d\n",res);
		delete [] adj,indegre;
	}
	return 0;
}
