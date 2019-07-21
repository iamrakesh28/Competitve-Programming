#include <bits/stdc++.h>

#define pb(x) push_back(x)
#define INF 0x3f3f3f3f

using namespace std;

typedef pair <int,int> ipair;


class Graph{
	public:
	int V;
	list <ipair> *adj;	
	Graph(int);
	void addEdge(int,int,int);
	void Dijkstra(int);
};
Graph :: Graph(int V)
{
	this->V = V;
	adj = new list<ipair> [V];
}

void Graph:: addEdge(int u,int v,int w)
{
	adj[u].pb(make_pair(v,w));
	adj[v].pb(make_pair(u,w));
}

void Graph::Dijkstra(int src)
{
	set <ipair> setds;
	vector <int> dist(V,INF);
	setds.insert(make_pair(0,src));
	dist[src] = 0;
	while(!setds.empty())
	{
		ipair temp = *(setds.begin());
		setds.erase(setds.begin());
		int node = temp.second;
		list <ipair> :: iterator it;
		for(it=adj[node].begin();it!=adj[node].end();++it)
		{
			int v = (*it).first;
			int w = (*it).second;
			if(dist[v] > dist[node] + w)
			{
				if(dist[v] != INF)
				{
					setds.erase(setds.find(make_pair(dist[v],v)));
				}
				dist[v] = dist[node] + w;
				setds.insert(make_pair(dist[v],v));
			}
		}
	}
	for(int i=0;i<V;++i)
	{
		if(i == src)
		continue;
		if(dist[i] == INF)
		printf("-1 ");
		else
		printf("%d ",dist[i]);
	}
}
int main()
{
	int q;
	scanf("%d",&q);
	while(q--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		Graph Path(n);
		for(int i=0;i<m;++i)
		{
			int u,v,w;
			scanf("%d%d%d",&u,&v,&w);
			Path.addEdge(u-1,v-1,w);
		}
		int src;
		scanf("%d",&src);
		Path.Dijkstra(src-1);
		printf("\n");
	}	
	return 0;
}
