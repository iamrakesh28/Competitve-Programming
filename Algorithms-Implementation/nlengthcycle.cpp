#include <bits/stdc++.h>

#define pb(x) push_back(x)

using namespace std;

class Graph{
	public:
	list <int> *adj;
	int *color;
	int *dist;
	void addEdge(int,int);
	Graph(int);
	int DFS(int,int,int,int);
};

Graph::Graph(int v)
{
	adj = new list <int> [v];
	color = new int[v];
	dist = new int[v];
	memset(color,0,sizeof(int)*v);
	memset(dist,0,sizeof(int)*v);
}

void Graph::addEdge(int u,int v)
{
	adj[u].pb(v);
	adj[v].pb(u);
}

int Graph:: DFS(int node,int par,int dist_,int n)
{
	int count = 0;
	color[node] = 1;
	dist[node] = dist_;
	list <int> :: iterator it;
	//cout<<node<<"\t";
	for(it = adj[node].begin();it!=adj[node].end();++it)
	{
		if(color[*it] ==  0)
		{
			count += DFS(*it,node,dist_+1,n);
		}
		else if(color[*it] == 1 && *it != par)
		{
			//if(abs(dist[node] - dist[*it]) == n-1)
			count++;
		}
	}
	color[node] = 2;
	return count;
}

int main()
{
	//int v;
	//scanf("%d",&v);
	Graph cycle(5);
	cycle.addEdge(0,1);
	cycle.addEdge(0,3);
	cycle.addEdge(1,4);
	cycle.addEdge(1,2);
	cycle.addEdge(2,3);
	cycle.addEdge(3,4);
	cout<<cycle.DFS(0,0,1,4)<<endl;
	return 0;
}
