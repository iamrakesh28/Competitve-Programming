#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)
#define INF 10000000

typedef pair <int,int> ipair;

class Graph{
	public:
	int V;
	list <ipair> *adj;
	void addEdge(int,int,int);
	Graph(int);
	void Dijkstra(int,int);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list<ipair>[v];
}
void Graph::addEdge(int u,int v, int w)
{
	adj[u].pb(make_pair(v,w));
	adj[v].pb(make_pair(u,w));
}

void Graph::Dijkstra(int src,int dest)
{
	bool **visited = new bool* [V];
	for(int i=0;i<V;++i)
	{
		visited[i] = new bool[1024];
		memset(visited[i],false,sizeof(bool)*1024);
	}
	queue<int> q,k;
	visited[src][0] = true;
	q.push(src);
	k.push(0);
	while(!q.empty())
	{
		int p = q.front();
		q.pop();
		int bit = k.front();
		k.pop();
		for(auto it = adj[p].begin();it!=adj[p].end();++it)
		{
			int v = (*it).first;
			int w = (*it).second;
			if(visited[v][w|bit] == false)	
			{
				visited[v][w|bit] = true;
				q.push(v);
				k.push(w|bit);
			}
			
		}
	}
	for(int i=0;i<1024;++i)
	{
		if(visited[dest][i])
		{
			cout<<i<<endl;
			return ;
		}
	}
	cout<<"-1"<<endl;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Graph graph(n);
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		graph.addEdge(u-1,v-1,w);
	}
	int src,dest;
	scanf("%d%d",&src,&dest);
	graph.Dijkstra(src-1,dest-1);
	return 0;
}
