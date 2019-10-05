#include <bits/stdc++.h>

using namespace std;

class Graph{
	public:
	list <int> *adj;
	void addEdge(int,int);
	Graph(int);
	void DFS(int,bool**,char*,int);
};

Graph::Graph(int v)
{
	adj = new list<int>[v];
}
void Graph::addEdge(int u,int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}
void Graph::DFS(int node,bool **visited,char *seq,int edge)
{
	if(edge == 8)
	{
		seq[edge] = node + 1 + '0';
		printf("%s\n",seq);
	}
	for(auto it = adj[node].begin();it!=adj[node].end();++it)
	{
		if(visited[node][*it] == false)
		{
			visited[node][*it] = true;
			visited[*it][node] = true;
			seq[edge] = node+1 + '0';
			DFS(*it,visited,seq,edge+1);
			visited[node][*it] = false;
			visited[*it][node] = false;
		}
	}
	
}
int main()
{
	Graph house(5);
	bool **visited = new bool*[5];	
	for(int i=0;i<5;++i)
	{
		visited[i] = new bool[5];
		memset(visited[i],false,sizeof(bool)*5);
	}
	house.addEdge(0,1);
	house.addEdge(0,2);
	house.addEdge(0,4);
	house.addEdge(1,2);
	house.addEdge(1,4);
	house.addEdge(2,3);
	house.addEdge(2,4);
	house.addEdge(3,4);
	char *seq = new char[10];
	house.DFS(0,visited,seq,0);
	return 0;
}
