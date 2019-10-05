#include <bits/stdc++.h>

using namespace std;

#define pb(x) push_back(x)

class Graph{
	public:
	int V,count;
	list <int> *adj;
	void addEdge(int,int);
	Graph(int);
	int DFS(int,int);
};

Graph::Graph(int v)
{
	this->V = v;
	adj = new list <int> [V];
	this->count = 0;
}
void Graph::addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}
int Graph::DFS(int node,int par)
{
	int sub,sum = 1;
	list <int> :: iterator it;
	for(it = adj[node].begin();it!=adj[node].end();++it)
	{
		if(*it != par)
		{
			sub = DFS(*it,node);
			if(sub % 2)
			sum += sub;
			else
			count++;
		}
	}
	return sum;
}

int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	Graph tree(n);
	for(int i=0;i<m;++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		tree.addEdge(u-1,v-1);
	}
	int sum = tree.DFS(0,-1);
	printf("%d\n",tree.count);
	return 0;
}
