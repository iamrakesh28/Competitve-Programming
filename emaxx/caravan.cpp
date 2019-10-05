#include <bits/stdc++.h>

#define mk(x,y) make_pair(x,y)
using namespace std;

list <int> *adj;
void addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void BFS(int s,int *dist,int n,int *pred)
{
	queue <int> q;
	bool visit[n];
	memset(visit,false,sizeof visit);
	q.push(s);
	dist[s] = 0;
	pred[s] = s;
	visit[s] = true;
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		for(auto it=adj[p].begin();it!=adj[p].end();++it)
		{
			if(visit[*it] == false)
			{
				dist[*it] = dist[p]+1;
				q.push(*it);
				visit[*it] = true;
				pred[*it] = p;
			}	
		}
	}
}
int main()
{
	int n,m,s,f,r;
	scanf("%d%d",&n,&m);
	adj = new list <int> [n];
	int *distr = new int[n];
	int *dist = new int[n];
	int *pred = new int[n];
	while(m--)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		addEdge(u-1,v-1);
	}
	scanf("%d%d%d",&s,&f,&r);
	BFS(r-1,distr,n,pred);
	vector <pair<int,int>> v;
	for(int i=0;i<n;++i)
	{
		for(auto it=adj[i].begin();it!=adj[i].end();++it)
		v.push_back(mk(distr[*it],*it));
		sort(v.begin(),v.end());
		adj[i].clear();
		for(auto it=v.rbegin();it!=v.rend();++it)
		adj[i].push_back((*it).second);
		v.clear();
	}
	BFS(s-1,dist,n,pred);
	int minm = distr[s-1];
	//cout<<pred[5]<<endl;
	for(int i=f-1;i != pred[i];i=pred[i])
	{
		minm = min(minm,distr[i]);
		//cout<<i+1<<endl;
	}
	printf("%d\n",minm);
	return 0;
}

