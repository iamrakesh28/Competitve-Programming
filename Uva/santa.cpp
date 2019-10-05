#include <bits/stdc++.h>

#define pb(x) push_back(x)

using namespace std;

class Graph{
	public:
	list <int> *adj;
	void addEdge(int,int);
	Graph(int);
	void DFS(int,bool*,int,char *);
};

Graph::Graph(int v)
{
	adj = new list <int> [v];	
}
void Graph::addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

void Graph::DFS(int node,bool **visited,int edge,char *seq)
{
	visited[node] = true;
	for(auto it = adj[node].begin();it!=adj[node].end();++it)
	{
		if(visited[*it] == false)
		{
			DFS(*it,visited,edge+1,seq);
		}
		else if(edge == 7)
		{
			seq[edge] = node + '0';
			printf("%s\n",seq);
		}
	}
	visited[node] = false;
}

int main()
{
	bool **visited = new bool*[5];
	for(int i=0;i<5;++i)
	{
		visited[i] = new bool[5];
		memset(visited[i],false,sizeof(bool)*5);
	} 
	memset(visited,false,sizeof(bool)*5);
	Graph house(5);
	house.addEdge(0,1);
	house.addEdge(0,2);
	house.addEdge(0,4);
	house.addEdge(1,2);
	house.addEdge(1,4);
	house.addEdge(2,3);
	house.addEdge(2,4);
	house.addEdge(3,4);
	char *seq = new char[8];
	house.DFS(0,visited,0,seq);
	return 0;
}
