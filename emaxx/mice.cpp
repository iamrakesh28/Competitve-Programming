#include <bits/stdc++.h>

#define mk(x,y) make_pair(x,y)
#define INF 100000000
using namespace std;

list <pair<int,int>> *adj;
bool *visit;
void addEdge(int u,int v,int w)
{
	adj[u].push_back(mk(v,w));
}

int ans(int n,int s,int k)
{
	set <pair<int,int>> p;
	p.insert(mk(0,s));
	vector <int> dist(n,INF);
	dist[s] = 0;
	while(!p.empty())
	{
		pair <int,int> q = *p.begin();
		p.erase(*p.begin());
		int u = q.second;
		//cout<<q.first<<endl;
		for(auto it=adj[u].begin();it!=adj[u].end();++it)
		{
			if(dist[(*it).first] == INF)
			{
				dist[(*it).first] = dist[u] + (*it).second;
				p.insert(mk(dist[(*it).first],(*it).first));
			}
			else if(dist[(*it).first] > dist[u] + (*it).second)
			{
				auto i = p.find(mk(dist[(*it).first],(*it).first));
				p.erase(*i);
				dist[(*it).first] = dist[u] + (*it).second;
				p.insert(mk(dist[(*it).first],(*it).first));
			}
		}
	}
	int cnt=0;
	for(int i=0;i<n;++i)
	{
		if(dist[i] <= k)
		cnt++;
		//cout<<dist[i]<<endl;
	}
	return cnt;
}
int main()
{
	int n,e,t,m;
	scanf("%d%d%d%d",&n,&e,&t,&m);
	visit = new bool[n];
	adj = new list<pair<int,int>> [n];
	memset(visit,false,sizeof visit);
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		addEdge(v-1,u-1,w);
	}
	printf("%d\n",ans(n,e-1,t));
	return 0;
}
