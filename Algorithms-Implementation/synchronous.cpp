#include <bits/stdc++.h>

#define pb(x) push_back(x)

typedef pair <int,int> ipair;

using namespace std;

class Graph{
	public:
	int n;
	list <ipair> *adj;
	list <int> *fish;
	void addEdge(int,int);
	void addFish(int,int);
	Graph(int);
	int DFS(int,int,bool*);
};

Graph::Graph(int v)
{
	this->n = v;
	adj = new list <ipair> [v];
	fish = new list <int> [v];
}

void Graph::addEdge(int u,int v,int w)
{
	adj[u].pb(make_pair(v,w));
	adj[v].pb(make_pair(u,w));
}
void Graph::addFish(int t,int f)
{
	fish[t].pb(f);
}
int Graph:: DFS(int node,bool *visited,bool *fishtype,int *cost)
{
	int cost;
	if(node == n-1)
	return 1;
	visited[node] = true;
	list <ipair> :: iterator it;
	for(it = adj[node].begin();it!=adj[node].end();++it)
	{
		if(visited[(*it).first] == false)
		{
			list <int> :: iterator t;
			for(t = fish[node].begin();t!=fish[node];++t)
			fishtype[*t] = true;
			(*cost) += (*it).second;
			if(DFS((*it).first,visited,fishtype,cost)
			{
			}
		}
	}
	visited[node] = false;
	return 0;
}
void Graph::DFSUtil(int n)
{
	bool *visitedPrim = new bool[n];
	bool *visitedSec = new bool[n];
	for
}

int main()
{
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	Graph cycle(n);
	for(int i=0;i<n;++i)
	{
		int t,f;
		scanf("%d",&t);
		for(int i=0;i<t;++i)
		{
			scanf("%d",&f);
			cycle.addFish(i,f);
		}
	}
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		cycle.addEdge(u-1,v-1,w);
	}
	return 0;
}
