/*
	Shortest Path(Acyclic Graph): Dynamic Programming Approach
	Time Complexity : O(V+E)
*/
#include <bits/stdc++.h>

#define pb(x) push_back(x)
#define INF 100000

using namespace std;

int min(int a,int b)
{
	return a<b?a:b;
}

class Graph{
	public:
	int V;
	list <int> *adjNode;
	list <int> *adjWeight;
	void addEdge(int,int,int);
	Graph(int);
	void ShortestPath(int,bool*,int,int*);
};
Graph::Graph(int v)
{
	this->V =v;
	adjNode = new list <int> [V];
	adjWeight = new list <int> [V];
}
void Graph::addEdge(int u,int v,int w)
{
	adjNode[u].pb(v);
	adjNode[v].pb(u);
	adjWeight[u].pb(w);
	adjWeight[v].pb(w);
}
void Graph::ShortestPath(int node,bool *visited,int source,int *weight)
{
	visited[node] = true;
	if(node == source)
	{
		weight[node] = 0;
		return ;
	}
	list <int> :: iterator it,itw = adjWeight[node].begin();
	for(it = adjNode[node].begin();it != adjNode[node].end();++it,itw++)
	{	
		if(visited[*it] == false)
		{
			ShortestPath(*it,visited,source,weight);
		}
		weight[node] = min(weight[*it] + *itw,weight[node]);
	}
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	int *weight = new int[n];
	for(int i=0;i<n;++i)
	weight[i] = INF;
	Graph Path(n); 
	bool *visited = new bool[n];
	memset(visited,false,sizeof(bool)*n);
	for(int i=0;i<m;++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		Path.addEdge(u-1,v-1,w);
	}
	int source,target;
	scanf("%d%d",&source,&target);
	Path.ShortestPath(target-1,visited,source-1,weight);
	printf("%d\n",weight[target-1]);
	return 0;
}
